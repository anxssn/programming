#include "mylib.h"
#include <string.h>

//функция шифрования: вписывается по строкам, выписывается по столбцам
void encrypt(const char* in, char* out, int rows, int cols) {
    int idx = 0;
    char tmp[rows][cols]; //создаем таблицу

    //заполняем таблицу по строкам
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char c = '_';             //пустая ячейка
            if (idx < strlen(in)) {
                c = in[idx];
                if (c == ' ') c = '_';
            }
            tmp[i][j] = c;
            idx++;
        }
    }
    //выписываем из таблицы по столбцам
    idx = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            out[idx++] = tmp[i][j];
        }
    }
    out[idx] = '\0';
}

//функция расшифровки: вписывается по столбцам, выписывается по строкам
void decrypt(const char* in, char* out, int rows, int cols) {
    int idx = 0;
    char tmp[rows][cols];
    
    //заполняем таблицу по столбцам
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            char c = in[idx++];
            tmp[i][j] = (c == '_') ? ' ' : c;
        }
    }
    
    //выписываем по строкам
    idx = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out[idx++] = tmp[i][j];
        }
    }
    out[idx] = '\0';
}

//функция проверки
int verify(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}