#include "student.h"

const char *familias[] = {"Грехова","Тимонин","Куприенко","Науменко","Бушев","Ксенофонтов","Еремеева","Гуменюк","Окунев","Качар"};
const char *names[] = {"Мария","Семен","Иван","Святослав","Михаил","Константин","Диана","Алина","Данил","Кирилл"};

void fill_array(struct student arr[]) {
    srand (time(NULL));
    for (int i = 0; i < N; i++) {    
        strcpy(arr[i].familia, familias[rand() % 10]);
        strcpy(arr[i].name, names[rand() % 10]);
        arr[i].groupa = 531 + rand() % 2;
        arr[i].fizika = rand() % 101;
    }
}

void print_array(struct student arr[]) {
    printf("\n%-20s | %-15s | %-8s | %-8s\n", "Фамилия", "Имя", "Группа", "Балл");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("| %-12s | %-40s | %-8d | %-8.2f\n", 
                arr[i].familia,
                arr[i].name, 
                arr[i].groupa, 
                arr[i].fizika);
    }
    printf("\n");
}

void bubble_sort(struct student arr[]) {
    for(int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if(arr[j].groupa > arr[j+1].groupa) {
                struct student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
