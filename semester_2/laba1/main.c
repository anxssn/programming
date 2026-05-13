#include "student.h"
int main() {
    struct student students[N];

    fill_array(students);
    printf("Массив до сортировки:\n");
    print_array(students);

    bubble_sort(students);

    printf("Массив после сортировки\n");
    print_array(students);
    return 0;
}   