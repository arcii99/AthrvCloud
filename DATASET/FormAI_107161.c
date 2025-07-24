//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

#define MAX_TASKS 10 // Maximum number of tasks that can be scheduled
#define TIME_UNIT 1 // Time unit for the scheduler, can be changed as needed

typedef struct {
    int task_id; // Unique ID for each task
    bool completed; // Flag to indicate if task is complete or not
    int deadline; // Deadline for the task to be completed by
    int duration; // Estimated duration for the task to complete
} Task;

int schedule(Task tasks[], int num_tasks);

int main() {
    Task tasks[MAX_TASKS];

    // Initialize tasks with unique IDs, deadlines and durations
    tasks[0] = (Task){.task_id = 1, .completed = false, .deadline = 10, .duration = 5};
    tasks[1] = (Task){.task_id = 2, .completed = false, .deadline = 15, .duration = 3};
    tasks[2] = (Task){.task_id = 3, .completed = false, .deadline = 20, .duration = 7};
    tasks[3] = (Task){.task_id = 4, .completed = false, .deadline = 8, .duration = 2};
    tasks[4] = (Task){.task_id = 5, .completed = false, .deadline = 12, .duration = 4};

    int num_tasks = 5;

    int total_time = schedule(tasks, num_tasks);

    printf("Total time taken to complete all tasks: %d\n", total_time);

    return 0;
}

int schedule(Task tasks[], int num_tasks) {
    int current_time = 0;
    int total_time = 0;
    int i, j;

    // Keep looping until all tasks are completed
    while (true) {
        int shortest_deadline = -1;
        int shortest_index = -1;

        // Find the shortest deadline task that has not been completed yet
        for (i = 0; i < num_tasks; i++) {
            if (!tasks[i].completed) {
                if (shortest_deadline == -1 || tasks[i].deadline < shortest_deadline) {
                    shortest_deadline = tasks[i].deadline;
                    shortest_index = i;
                }
            }
        }

        // If no tasks are available to execute, break out of the loop
        if (shortest_index == -1) {
            break;
        }

        // Execute the shortest deadline task and mark it as complete
        printf("Task ID: %d, Deadline: %d, Duration: %d\n",
            tasks[shortest_index].task_id, tasks[shortest_index].deadline, tasks[shortest_index].duration);
        tasks[shortest_index].completed = true;

        // Update the current time and total time taken
        current_time += tasks[shortest_index].duration;
        total_time += tasks[shortest_index].duration;

        // Check if the deadline has been missed and print a warning if it has
        if (current_time > tasks[shortest_index].deadline) {
            printf("WARNING: Task with ID %d has missed its deadline!\n", tasks[shortest_index].task_id);
        }

        // Wait for TIME_UNIT before checking for new tasks
        for (j = 0; j < TIME_UNIT; j++) {
            // Do nothing
        }
    }

    return total_time;
}