//1. Создание потока
pthread_t thread[4]; //Идентификаторы потоков
info thread_data[4]; //Данные потоков

for (int i = 0; i < 4; i++) {
    thread_data[i].thread_id = i+1;
    thread_data[i].message_count = 5;
}

for (int i=0; i < 4; i++) {
    int result = pthread_create(&thread[i], NULL, thread_func, &thread_data[i]);
    if (result != 0) {
        perror("Ошибка при создании потока");
        return 1;
    }
}



