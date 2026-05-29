#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

void printError(const char* msg) {
    fprintf(stderr, "ОШИБКА: %s\n", msg);
}

int main(int argc, char *argv[]) {
    // Проверка количества аргументов
    if (argc != 3) {
        fprintf(stderr, "ОШИБКА: Неверное количество аргументов\n");
        fprintf(stderr, "Использование: %s <зашифрованный_файл> <оригинальный_файл>\n", argv[0]);
        return 1;
    }

    // Ввод размеров таблицы с проверкой
    int rows, cols;
    printf("Введите количество строк: ");
    if (scanf("%d", &rows) != 1) {
        printError("Неверный ввод строк (должно быть целое число)");
        return 1;
    }
    
    printf("Введите количество столбцов: ");
    if (scanf("%d", &cols) != 1) {
        printError("Неверный ввод столбцов (должно быть целое число)");
        return 1;
    }
    
    // Проверка положительности размеров
    if (rows <= 0 || cols <= 0) {
        printError("Количество строк и столбцов должно быть положительным");
        return 1;
    }

    int totalCells = rows * cols;

    // === Открытие зашифрованного файла ===
    FILE *encryptedFile = fopen(argv[1], "r");
    if (encryptedFile == NULL) {
        printError("Не удалось открыть зашифрованный файл");
        printf("   Файл: %s\n", argv[1]);
        return 1;
    }

    if (fseek(encryptedFile, 0, SEEK_END) != 0) {
        printError("Не удалось прочитать зашифрованный файл (ошибка позиционирования)");
        fclose(encryptedFile);
        return 1;
    }
    
    long encSize = ftell(encryptedFile);
    if (encSize == -1) {
        printError("Не удалось определить размер зашифрованного файла");
        fclose(encryptedFile);
        return 1;
    }
    
    if (fseek(encryptedFile, 0, SEEK_SET) != 0) {
        printError("Не удалось вернуться в начало файла");
        fclose(encryptedFile);
        return 1;
    }

    // Проверка соответствия размера зашифрованного файла
    if (encSize != totalCells) {
        printError("Размер зашифрованного файла не соответствует размеру таблицы");
        printf("   Размер зашифрованного файла: %ld, Ожидалось: %d\n", encSize, totalCells);
        printf("   Убедитесь, что вы используете те же строки/столбцы, что и при шифровании\n");
        fclose(encryptedFile);
        return 1;
    }

    // Чтение зашифрованного текста
    char *encrypted = (char*)malloc(encSize + 1);
    if (encrypted == NULL) {
        printError("Не удалось выделить память");
        fclose(encryptedFile);
        return 1;
    }
    
    size_t bytesRead = fread(encrypted, 1, encSize, encryptedFile);
    if (bytesRead != encSize) {
        printError("Не удалось прочитать зашифрованный файл целиком");
        free(encrypted);
        fclose(encryptedFile);
        return 1;
    }
    encrypted[encSize] = '\0';
    fclose(encryptedFile);

    // === Открытие оригинального файла ===
    FILE *originalFile = fopen(argv[2], "r");
    if (originalFile == NULL) {
        printError("Не удалось открыть оригинальный файл");
        printf("   Файл: %s\n", argv[2]);
        free(encrypted);
        return 1;
    }

    if (fseek(originalFile, 0, SEEK_END) != 0) {
        printError("Не удалось прочитать оригинальный файл (ошибка позиционирования)");
        fclose(originalFile);
        free(encrypted);
        return 1;
    }
    
    long origSize = ftell(originalFile);
    if (origSize == -1) {
        printError("Не удалось определить размер оригинального файла");
        fclose(originalFile);
        free(encrypted);
        return 1;
    }
    
    if (fseek(originalFile, 0, SEEK_SET) != 0) {
        printError("Не удалось вернуться в начало файла");
        fclose(originalFile);
        free(encrypted);
        return 1;
    }

    // Проверка, что оригинальный текст помещается в таблицу
    if (origSize > totalCells) {
        printError("Оригинальный текст длиннее вместимости таблицы");
        printf("   Длина оригинала: %ld, Вместимость таблицы: %d\n", origSize, totalCells);
        free(encrypted);
        fclose(originalFile);
        return 1;
    }

    // Чтение оригинального текста
    char *original = (char*)malloc(origSize + 1);
    if (original == NULL) {
        printError("Не удалось выделить память для оригинального текста");
        free(encrypted);
        fclose(originalFile);
        return 1;
    }
    
    bytesRead = fread(original, 1, origSize, originalFile);
    if (bytesRead != origSize) {
        printError("Не удалось прочитать оригинальный файл целиком");
        free(encrypted);
        free(original);
        fclose(originalFile);
        return 1;
    }
    original[origSize] = '\0';
    fclose(originalFile);

    // === Расшифровка ===
    char *decrypted = (char*)malloc(totalCells + 1);
    if (decrypted == NULL) {
        printError("Не удалось выделить память для расшифрованного текста");
        free(encrypted);
        free(original);
        return 1;
    }
    
    decrypt(encrypted, decrypted, rows, cols);

    // === Вывод результатов ===
    printf("\n--- РЕЗУЛЬТАТЫ ---\n");
    printf("Расшифрованный текст: '%s'\n", decrypted);
    printf("Оригинальный текст:   '%s'\n", original);
    printf("Длина расшифрованного: %zu\n", strlen(decrypted));  
    printf("Длина оригинального:   %zu\n", strlen(original));
    
    int match = verify(decrypted, original);
    printf("Совпадение: %s\n", match ? "ДА" : "НЕТ");
    
    if (!match) {
        printf("\nПРЕДУПРЕЖДЕНИЕ: Расшифрованный текст не совпадает с оригиналом!\n");
        printf("Возможные причины:\n");
        printf("  - Неправильные строки/столбцы\n");
        printf("  - Файл был изменён после шифрования\n");
    } else {
        printf("\nУСПЕХ: Расшифровка подтверждена\n");
    }

    // Очистка памяти
    free(encrypted);
    free(original);
    free(decrypted);
    
    return match ? 0 : 1;
}