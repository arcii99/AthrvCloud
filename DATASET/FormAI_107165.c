//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a task struct
typedef struct {
    int id;
    int interval;
    void (*func)();
    int counter;
} Task;

// Define an array of tasks
Task tasks[10];

// Define a function that adds a new task to the array
void addTask(int id, int interval, void (*func)()) {
    for(int i = 0; i < 10; i++) {
        if(tasks[i].id == 0) {
            tasks[i].id = id;
            tasks[i].interval = interval;
            tasks[i].func = func;
            tasks[i].counter = interval;
            printf("Added task with ID #%d\n", id);
            return;
        }
    }
    printf("Task list is full. Cannot add task with ID #%d\n", id);
}

// Define a function that removes a task from the array
void removeTask(int id) {
    for(int i = 0; i < 10; i++) {
        if(tasks[i].id == id) {
            tasks[i].id = 0;
            printf("Removed task with ID #%d\n", id);
            return;
        }
    }
    printf("Task with ID #%d not found in task list\n", id);
}

// Define a function that checks if any tasks need to be run and runs them
void checkTasks() {
    for(int i = 0; i < 10; i++) {
        if(tasks[i].id != 0) {
            tasks[i].counter--;
            if(tasks[i].counter == 0) {
                tasks[i].func();
                tasks[i].counter = tasks[i].interval;
            }
        }
    }
}

// Define some example functions that can be run as tasks
void printTask1() {
    printf("Task 1 has run\n");
}

void printTask2() {
    printf("Task 2 has run\n");
}

void printTask3() {
    printf("Task 3 has run\n");
}

int main() {
    // Initialize task array
    for(int i = 0; i < 10; i++) {
        tasks[i].id = 0;
    }

    // Add some example tasks
    addTask(1, 5, &printTask1);
    addTask(2, 10, &printTask2);
    addTask(3, 3, &printTask3);

    // Check tasks every second
    int timer = 0;
    while(1) {
        printf("Timer: %d\n", timer);
        checkTasks();
        timer++;
        sleep(1);
    }

    return 0;
}