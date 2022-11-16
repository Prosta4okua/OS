/**
* <b>Завдання #2 ( Передача параметрів потоку )</b>
Напишіть програму, що створює чотири потоки виконання, які виконують одну й ту ж
потокову функцію.
 Ця функція повинна прийняти в якості параметрів:
 <ul>
 <li>ім'я потоку name</li>
 <li>базову частину рядка для виведення str</li
 <li>кількість повторень рядку num</li
 </ul>
Вивести в стандартний потік виведення послідовність текстових рядків, сформованих за правилом:<br>
 <br>
 <code>Thread name. Str i</code>
 <br>
 де i — ціле число, що визначає кількість зроблених повторень рядка. Кожен потік повинен
отримати свій набір параметрів.
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long WAIT_FOR_SECONDS = 3;

// There is a structure, where I'll save all data, that I need to pass to thread and manipulate with it there.
typedef struct toThread {
    char* name;
    char* baseStr;
    int num;
}ThreadData;

void * func_for_threads(void *args) {
    ThreadData my_structure = * (ThreadData* ) args;

    for (int i = 0; i < my_structure.num; ++i) {
        printf("Thread %s. Str %d/%d. Message: %s\n", my_structure.name, (i+1), my_structure.num, my_structure.baseStr);
    }
}

// the name speak for itself
void check_if_error(int result) {
    if (result != 0) {
        fprintf(stderr, "Error during thread creation\n");
        exit(1);
    }
}

int main(void) {

    // structures initialize
    ThreadData potik1, potik2, potik3, potik4;

    potik1.name = "MyThread 1";
    potik1.baseStr = "Hello!";
    potik1.num = 5;

    potik2.name = "MyThread 2";
    potik2.baseStr = "Hehe?";
    potik2.num = 3;

    potik3.name = "MyThread 3";
    potik3.baseStr = "Not hehe!";
    potik3.num = 4;

    potik4.name = "MyThread 4";
    potik4.baseStr = "Hehe!";
    potik4.num = 6;

    // creating threads
    pthread_t thread1, thread2, thread3, thread4;
    check_if_error(pthread_create(&thread1, NULL, &func_for_threads, &potik1));
    check_if_error(pthread_create(&thread2, NULL, &func_for_threads, &potik2));
    check_if_error(pthread_create(&thread3, NULL, &func_for_threads, &potik3));
    check_if_error(pthread_create(&thread4, NULL, &func_for_threads, &potik4));

    // cuz threads should work
    // another implementation is via pthread_join, but I'll use it later
    sleep(WAIT_FOR_SECONDS);

    return 0;
}