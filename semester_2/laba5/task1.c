#include <stdio.h>
#include <stdlib.h>

// Скомпилируй и запусти меня

void init(int **arr, int* n) {  
    *n = 5; 
    int N = *n; //было: void init(int *arr, int n) { 
    *arr = malloc(N * sizeof(int)); //было:  arr = malloc(n * sizeof(int));
    for (long i = 0; i < N; ++i) {  
        (*arr)[i] = i;     //было: arr[i] = i;   
    }
}

int main() {
    int *arr = NULL;
    int n = 10;

    init(&arr, &n); //было:  init(arr, n);  
    printf("%d\n", n); 
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}