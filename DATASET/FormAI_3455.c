//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function prototypes
void task1();
void task2();
void task3();

// Task buffer
void (*task_buffer[3])() = {&task1, &task2, &task3};

int main() {
    printf("Welcome to the Surrealist Task Scheduler!\n");
    printf("Let's schedule some tasks that may or may not exist...\n\n");

    // Let's arbitrarily assign the tasks
    task_buffer[0] = &task3;
    task_buffer[1] = &task2;
    task_buffer[2] = &task1;

    int i;
    for (i = 0; i < 3; i++) {
        printf("Task %d: firing up...\n", i+1);
        sleep(1);
        (*task_buffer[i])();
    }

    printf("\nAll tasks complete! Exiting...\n");
    return 0;
}

void task1() {
    printf("Task 1: Drinking a cup of coffee while juggling chainsaws...\n");
    sleep(3);
    printf("Task 1: Chainsaws starting...I think...?\n");
    sleep(2);
    printf("Task 1: I've lost my hands to the chainsaws! Ahh, it's beautiful...\n");
    exit(1);
}

void task2() {
    printf("Task 2: Drawing a portrait of a platypus, but only using spaghetti...\n");
    sleep(2);
    printf("Task 2: The platypus is coming to life! Oh god, it's beautiful...\n");
    sleep(2);
    printf("Task 2: Wait, the platypus is attacking me with an army of spaghetti worms...\n");
    exit(2);
}

void task3() {
    printf("Task 3: Dancing on the ceiling with an octopus in glorious 8K resolution...\n");
    sleep(3);
    printf("Task 3: The octopus is trying to steal my soul! Oh no, it's beautiful...\n");
    sleep(2);
    printf("Task 3: Wait, the octopus just wanted to give me a hug... Nevermind...\n");
    exit(3);
}