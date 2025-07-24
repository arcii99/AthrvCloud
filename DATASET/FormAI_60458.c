//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5 // Maximum number of tasks in the scheduler
#define MAX_TASK_LENGTH 10 // Maximum length of each task in seconds

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Structure to represent a task in the scheduler
typedef struct {
    int id; // Identifier for the task
    int length; // Length of the task in seconds
    int priority; // Priority level for the task (higher the value, higher the priority)
} Task;

// Function to create a new task with randomly generated attributes
Task createTask(int id) {
    Task task;
    task.id = id;
    task.length = getRandomNumber(1, MAX_TASK_LENGTH);
    task.priority = getRandomNumber(1, 10);
    return task;
}

// Function to schedule tasks based on their priority and length
void scheduleTasks(Task tasks[], int n) {
    int i, j;
    Task temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(tasks[i].priority < tasks[j].priority) {
                // Swap tasks if priority of task i is lesser than that of task j
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            } else if(tasks[i].priority == tasks[j].priority && tasks[i].length > tasks[j].length) {
                // Swap tasks if priority of task i and task j is same, but length of task i is greater than that of task j
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with current time
    Task tasks[MAX_TASKS];
    int i, totalTime = 0;

    // Generate random tasks and calculate total time required to complete all tasks
    for(i = 0; i < MAX_TASKS; i++) {
        tasks[i] = createTask(i+1);
        printf("Task %d - Priority %d, Length %d seconds\n", tasks[i].id, tasks[i].priority, tasks[i].length);
        totalTime += tasks[i].length;
    }

    printf("Total time required to complete all tasks = %d seconds\n", totalTime);

    scheduleTasks(tasks, MAX_TASKS); // Schedule the tasks based on their priority and length

    // Print the scheduled order of tasks along with their actual start and end times
    int startTime = 0, endTime;
    for(i = 0; i < MAX_TASKS; i++) {
        printf("Task %d started at %d seconds and finished at %d seconds\n", tasks[i].id, startTime, (startTime + tasks[i].length));
        endTime = startTime + tasks[i].length;
        startTime = endTime;
    }

    return 0;
}