//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to hold task information
typedef struct {
    char* name;
    int priority;
    int duration;
    int deadline;
} Task;

// Function to create a new task
Task createTask(char* name, int priority, int duration, int deadline) {
    Task task;
    task.name = name;
    task.priority = priority;
    task.duration = duration;
    task.deadline = deadline;
    return task;
}

// Function to print a task
void printTask(Task task) {
    printf("Task: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Duration: %d\n", task.duration);
    printf("Deadline: %d\n\n", task.deadline);
}

// Function to compare two tasks by priority
int compareTasks(const void* t1, const void* t2) {
    Task* task1 = (Task*) t1;
    Task* task2 = (Task*) t2;
    return (task2->priority - task1->priority);
}

// Function to schedule the tasks
void scheduleTasks(Task* tasks, int count) {
    int i, j, k;
    int startTime = 8; // Start time at 8am
    int endTime = 18; // End time at 6pm
    int totalTime = endTime - startTime; // Total available time for tasks
    int remainingTime = totalTime; // Remaining time for tasks
    int scheduledTime = 0; // Total time scheduled for tasks

    // Sort tasks by priority
    qsort(tasks, count, sizeof(Task), compareTasks);

    // Schedule tasks
    printf("Scheduling Tasks:\n\n");
    for (i = 0; i < count; i++) {
        Task task = tasks[i];

        // Check if task can be scheduled
        if (task.duration <= remainingTime) {
            // Schedule task
            printf("Scheduled Task: %s\n", task.name);
            printf("Start Time: %d\n", startTime + scheduledTime);
            scheduledTime += task.duration;
            remainingTime -= task.duration;
        } else {
            // Split task into smaller tasks
            printf("Splitting Task: %s\n", task.name);
            k = 1;
            while (k < task.duration) {
                j = i + 1;
                printf("Scheduled Subtask: %s (%d/%d)\n", task.name, k, task.duration);
                printf("Start Time: %d\n\n", startTime + scheduledTime);
                scheduledTime += 1; // Schedule subtask for 1 hour
                remainingTime -= 1;
                k++;
                if (j >= count) {
                    printf("Failed to Schedule All Tasks. Consider Adjusting Priorities.\n");
                    return;
                } else {
                    task = tasks[j];
                }
            }
            // Schedule remaining part of task
            printf("Scheduled Task: %s\n", task.name);
            printf("Start Time: %d\n", startTime + scheduledTime);
            scheduledTime += task.duration - k + 1;
            remainingTime -= task.duration - k + 1;
            i = j;
        }
        // Check if all tasks have been scheduled
        if (scheduledTime >= totalTime) {
            printf("\nAll Tasks Scheduling Complete.\n");
            printf("Remaining Time: %d\n", remainingTime);
            return;
        }
    }
    printf("\nAll Tasks Scheduling Complete.\n");
    printf("Remaining Time: %d\n", remainingTime);
}

int main() {
    // Create tasks
    Task task1 = createTask("Battle Strategy Meeting", 5, 2, 10);
    Task task2 = createTask("Sword Practice", 7, 3, 13);
    Task task3 = createTask("Armor Repair", 3, 4, 16);
    Task task4 = createTask("Horse Training", 4, 5, 19);
    Task task5 = createTask("Shield Maintenance", 6, 6, 22);
    Task task6 = createTask("Patrolling Perimeter", 2, 7, 25);
    Task task7 = createTask("Castle Cleaning", 1, 8, 28);
    Task task8 = createTask("Feast Preparation", 8, 9, 31);

    // Add tasks to array
    Task tasks[] = {task1, task2, task3, task4, task5, task6, task7, task8};
    int count = sizeof(tasks) / sizeof(tasks[0]);

    // Schedule tasks
    scheduleTasks(tasks, count);

    return 0;
}