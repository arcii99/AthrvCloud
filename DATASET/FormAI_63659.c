//FormAI DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A Task Scheduler that will decide randomly
 * whether the tasks will be executed or not
 */ 

int main() {
    srand(time(NULL)); // Seeding the random function

    printf("Welcome to the Random Task Scheduler! Let's get started\n\n");

    int num_tasks;
    printf("Enter the number of tasks you want to schedule: ");
    scanf("%d", &num_tasks);

    int tasks[num_tasks];
    for(int i = 0; i < num_tasks; i++) {
        tasks[i] = i + 1;
    }

    printf("\n\nTasks to be scheduled: ");
    for(int i = 0; i < num_tasks; i++) {
        printf("%d ", tasks[i]);
    }

    printf("\n\nPress any key to schedule tasks randomly...\n\n");
    getchar();
    getchar();

    printf("Here's the fun part! The tasks being scheduled randomly are:\n\n");

    for(int i = 0; i < num_tasks; i++) {
        int r = rand() % 2;
        if(r == 1) {
            printf("Task %d will be executed!\n", tasks[i]);
        } else {
            printf("Oops! Task %d will NOT be executed this time.\n", tasks[i]);
        }
    }

    printf("\nThere you go! All tasks have been scheduled.\n");

    return 0;
}