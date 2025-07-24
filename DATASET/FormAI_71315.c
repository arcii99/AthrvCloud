//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Task structure containing task ID and time required to complete the task
struct Task {
    int id;
    int time;
};

// Function to compare tasks based on their time required to complete
int compare_tasks(const void* task1, const void* task2) {
    const struct Task* t1 = task1;
    const struct Task* t2 = task2;
    return t1->time - t2->time;
}

// Function to execute a task
void execute_task(struct Task task) {
    printf("Executing task with ID %d and time required %d\n", task.id, task.time);
}

// Function to schedule tasks in order of their time required to complete
void schedule_tasks(struct Task tasks[], int num_tasks) {
    // Sort tasks in order of their time required to complete using quicksort algorithm
    qsort(tasks, num_tasks, sizeof(struct Task), compare_tasks);

    // Execute tasks in order of their time required to complete
    for (int i = 0; i < num_tasks; i++) {
        execute_task(tasks[i]);
    }
}

int main() {
    // Example task set
    struct Task tasks[] = {
        {1, 5},
        {2, 3},
        {3, 2},
        {4, 8},
        {5, 1}
    };

    // Schedule tasks in order of their time required to complete
    schedule_tasks(tasks, 5);

    // Exit program with success
    return 0;
}