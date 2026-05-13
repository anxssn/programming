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
    char *names[] = {"Гостинная", "Кухня", "Прихожая", "Спальня", "Ванная", "Прачечная"};
    sprintf(r.name, "%s_%d", names[idx % 6], idx);
    r.level = rand() % 10 + 1;
    r.number = rand() % 100 + 1;
    r.resolution = rand() % 3 + 1;
    return r;
}

void addLow (struct room r) {
    node_t *new_node = newNode(r);
    if (head_low == NULL) {
        head_low = new_node;
    } else {
        node_t *cur = head_low;
        while (cur->next != NULL) cur = cur->next;
        cur->next = new_node;
        new_node->prev = cur;
    }

}

void addUp (struct room r) {
    node_t *new_node = newNode(r);
    if (head_upp == NULL) {
        head_upp = new_node;
    } else {
        new_node->next = head_upp;
        head_upp->prev = new_node;
        head_upp = new_node;
    }
}

void linkVertical() {
    node_t *u = head_upp, *l = head_low;
    while (u && l) {
        u->vertical = l;
        u = u->next;
        l = l->next;
    }
}

void printAll() {
    printf("\nСтруктура\n");

    printf("Верхний:");
    node_t *cur = head_upp;
    if (!cur) printf("пусто");
    else {
        while (cur-> next) cur = cur->next;
        while(cur) {
            printf("%d", cur->data.level);
            if (cur->vertical) printf("<-");
            cur = cur->prev;
        }
    }
    printf("\n");

    
    // Нижний список (прямой)
    printf("Нижний: ");
    cur = head_low;
    if (!cur) printf("пусто");
    else {
        while (cur) {
            printf("%d", cur->data.level);
            if (cur->next) printf(" -> ");
            cur = cur->next;
        }
    }
    printf("\n\n");

}

void showCur(node_t *cur, char *lvl) {
    if (!cur) { printf("NULL\n"); return; }
    printf("Текущий [%s]: %s\n", lvl, cur->data.name);
}


// Навигация
void navigate() {
    node_t *cur = S;
    char *lvl = "UP";
    char cmd;
    
    printf("Управление: W/2-вверх, S/8-вниз, A/4-влево, D/6-вправо, Q-выход\n");
    showCur(cur, lvl);
    
    while (1) {
        printf("Команда: ");
        scanf(" %c", &cmd);
        cmd = toupper(cmd);
        
        if (cmd == 'D' || cmd == '6') {  // вправо
            if (cur->next) {
                cur = cur->next;
                showCur(cur, lvl);
            } else printf("Конец списка!\n");
        }
        else if (cmd == 'A' || cmd == '4') {  // влево
            if (cur->prev) {
                cur = cur->prev;
                showCur(cur, lvl);
            } else printf("Начало списка!\n");
        }
        else if (cmd == 'W' || cmd == '2') {  // вверх (низ->верх)
            if (lvl[0] == 'D') {
                node_t *u = head_upp, *l = head_low;
                while (l && l != cur) {
                    if (u) u = u->next;
                    l = l->next;
                }
                if (u) { cur = u; lvl = "UP"; printf("Перешли наверх\n"); showCur(cur, lvl); }
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
    while (cur) { tmp = cur->next; free(cur); cur = tmp; }
    cur = head_upp;
    while (cur) { tmp = cur->next; free(cur); cur = tmp; }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Практическая работа №3\n");
    printf("Введите N:");
    scanf("%d", &n);
    if (n <= 0) { printf ("Ошибка!\n"); return 1; }

    for (int i = 1; i <= n; i++)
        addLow(genRoom(i));

    for (int i = 1; i <= n; i++)
        addUp(genRoom(n + i));

    S = head_upp;
    while (S && S->next) S = S->next;

    linkVertical();
    printAll();
    navigate();

    return 0;
}
