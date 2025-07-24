//FormAI DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char name[50];
    int delay;
    int priority;
    bool active;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(char name[], int delay, int priority) {
    if(numTasks < MAX_TASKS) {
        tasks[numTasks].id = numTasks + 1;
        strcpy(tasks[numTasks].name, name);
        tasks[numTasks].delay = delay;
        tasks[numTasks].priority = priority;
        tasks[numTasks].active = true;
        
        numTasks++;
    } else {
        printf("Maximum number of tasks reached.\n");
    }
}

void deleteTask(int taskId) {
    int index = -1;
    for(int i=0; i<numTasks; i++) {
        if(tasks[i].id == taskId) {
            index = i;
            break;
        }
    }
    
    if(index != -1) {
        tasks[index].active = false;
        printf("Task with ID %d has been deleted.\n", taskId);
    } else {
        printf("Task with ID %d not found.\n", taskId);
    }
}

void printTasks() {
    printf("ID\tName\tDelay\tPriority\n");
    for(int i=0; i<numTasks; i++) {
        if(tasks[i].active) {
            printf("%d\t%s\t%d\t%d\n", tasks[i].id, tasks[i].name, tasks[i].delay, tasks[i].priority);
        }
    }
}

void executeTask(Task task) {
    printf("Executing task %s with ID %d...\n", task.name, task.id);
}

int main() {
    srand(time(NULL));
    
    addTask("Task 1", rand() % 10, rand() % 10 + 1);
    addTask("Task 2", rand() % 10, rand() % 10 + 1);
    addTask("Task 3", rand() % 10, rand() % 10 + 1);
    addTask("Task 4", rand() % 10, rand() % 10 + 1);
    
    printf("Task scheduler started.\n");
    
    while(true) {
        for(int i=0; i<numTasks; i++) {
            if(tasks[i].active) {
                tasks[i].delay--;
                if(tasks[i].delay == 0) {
                    executeTask(tasks[i]);
                    tasks[i].delay = rand() % 10;
                    tasks[i].priority = rand() % 10 + 1;
                }
            }
        }
        
        printTasks();
        printf("Press any key to continue, or ctrl+c to exit.\n");
        
        getchar();
    }
    
    return 0;
}