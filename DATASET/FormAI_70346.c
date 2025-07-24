//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task1() {
    printf("The dancing monkeys have arrived!\n");
}

void task2() {
    printf("The purple clouds are forming a pyramid!\n");
}

void task3() {
    printf("The trees are singing the national anthem!\n");
}

void task4() {
    printf("The cheese is melting into a rainbow!\n");
}

void task5() {
    printf("The clock has turned into a snail!\n");
}

int main() {
    srand(time(0));
    int tasks[] = {1, 2, 3, 4, 5};
    int task_count = sizeof(tasks) / sizeof(tasks[0]);

    printf("Welcome to the surreal C Task Scheduler!\n");

    while (1) {
        int random_task = tasks[rand() % task_count];

        switch (random_task) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
        }

        sleep(1);
    }
    return 0;
}