/** <b>Завдання 2</b>
 *      Напишіть програму, яка за допомогою командного рядка отримує параметр – час
    затримки в секундах. У основній програмі створюється потік – нащадок і очікується
    завершення роботи. При створенні потік-нащадок встановлюється в режим потоку, що
    скасовується асинхронно. Потік виконання виводить рядок з текстом (який включає номер
    ітерації) нескінченну кількість разів і «засинає» на одну секунду після кожного виведення.
    Після створення потоку основний потік засипає на задану кількість секунд (час затримки) і
    після пробудження намагається скасувати потік, що працює. Потім аналізується статус
    завершення потоку і виводиться повідомлення про те, як завершився потік - в результаті
    скасування або звичайним чином.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int counter;


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
    pthread_create(&thread, NULL, &thread_function, NULL);
    sleep(seconds);
    pthread_cancel(thread);

    void* result;
    if (!pthread_equal(pthread_self(), thread))
        pthread_join(thread, &result) ;
    if (result == PTHREAD_CANCELED) {
        fprintf(stderr, "Canceled\n");
//        return EXIT_FAILURE;
    } else {
        //обробка результату, що було отримано
        //з потокової функції у разі нормального
        //завершення роботи потокової функції`
        fprintf(stderr, "Default\n");
    }
    return EXIT_SUCCESS;
}

void check_if_error(int result, char *err) {
    if (result != 0) {
        fprintf(stderr, "Error occurred during %s", err);
        exit(EXIT_FAILURE);
    }
}

void* thread_function(void* arg)
{
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while (1) {
        system("clear");
        printf("Counter: %d\n", counter);
        counter++;
        sleep(1);
    }
}