//FormAI DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 20

typedef struct {
    int hour;
    int minute;
    char task[100];
} Task;

// Function to print tasks for a given time
void print_tasks(int hour, int minute, Task tasks[], int num_tasks) {
    printf("Today's tasks for %02d:%02d:\n", hour, minute);
    int i;
    for(i = 0; i < num_tasks; i++) {
        if(tasks[i].hour == hour && tasks[i].minute == minute) {
            printf("- %s\n", tasks[i].task);
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    // Add some sample tasks
    Task task1 = {8, 30, "Prepare breakfast"};
    Task task2 = {9, 0, "Go for a walk"};
    Task task3 = {14, 0, "Attend meeting"};
    tasks[num_tasks++] = task1;
    tasks[num_tasks++] = task2;
    tasks[num_tasks++] = task3;

    // Get current time
    time_t now;
    time(&now);
    struct tm *time_info = localtime(&now);
    int current_hour = time_info->tm_hour;
    int current_minute = time_info->tm_min;

    // Print today's tasks
    print_tasks(current_hour, current_minute, tasks, num_tasks);

    return 0;
}