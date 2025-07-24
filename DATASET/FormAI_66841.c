//FormAI DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // allocate memory for task list
    int *taskList = malloc(sizeof(int) * 10);

    // initialize task list
    for (int i = 0; i < 10; i++) {
        taskList[i] = i + 1;
    }

    // seed random number generator
    srand(time(0));

    // randomly shuffle task list
    for (int i = 0; i < 10; i++) {
        int j = rand() % 10;
        int temp = taskList[i];
        taskList[i] = taskList[j];
        taskList[j] = temp;
    }

    // print shuffled task list
    printf("Task List:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", taskList[i]);
    }
    printf("\n");

    // run tasks in shuffled order
    printf("Running Tasks...\n");
    for (int i = 0; i < 10; i++) {
        printf("Task %d\n", taskList[i]);
        // perform task
    }

    // free memory
    free(taskList);

    return 0;
}