//FormAI DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_COUNT 100
#define MAX_TIMESLOT 100
#define RANDOM_RANGE 5

// Struct to represent each task
typedef struct {
    int id;
    int timeslot;
    int paranoid_level;
} Task;

// Function to generate a random number within range
int generateRandom(int range) {
    return rand() % range + 1;
}

int main() {
    srand(time(NULL));

    Task tasks[TASK_COUNT];

    // Initialize tasks with random values
    for (int i = 0; i < TASK_COUNT; i++) {
        tasks[i].id = i;
        tasks[i].timeslot = generateRandom(MAX_TIMESLOT);
        tasks[i].paranoid_level = generateRandom(RANDOM_RANGE);
    }

    // Sort tasks by paranoid level
    for (int i = 0; i < TASK_COUNT - 1; i++) {
        for (int j = i + 1; j < TASK_COUNT; j++) {
            if (tasks[i].paranoid_level < tasks[j].paranoid_level) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Execute tasks in order of paranoid level
    for (int i = 0; i < TASK_COUNT; i++) {
        printf("Executing task %d with paranoid level %d and timeslot %d\n", 
            tasks[i].id, tasks[i].paranoid_level, tasks[i].timeslot);
        for (int j = 0; j < tasks[i].timeslot; j++) {
            // Randomly pause execution to simulate paranoia
            if (generateRandom(RANDOM_RANGE) <= tasks[i].paranoid_level) {
                printf("Task %d paused at timeslot %d\n", tasks[i].id, j);
                // Wait for random number of timeslots before resuming task
                j += generateRandom(RANDOM_RANGE);
                printf("Task %d resumed at timeslot %d\n", tasks[i].id, j);
            }
        }
    }

    printf("All tasks completed successfully!\n");

    return 0;
}