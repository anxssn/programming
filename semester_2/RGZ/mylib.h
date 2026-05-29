#ifndef MYLIB_H
#define MYLIB_H

void encrypt(const char* in, char* out, int rows, int cols); //функция шифрования
void decrypt(const char* in, char* out, int rows, int cols); //функция расшифровки
int verify(const char* a, const char* b); //функция проверки

#endif