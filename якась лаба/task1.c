/**
 * <b>Завдання №1 (Створення потоку) </b>
 * Напишіть програму, що створює новий потік виконання.
 * При створенні використовуйте для атрибутів потоку значення за замовчуванням.
 * Початковий та новостворений потоки виконання повинні вивести в стандартний потік виведення десять рядків тексту (Оригінальний
потік виводить такі рядки «Main Thread. Iteration: 1», новостворений потік: «Child Thread.
Iteration: 1»). Після виведення рядка кожен потік «засинає» на задану в коді програми
кількість секунд (наприклад, від 0 до 2). Дослідити, як цей параметр впливає на виконання програми.
 * @return
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

long WAIT_FOR_SECONDS = 2;

void * any_func(void * args) {
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "Child Thread. Iteration: %d\n", (i+1));
        sleep(WAIT_FOR_SECONDS);
    }
//    sleep(WAIT_FOR_SECONDS);
    return NULL;
}
int main(void) {
    pthread_t thread;
    int result;
    result = pthread_create(&thread, NULL, &any_func, NULL);
    if (result != 0) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "Parent Thread. Iteration: %d\n", (i+1));
        sleep(WAIT_FOR_SECONDS);
    }
//    fprintf(stderr, "Goodbye World\n");
//    while(1);
    return 0;
}