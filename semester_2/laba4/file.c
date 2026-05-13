#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int id;
    char level[50];
} Employee;

#define MAX_EMPLOYEES 100

int saveToBinaryFile(Employee *employees, int count, const char *filename) { //Функция сохранения 
    FILE *file = fopen(filename, "wb"); //открываем файл для записи в бинарном режиме
    if (file == NULL) {
        perror ("Ошибка создания binary file");
        return -1;
    }

    fwrite(&count, sizeof(int), 1, file); // кол-во сотрудников
    fwrite(employees, sizeof(Employee), count, file); // сам массив структур
    fclose(file);
    printf("Данные сохранены в %s\n", filename);
    return 0;

}

int searchEmployee(const char *filename) { //Функция поиска 
    FILE *file = fopen(filename, "rb"); //открываем фал только для чтения в бинарном виде
    if (file == NULL) {
        perror("Ошибка при открытии binary file");
        return -1;
    }

    int count;
    if (fread(&count, sizeof(int), 1, file) != 1) {
        printf("Ошибка чтения файла\n"); //считываем то самое число, которое записали первым
        fclose(file);
        return -1;
    }

    int searchId;
    printf("\nВведите ID сотрудника для поиска: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Ошибка ввода ID\n");
        fclose(file);
        return -1;
    }

    Employee emp;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (fread(&emp, sizeof(Employee), 1, file) != 1) { 
            printf("Ошибка чтения данных\n");
            fclose(file);
            return -1;
        }
        
        if (emp.id == searchId) {
            printf("\nСотрудник найден:\n");
            printf("| %-20s | %-10d | %-15s |\n", emp.name, emp.id, emp.level);
            found = 1;
            break;
        }
    }
     
    if (!found) {
        printf("Сотрудник с ID %d не найден\n", searchId);
    }
    
    fclose(file);
    return 0;
}


int main (int argc, char* argv[]) {
    if (argc < 2) {
        printf("ОЩИБКА");
        return 1;
    }

    FILE *file = fopen (argv[1],"r");
    if (file == NULL) {
        perror("Error opening file");
        return(1);

    }

    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    char line [256];
    
    while (fgets(line,sizeof(line),file) && count < MAX_EMPLOYEES) { //читаем файл построчно в переменную line, пока есть строки и пока count < 100
        line [strcspn(line, "\n")] = 0; //удаляем символ \n
        if (strlen(line) == 0) continue;//если пустая строка - пропускаем

        //режем строки
        char *name = strtok(line, ";");
        char *idStr = strtok(NULL,";");
        char *level = strtok(NULL, ";");

        if (name == NULL || idStr == NULL || level == NULL) { //если не хватило одной части - пропускаем
            printf("Ошибка парсинга строки: %s\n", line);
            continue;
        }
       
        strncpy(employees[count].name, name, sizeof(employees[count].name) - 1); //копируем из строки name в employees[0].name
        employees[count].name[sizeof(employees[count].name) - 1] = '\0'; //добавляем \0 в конец name
        
        employees[count].id = atoi(idStr); //текст ID в число и в структуру
        
        strncpy(employees[count].level, level, sizeof(employees[count].level) - 1); //В employees[0].level копируется "Level_A" + \0 в конце
        employees[count].level[sizeof(employees[count].level) - 1] = '\0'; //Ставим \0 в последний байт массива level
        
        count++;
    }
    
    fclose(file);

    printf("| %-20s | %-10s | %-15s |\n", "name", "id", "level");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf ("| %-20s | %-10d | %-15s |\n", employees[i].name, employees[i].id, employees[i].level);
    }

    printf("------------------------------------------------------\n");
    printf("Всего сотрудников: %d\n\n", count);

    if (saveToBinaryFile(employees, count, "database.dat") != 0) {
        printf("Ошибка сохранения в бинарный файл\n");
        return 1;
    }

    if (searchEmployee("database.dat") != 0) {
        printf("Ошибка при поиске\n");
        return 1;
        
    }

    return 0;

}  