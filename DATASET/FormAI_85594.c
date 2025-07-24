//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to perform a surrealist task. */
void surreal_task() {
    printf("A fish walks into a bar and orders a drink. The bartender asks, \"What kind of drink would you like?\"\n");
    printf("The fish replies, \"Water,\" and the bartender serves it a glass of water.\n");
    printf("The fish takes a sip and exclaims, \"Wow, this water tastes like human tears!\"\n");
}

/* Struct to hold information about a task. */
typedef struct task {
    int id;
    time_t start_time;
    int frequency;
    void (*task_function)();
} task;

int main() {
    /* Seed the random number generator. */
    srand(time(0));

    /* Create some tasks. */
    task task1 = {1, time(0), rand() % 10 + 1, surreal_task};
    task task2 = {2, time(0), rand() % 10 + 1, surreal_task};
    task task3 = {3, time(0), rand() % 10 + 1, surreal_task};

    /* Set up the task list. */
    task* task_list[3];
    task_list[0] = &task1;
    task_list[1] = &task2;
    task_list[2] = &task3;

    /* Loop through the task list, executing tasks as appropriate. */
    while(1) {
        for(int i = 0; i < 3; i++) {
            task* t = task_list[i];
            if(difftime(time(0), t->start_time) >= t->frequency) {
                /* Execute the task. */
                printf("Executing task %d:\n", t->id);
                t->task_function();

                /* Update the start time for the task. */
                t->start_time = time(0);
            }
        }
    }

    return 0;
}