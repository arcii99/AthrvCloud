//FormAI DATASET v1.0 Category: Task Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

/* Structure to hold task information */
struct task {
    int task_id;
    int priority;
    int time;
};

/* Compare function for qsort() */
int compare(const void *t1, const void *t2) {
    int p1 = ((struct task*)t1)->priority;
    int p2 = ((struct task*)t2)->priority;
    return p2 - p1;
}

int main() {
    int num_tasks, i, total_time = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    struct task tasks[num_tasks];

    /* Prompt user for task information */
    for(i = 0; i < num_tasks; i++) {
        printf("\nEnter task %d priority (1-10): ", i+1);
        scanf("%d", &tasks[i].priority);

        printf("Enter task %d time (in seconds): ", i+1);
        scanf("%d", &tasks[i].time);

        tasks[i].task_id = i+1;

        total_time += tasks[i].time;
    }

    /* Sort tasks by priority (highest to lowest) */
    qsort(tasks, num_tasks, sizeof(struct task), compare);

    /* Run through tasks in priority order for execution */
    int current_time = 0;
    for(i = 0; i < num_tasks; i++) {
        printf("\nExecuting Task %d with priority %d for %d seconds.", tasks[i].task_id, tasks[i].priority, tasks[i].time);

        current_time += tasks[i].time;

        /* Calculate percentage completion and estimated time remaining */
        float percent_completed = ((float)current_time / total_time) * 100;
        int time_remaining = total_time - current_time;

        printf("\nTask %d completed. %.2f%% of tasks complete. Approximately %d seconds remaining.\n", tasks[i].task_id, percent_completed, time_remaining);
    }

    printf("\nAll tasks complete.");
    return 0;
}