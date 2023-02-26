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



void* thread_function(void* arg);
void check_if_error(int result, char *err);

int main (int argc, char *argv[] ) {
    int seconds;
    if (argc < 2) {
        seconds = 5;
        fprintf(stdin, "You had to specify amount of seconds! We set it to %d by default.\n", seconds);
    } else {
        seconds = atoi(argv[1]);
    }
    pthread_t thread;
    pthread_create(&thread, NULL, &thread_function, &seconds);

    sleep(seconds);
    pthread_cancel(thread);

    void* result;
    if (!pthread_equal(pthread_self(), thread))
        pthread_join(thread, &result) ;
    if (result == PTHREAD_CANCELED) {
        fprintf(stderr, "Canceled\n");
        return EXIT_FAILURE;
    } else {
        //обробка результату, що було отримано
        //з потокової функції у разі нормального
        //завершення роботи потокової функції`
        fprintf(stderr, "Default\n");
    }

    while (1);
//    return EXIT_SUCCESS;
}

void check_if_error(int result, char *err) {
    if (result != 0) {
        fprintf(stderr, "Error occurred during %s", err);
        exit(EXIT_FAILURE);
    }
}

void* thread_function(void* arg)
{
    int n = *(int* ) arg;
    pthread_setcanceltype(PTHREAD_CANCEL_DISABLE, NULL);
    int counter = 0;
    while (1) {
        system("clear");
        counter++;
        fprintf(stderr, "Hehe: %d\n", counter);
        sleep(1);
    }
}