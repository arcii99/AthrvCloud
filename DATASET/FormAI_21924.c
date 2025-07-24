//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>

int main() {
    int num_tasks, max_time;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);
    printf("Enter the maximum time for each task: ");
    scanf("%d", &max_time);
    int task_time[num_tasks], task_order[num_tasks], temp;
    printf("Enter the time taken for each task:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: ", i+1);
        scanf("%d", &task_time[i]);
        task_order[i] = i+1;
    }
    for (int i = 0; i < num_tasks-1; i++) {
        for (int j = i+1; j < num_tasks; j++) {
            if (task_time[i] < task_time[j]) {
                temp = task_time[i];
                task_time[i] = task_time[j];
                task_time[j] = temp;

                temp = task_order[i];
                task_order[i] = task_order[j];
                task_order[j] = temp;
            }
        }
    }
    int total_time = 0;
    printf("Task order to maximize time efficiency: ");
    for (int i = 0; i < num_tasks; i++) {
        if (total_time + task_time[i] <= max_time) {
            printf("%d ", task_order[i]);
            total_time += task_time[i];
        } else {
            break;
        }
    }
    printf("\nTotal time taken for these tasks: %d", total_time);
    return 0;
}