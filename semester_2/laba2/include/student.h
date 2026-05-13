#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
    char familia[50];
    char name[50];
    int groupa;
    float fizika;
};

#define N 10

extern const char *familias[];
extern const char *names[];

void fill_array(struct student arr[]);
void print_array(struct student arr[]);
void bubble_sort(struct student arr[]);

#endif