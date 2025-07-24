//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Task {
    char name[50];
    int priority;
    int deadline;
    int time;
} Task;

void printTask(Task t) {
    printf("Task: %s\n", t.name);
    printf("Priority: %d\n", t.priority);
    printf("Deadline: %d seconds\n", t.deadline);
    printf("Time required: %d seconds\n\n", t.time);
}

void schedule(Task* tasks, int size) {
    int current_time = 0;
    int completed = 0;
    while (completed < size) {
        printf("Current time: %d seconds\n\n", current_time);
        int highest_priority = -1;
        int next_task = -1;
        for (int i = 0; i < size; i++) {
            if (tasks[i].priority > highest_priority && tasks[i].deadline >= current_time && tasks[i].time > 0) {
                highest_priority = tasks[i].priority;
                next_task = i;
            }
        }
        if (next_task != -1) {
            printf("Executing task: %s\n", tasks[next_task].name);
            tasks[next_task].time--;
            if (tasks[next_task].time == 0) {
                printf("Task %s completed!\n\n", tasks[next_task].name);
                completed++;
            }
        } else {
            printf("No tasks available to execute at this time...\n\n");
        }
        current_time++;
    }
}

int main() {
    srand(time(NULL));
    Task tasks[5];
    strcpy(tasks[0].name, "Hack into the mainframe");
    tasks[0].priority = 10;
    tasks[0].deadline = rand() % 10;
    tasks[0].time = rand() % 10 + 1;
    strcpy(tasks[1].name, "Steal confidential data");
    tasks[1].priority = 9;
    tasks[1].deadline = rand() % 10;
    tasks[1].time = rand() % 10 + 1;
    strcpy(tasks[2].name, "Plant a virus in the system");
    tasks[2].priority = 8;
    tasks[2].deadline = rand() % 10;
    tasks[2].time = rand() % 10 + 1;
    strcpy(tasks[3].name, "Disable security cameras");
    tasks[3].priority = 7;
    tasks[3].deadline = rand() % 10;
    tasks[3].time = rand() % 10 + 1;
    strcpy(tasks[4].name, "Encrypt the stolen data");
    tasks[4].priority = 6;
    tasks[4].deadline = rand() % 10;
    tasks[4].time = rand() % 10 + 1;

    printf("List of tasks:\n\n");
    for (int i = 0; i < 5; i++) {
        printTask(tasks[i]);
    }

    printf("Scheduling tasks...\n\n");
    schedule(tasks, 5);
    printf("All tasks completed!\n");

    return 0;
}