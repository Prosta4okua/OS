/** <b>Завдання No3 ( Потік, що не скасовується )</b>
<br>Напишіть програму, яка за допомогою командного рядка отримує параметр – час
затримки в секундах. У основній програмі створюється потік – нащадок і очікується
завершення його роботи. Потік-нащадок встановлюється в такий стан, що не дозволяє його
скасувати. Цей потік виконання має виводити на екран рядок з текстом (цей рядок включає
номер ітерації) задану кількість разів (це дорівнює подвоєному часу затримки) і «засинає» на
секунду після кожного виведення. Після створення потоку основний потік засипає на задану
кількість секунд (час затримки) і після пробудження намагається скасувати потік-нащадок,
що працює. Потім аналізується статус завершення потоку і виводиться повідомлення про те,
— 1 —

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

int iterations = 10000;
double PI_res = 0;

void *thread_function(void *arg);

void check_if_error(int result, char *err);

int main(int argc, char *argv[]) {
    int seconds;
    if (argc < 2) {
        seconds = 5; // час затримки
        fprintf(stdin, "You had to specify amount of seconds! We set it to %d by default.\n", seconds);
    } else {
        seconds = atoi(argv[1]);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, &thread_function, &seconds);

    sleep(seconds);
    pthread_cancel(thread);

    void *result;
    if (!pthread_equal(pthread_self(), thread))
        pthread_join(thread, &result);
    if (result == PTHREAD_CANCELED) {
        fprintf(stderr, "Canceled\n");
//        return EXIT_FAILURE;
    } else {
        //обробка результату, що було отримано
        //з потокової функції у разі нормального
        //завершення роботи потокової функції`
        fprintf(stderr, "Default\n");
    }

    fprintf(stderr, "Finish PI: %lf", PI_res * 4);
//    while (1);
//    return EXIT_SUCCESS;
}

void check_if_error(int result, char *err) {
    if (result != 0) {
        fprintf(stderr, "Error occurred during %s", err);
        exit(EXIT_FAILURE);
    }
}

void *thread_function(void *arg) {
    int old_cancel_state;
    int divider = 1;
    for (int i = 0; i < iterations; i++) {
        /* Початок області, де потік не буде скасовуваний */
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);
        /* Обов’язкові дії */
//        pow(-1, i) = -1 or 1
//          1. / divider = 1/1, 1/3, 1/5...
        PI_res += pow(-1, i) * (1. / divider);
        divider += 2;
        /* Кінець області, де потік не буде скасовуваний */
        pthread_setcancelstate(old_cancel_state, NULL);
        fprintf(stderr, "PI: %.10lf\n", PI_res * 4);
        system("clear");
    }
}