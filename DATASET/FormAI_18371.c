//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define task function types
typedef void (*TaskFunction)(void);

// Define task structure
typedef struct {
    TaskFunction function;
    time_t execute_time;
} Task;

// Define compare function for sorting tasks, compares execute_time
int compare_tasks(const void* task1, const void* task2) {
    const Task* t1 = task1;
    const Task* t2 = task2;
    return difftime(t1->execute_time, t2->execute_time);
}

int main() {
    Task tasks[5]; // Create array of 5 tasks
    int i;

    // Initialize seed for random number generator
    srand(time(NULL));

    // Define task functions that simply print a message
    void task1() { printf("Task 1 executed!\n"); }
    void task2() { printf("Task 2 executed!\n"); }
    void task3() { printf("Task 3 executed!\n"); }
    void task4() { printf("Task 4 executed!\n"); }
    void task5() { printf("Task 5 executed!\n"); }

    // Add task functions to task array with random execute times
    for (i = 0; i < 5; i++) {
        int execute_sec = rand() % 60; // random value between 0 and 59
        tasks[i].execute_time = time(NULL) + execute_sec;
        // Assign task function based on i
        switch (i) {
            case 0: tasks[i].function = task1; break;
            case 1: tasks[i].function = task2; break;
            case 2: tasks[i].function = task3; break;
            case 3: tasks[i].function = task4; break;
            case 4: tasks[i].function = task5; break;
        }
    }

    // Sort task array by execute time
    qsort(tasks, 5, sizeof(Task), compare_tasks);

    // Loop through tasks, executing and removing them from the task array
    while (i < 5) {
        // Wait for the next task to be ready
        time_t current_time = time(NULL);
        double time_diff = difftime(tasks[i].execute_time, current_time);
        if (time_diff > 0) {
            sleep(time_diff);
            continue;
        }

        // Execute the task and remove it from the task array
        tasks[i].function();
        i++;
    }

    return 0;
}