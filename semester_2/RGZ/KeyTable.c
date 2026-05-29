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
        fprintf(stderr, "Использование: %s <входной_файл> <выходной_файл>\n", argv[0]);
        return 1;
    }

    // Ввод размеров таблицы с проверкой
    int rows, cols;
    printf("Введите количество строк:");
    if (scanf("%d", &rows) != 1) {
        printError("Неверный ввод строк (должно быть целое число)");
        return 1;
    }
    
    printf("Введите количество столбцов:  ");
    if (scanf("%d", &cols) != 1) {
        printError("Неверный ввод столбцов (должно быть целое число)");
        return 1;
    }
    
    // Проверка положительности размеров
    if (rows <= 0 || cols <= 0) {
        printError("Количество строк и столбцов должно быть положительным");
        return 1;
    }

    // Открытие входного файла с проверкой
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printError("Не удалось открыть входной файл");
        printf("   Файл:%s\n", argv[1]);
        return 1;
    }

    // Определение размера файла
    if (fseek(input, 0, SEEK_END) != 0) { // fseek - перемещаем указатель в конец файла
        printError("Не удалось прочитать файл ");
        fclose(input);
        return 1;
    }
    
    long size = ftell(input); // ftell - возвращает текущую позицию (размер файла)
    if (size == -1) {
        printError("Не удалось определить размер файла");
        fclose(input);
        return 1;
    }
    
    // Возвращаем указатель в начало файла
    if (fseek(input, 0, SEEK_SET) != 0) {
        printError("Не удалось вернуться в начало файла");
        fclose(input);
        return 1;
    }

    // Проверка, что текст помещается в таблицу
    int totalCells = rows * cols;
    if (size > totalCells) {
        printError("Текст слишком длинный для указанного размера таблицы");
        printf("  Длина текста: %ld, Вместимость таблицы:  %d\n", size, totalCells);
        printf("   Увеличьте количество строк/столбцов\n");
        fclose(input);
        return 1;
    }

    // Чтение входного текста
    char *text = (char*)malloc(size + 1);
    if (text == NULL) {
        printError("Не удалось выделить память");
        fclose(input);
        return 1;
    }
    
    size_t bytesRead = fread(text, 1, size, input);
    if (bytesRead != size) {
        printError("Не удалось прочитать файл целиком");
        free(text);
        fclose(input);
        return 1;
    }
    text[size] = '\0';
    fclose(input);

    // Шифрование
    char *encrypted = (char*)malloc(totalCells + 1);
    if (encrypted == NULL) {
        printError("Не удалось выделить память для зашифрованного текста");
        free(text);
        return 1;
    }
    
    encrypt(text, encrypted, rows, cols);

    // Открытие выходного файла с проверкой
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printError("Не удалось создать выходной файл");
        printError("  Проверьте права на запись в директорию\n");
        free(text);
        free(encrypted);
        return 1;
    }

    // Запись результата
    if (fputs(encrypted, output) == EOF) {
        printError("Не удалось записать в выходной файл");
        fclose(output);
        free(text);
        free(encrypted);
        return 1;
    }
    
    fclose(output);

    // Успешное завершение
    printf("УСПЕХ: Шифрование завершено\n");
    printf("   Входной файл: %s (%ld байт)\n", argv[1], size);
    printf("   Выходной файл: %s\n", argv[2]);
    printf("   Размер таблицы: %dx%d\n", rows, cols);

    free(text);
    free(encrypted);
    return 0;
}