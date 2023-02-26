/**
* Напишіть програму, яка за допомогою командного рядка отримує параметр —
кількість потоків-нащадків, що будуть створені. В основній програмі (для цього можна
створити окрему функцію) створюється задана при старті програми кількість потоків -
нащадків та очікується завершення їхньої роботи. Кожен потік виконання виводить у
стандартний потік виведення випадкову кількість рядків, що містять випадкові числа.
Випадкові числа генеруються із заданого діапазону. Кожен рядок, що виводиться в кожному
потоку виконання, включає ідентифікатор потоку, текстове повідомлення та згенероване
псевдовипадкове число. Незмінна частина рядка зберігається в області потокових даних
кожного потоку. Можна використати функцію sleep, щоб зробити роботу програми більш
наочною.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>


void* attribute_thread_function(void* arg);
void* thread_function(void* arg);
void check_if_error(int result, char *err);
void write_to_thread_log(const int number, const int counter);

static pthread_key_t thread_key;

int main (int argc, char *argv[] ) {
    int amount_of_threads;

    srand(time(NULL));

    if (argc < 2) {
        perror("You had to specify amount of threads! We set it to 5 by default.");
        amount_of_threads = 5;
    } else {
        amount_of_threads = atoi(argv[1]);
    }

    pthread_key_create(&thread_key, NULL);

    // створюємо потоки
    pthread_t * threads = calloc(amount_of_threads, sizeof(pthread_t));
    if (threads == NULL) {
        perror("Memory allocation error 2");
        exit(1);
    }
    for (int i = 0; i < amount_of_threads; i++) {
        check_if_error(pthread_create(&threads[i], NULL, thread_function, (void *) &i), "creating thread");
        check_if_error(pthread_join(threads[i], NULL), "during waiting for ending thread");
    }

    printf("\n\n");

}

void check_if_error(int result, char *err) {
    if (result != 0) {
        perror("Error occurred during");
        perror(err);
        exit(EXIT_FAILURE);
    }
}

void* thread_function(void* arg)
{
    // з void* в int
    int n = *(int* ) arg;

    char * str = "Static. Random number is [not static]";
    pthread_setspecific(thread_key, str);

    int random_number = rand() % (n + 100);

    write_to_thread_log(random_number, n + 1);

    sleep(1);

    return NULL;
}

void write_to_thread_log(const int number, const int counter)
{
    char * str = (char*) pthread_getspecific(thread_key);
    fprintf(stderr, "%d -- %s: %d\n", counter, str, number);
}