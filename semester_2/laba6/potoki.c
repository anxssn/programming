#include <stdio.h>
#include <pthread.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIZE 50


//структура для хранения данных о потоке
struct thread_inf {
    int thread_id;
    int message_count;
};

typedef struct thread_inf info;

//обработчик завершения потока
//функция вызывается, когда поток отменяют или он завершается
void thread_cleanup(void *arg) {
    info* data = (info*)arg;
    printf("Поток %d: завершение работы\n", data->thread_id);
}

//функция дочернего потока
void* thread_func(void* arg) {
    pthread_cleanup_push(thread_cleanup, arg);

    info data = *(info*)arg;
    int thread_id = data.thread_id;
    int message_count = data.message_count;

    //цикл для вывода 5 соо
    for (int i = 1; i <= message_count; i++) {
        printf("Поток %d: Сообщение %d из %d\n", thread_id, i, message_count);
        sleep(1);
    }

    printf("Поток %d завершен\n", data.thread_id);
    pthread_cleanup_pop(0); //если поток норм, удаляем обработчик очистки

    return NULL;
}

//функция для слипсорт
// Каждый поток засыпает на value миллисекунд, потом выводит число
void* sleep_sort(void* arg) {
    int value = *(int*)arg; // Получаем число из аргумента
    usleep(value * 1000); /// Сон на value миллисекунд
    printf("%d ", value); // Выводим число
    fflush(stdout); // Принудительно выводим на экран
    return NULL;
}

//запуск
void sleep_run() {
    int arr[MAX_SIZE];
    int n;
    pthread_t threads[MAX_SIZE]; // Массив для потоков
    struct timespec start, end; // Для замера времени
    double elapsed;

    printf("Введите количество элементов (не более %d): ", MAX_SIZE);
    scanf("%d", &n);
    if(n <= 0 || n > MAX_SIZE) {
        printf("Неккоректный размер массива\n");
        return;
    }

    printf("Введите %d неотрицательных чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            printf("Отрицательные числа не поддерживаются\n");
            return;
        }
    }

    printf("Отсортированный массив: ");
    clock_gettime(CLOCK_MONOTONIC, &start); //запоминаем время начала
    
    // Создаем поток для КАЖДОГО элемента массива
    for (int i = 0; i < n; i++) {
        if (pthread_create(&threads[i], NULL, sleep_sort, &arr[i]) != 0) {
            perror("Ошибка при создании потока");
            return;
        }
    }

    // Ждем завершения всех потоков
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end); //запоминаем время конца
    elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed += (end.tv_nsec - start.tv_nsec) / 1000000.0;
    
    printf("\nВремя сортировки: %.3f мс\n", elapsed);
}


int main() {
    struct timespec start_time, end_time; // Для замера времени
    double elapsed_time; // Время выполнения в мс;

    // Часть 1: Взаимодействие потоков
    pthread_t thread[4]; // Массив для 4 потоков
    info thread_info_data[4]; // Данные для каждого потока

    // Инициализируем данные для 4 потоков (ID от 1 до 4, по 5 сообщений)
    for (int i = 0; i < 4; i++) {
        thread_info_data[i].thread_id = i + 1;
        thread_info_data[i].message_count = 5;
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time); // Засекаем время для этой части

    // Создаем 4 дочерних потока
    for (int i = 0; i < 4; i++) {
        if (pthread_create(&thread[i], NULL, thread_func, &thread_info_data[i]) != 0) {
            perror("Ошибка при создании потока");
            return 1;
        }
    }

    //родительский поток
    for (int i = 1; i <= 5; i++) {

        printf("Родительский поток: строка %d\n", i);
            sleep(1);
        
    }

    //отмена потоков через 2 сек
    sleep(2);
    printf("\nОТМЕНА ВСЕХ ДОЧЕРНИХ ПОТОКОВ\n");
    for (int i = 0; i < 4; i++) {
        pthread_cancel(thread[i]); //сигнал отмены
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(thread[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    elapsed_time += (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;
    printf("Время связи с потоком: %.3f мс\n", elapsed_time);


    //Часть 3: SleepSort
    sleep_run();

    return 0;
}
