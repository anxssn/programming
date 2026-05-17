#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

//Создаем структуру комнаты
struct room {
    char name [50];
    int level;
    int number;
    int resolution;
};

//Создаем структуру узла
struct node {
    struct room data;
    struct node *next; // Указатель на следующий узел
    struct node *prev; // Указатель на предыдущий узел
    struct node *vertical; //Указатель на узел другого уровня
};

typedef struct node node_t; 

node_t *S = NULL; //указатель на начало
node_t *head_upp = NULL; //голова верхнего списка
node_t *head_low = NULL; //голова нижнего списка

// Функция для создания нового узла
node_t *newNode(struct room r) {   
    node_t *new_node = (node_t *)malloc(sizeof(node_t)); //сохраняем адрес выделенной памяти в переменную node_t
    if (new_node == NULL) { //Если память закончилась, верни NULL
        perror("Не удалось выделить память для нового узла"); //coo + описание ошибки
        exit (EXIT_FAILURE); //завершение программы
    }
    new_node->data = r; // присваивает полю data нового узла значение, переданное в функцию (r)
    new_node->next = NULL; // Инициализация нового узла 
    new_node->prev = NULL; // Инициализация нового узла
    new_node->vertical = NULL; // Инициализация вертикального указателя
    return new_node;
}

//Генерация случайной комнаты
struct room genRoom(int idx) { 
    struct room r; 
    char *names[] = {"Гостинная", "Кухня", "Прихожая", "Спальня", "Ванная", "Прачечная"}; //массив указателей на строки
    sprintf(r.name, "%s_%d", names[idx % 6], idx);  //имя комнаты
    r.level = rand() % 10 + 1; //случайный уровень сложности
    r.number = rand() % 100 + 1; //случайный номер комнаты
    r.resolution = rand() % 3 + 1; //случайные размеры комнаты
    return r;
}

//функция добавления узла в конец нижнего списка
void addLow (struct room r) {
    node_t *new_node = newNode(r); //новый узел с данными r
    if (head_low == NULL) {
        head_low = new_node; //новый узел становится головой нижнего списка
    } else {
        node_t *cur = head_low;
        while (cur->next != NULL) cur = cur->next; //идем до последнего узла списка
        cur->next = new_node;
        new_node->prev = cur;
    }

}

//функция добавления узла в начало верхнего списка
void addUp (struct room r) {
    node_t *new_node = newNode(r);
    if (head_upp == NULL) {
        head_upp = new_node;
    } else {
        new_node->next = head_upp; //новый узел указывает на старый новый узел
        head_upp->prev = new_node; //старый первый помнит новый как предыдущий
        head_upp = new_node; //новый узел теерь первый
    }
}

//функция для вертикальных связей
void linkVertical() {
    node_t *u = head_upp, *l = head_low; //создаем два бегунка
    while (u && l) { //пока есть узлы в обоихсписках
        u->vertical = l; //устанавливаем вертикальную связь вниз
        u = u->next; //переходим к следующему узлу верхнего списка
        l = l->next; //переходим к следующему узлу нижнего списка
    }
}

//вывод двухуровневой структуры
void printAll() {
    printf("\nСтруктура\n");

    printf("Верхний:");
    node_t *cur = head_upp; //создаем бегунок для верхнего списка
    if (!cur) printf("пусто"); //если пуст верхний список - пусто
    else {
        while (cur-> next) cur = cur->next; //пока есть следующий узел - идем вперед
        while(cur) { //пока есть текущий узел
            printf("%d", cur->data.level); //выводим уровень комнаты
            if (cur->vertical) printf("|"); //если есть вертикальная связь - выводим соо
             if (cur->next) printf(" -> "); //если есть следующий узел - соо
            cur = cur->prev; //переходим к предыдущему узлу
        }
    }
    printf("\n");

    
    // Нижний список  
    printf("Нижний: ");
    cur = head_low; //проходим по нижнему списку
    if (!cur) printf("пусто");
    else {
        while (cur) {
            printf("%d", cur->data.level);
            if (cur->vertical) printf("^");
            if (cur->next) printf(" -> ");
            cur = cur->next;
        }
    }
    printf("\n\n");

}

//функция вывода информации о текущем узле
void showCur(node_t *cur, char *lvl) { 
    if (!cur) { printf("NULL\n"); return; } //Если cur == NULL, узла нет
    printf("Текущий [%s]: %s\n", lvl, cur->data.name); //1)%s-строка(lvl), 2) %s - строка (cur->data.name)
}


// Навигация
void navigate() { 
    node_t *cur = S; //начинаем с указателя S
    char *lvl = "UP"; //текущий уровень
    char cmd; //переменная для команды пользователя
    
    printf("Управление: W/2-вверх, S/8-вниз, A/4-влево, D/6-вправо, Q-выход\n");
    showCur(cur, lvl); //показываем начальную позицию
    
    while (1) {
        printf("Команда: ");
        scanf(" %c", &cmd); 
        cmd = toupper(cmd); //переводим символ в верхний регистр
        
        if (cmd == 'D' || cmd == '6') {  // если мы нажали D или 6 - вправо
            if (cur->next) { //если следующий узел существует
                cur = cur->next; //переходим к следующему узлу
                showCur(cur, lvl); //Показываем новый текущий узел
            } else printf("Конец списка!\n"); //если следующего узла нет - выводим соо
        }
        else if (cmd == 'A' || cmd == '4') {  
            if (cur->prev) { //если предыдущий узел существует 
                cur = cur->prev; //переходим к предыдущему узлу
                showCur(cur, lvl); 
            } else printf("Начало списка!\n"); 
        }
        else if (cmd == 'W' || cmd == '2') {  
            if (lvl[0] == 'D') { //если первый символ строки равен D, мы на нижнем уровне
                node_t *u = head_upp, *l = head_low; //создаем бегунки
                while (l && l != cur) { //идем по нижнему списку, пока не найдем cur
                    if (u) u = u->next; //переходим к следующему верхнему узлу 
                    l = l->next; //переходим к следующему нижнему узлу
                }
                if (u) { cur = u; lvl = "UP"; printf("Перешли наверх\n"); showCur(cur, lvl); } //если находим соответствующий узел - переходим
                else printf("Нет узла наверху!\n");
            } else printf("Уже наверху!\n");
        }
        else if (cmd == 'S' || cmd == '8') {  // вниз (верх->низ)
            if (lvl[0] == 'U') {
                if (cur->vertical) {
                    cur = cur->vertical; lvl = "DOWN";
                    printf("Перешли вниз\n"); showCur(cur, lvl);
                } else printf("Нет связи вниз!\n");
            } else printf("Уже внизу!\n");
        }
        else if (cmd == 'Q') {
            printf("Выход...\n");
            break;
        }
        else printf("Неизвестная команда!\n");
    }

    // Очистка памяти
    node_t *tmp;
    cur = head_low;
    while (cur) { tmp = cur->next; free(cur); cur = tmp; } //освобождаем память нижнего списка
    cur = head_upp; 
    while (cur) { tmp = cur->next; free(cur); cur = tmp; } //освобождаем память верхнего списка
}

int main() {
    srand(time(NULL)); //генератор случаных чисел
    int n;
    printf("Практическая работа №3\n");
    printf("Введите N:");
    scanf("%d", &n);
    if (n <= 0) { printf ("Ошибка!\n"); return 1; }

    for (int i = 1; i <= n; i++)
        addLow(genRoom(i)); //создаем нижний список из N элементов

    for (int i = 1; i <= n; i++)
        addUp(genRoom(n + i)); //создаем верхний список из N элементов

    S = head_upp;
    while (S && S->next) S = S->next; //идем к правому краю верхнего списка

    linkVertical();
    printAll();
    navigate();

    return 0;
}
