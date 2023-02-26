/**
* <b>Завдання No1 ( Атрибути потоку )</b><br>
Напишіть програму, яка за допомогою командного рядка отримує параметр —
кількість потоків, що створюються. З основної функції викликається інша функція, куди
передається робочий масив, у якій створюється задану кількість розрахункових потоків –
нащадків і очікується завершення їх роботи. (В спрощеному варіанті програми можна все це
зробити в функції main.)<br>
Кожен розрахунковий потік отримує як аргумент номер цього потоку виконання
(відлік починається з 0), засинає на цю кількість секунд і після пробудження генерує
псевдовипадкове число в діапазоні [1, 10] . Потім, отримане псевдовипадкове число
заноситься до глобального масиву цілих чисел у комірку, що відповідає номеру потоку, а
потік засипає на це згенероване число — кількість секунд. Паралельно з розрахунковими
потоками запускається від'єднаний потік, який постійно з періодом 1 секунда виводить на
екран повідомлення, що відображає всі ті значення, що на той час зберігаються в масиві.
Коли масив стане повністю заповненим, від'єднаний потік самостійно завершує свою роботу.
Передбачити інформаційні повідомлення, що пояснюють роботу програми
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int* array;

/**
 * Паралельно з розрахунковими
потоками запускається від'єднаний потік, який постійно з періодом 1 секунда виводить на
екран повідомлення, що відображає всі ті значення, що на той час зберігаються в масиві.
Коли масив стане повністю заповненим, від'єднаний потік самостійно завершує свою роботу.
 */
void* attribute_thread_function(void* arg);
void* thread_function(void* arg);
void check_if_error(int result, char *err);

int main (int argc, char *argv[] ) {
    int amount_of_threads;

    srand(time(NULL));

    if (argc < 2) {
        perror("You had to specify amount of threads! We set it to 5 by default.");
        amount_of_threads = 5;
    } else {
        amount_of_threads = atoi(argv[1]);
    }

//    розмір масиву = кількість потоків
    array = (int* ) calloc(amount_of_threads, sizeof(int));
    if (array == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    pthread_t attr_thread;
    pthread_attr_t attribute;


    pthread_attr_init(&attribute);
    (pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_DETACHED), "setting up detach state in attribute");
    pthread_create(&attr_thread, &attribute, &attribute_thread_function, &amount_of_threads);



    pthread_t * threads = calloc(amount_of_threads, sizeof(pthread_t));
    if (threads == NULL) {
        perror("Memory allocation error 2");
        exit(1);
    }
    // створюємо потоки
    for (int i = 0; i < amount_of_threads; i++)
        check_if_error(pthread_create(&threads[i], NULL, thread_function, (void* ) &i), "creating thread");

    // очікуємо завершення потоків
    for (int i = 0; i < amount_of_threads; i++)
        check_if_error(pthread_join(threads[i], NULL), "during waiting for ending thread");



    pthread_attr_destroy(&attribute);

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

    sleep(n);

    array[n-1] = rand() % 10 + 1;
    printf("\nWe've generated %d[%d]!", array[n-1], (n-1));

    sleep(array[n]);
}

void* attribute_thread_function(void* arg) {
    // з void* в int
    int n = *(int* ) arg;
    printf("\nN: %d\n", n);

    for (int i = 0; i < n; i++) {
        sleep(1.1);
        printf("\nYour random-generated array:\t\t");
        for (int j = 0; j < n; j++)
            printf("%d ", array[j]);
    }

    return NULL;
}