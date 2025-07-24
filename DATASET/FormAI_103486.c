//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 50
#define MAX_TIME 30

struct Task {
    int id;
    int priority;
    int time;
};

typedef struct Task Task;

int compare(const void* a, const void* b) {
    Task t1 = *(Task*)a;
    Task t2 = *(Task*)b;
    
    if (t1.priority == t2.priority) {
        return t2.time - t1.time;
    }
    return t2.priority - t1.priority;
}

int main() {
    Task tasks[MAX_TASKS] = {0};
    int num_tasks = 0;
    
    srand(time(NULL));
    
    // Generate random tasks
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i;
        tasks[i].priority = rand() % 10 + 1;
        tasks[i].time = rand() % MAX_TIME + 1;
        if (tasks[i].priority < 5) {
            tasks[i].time = tasks[i].time / 2; // Tasks with lower priorities take less time
        }
        num_tasks++;
    }
    
    printf("Task Scheduler:\n");
    
    // Sort tasks by priority and time
    qsort(tasks, num_tasks, sizeof(Task), compare);
    
    int time_remaining = MAX_TIME;
    
    for (int i = 0; i < num_tasks; i++) {
        Task task = tasks[i];
        int task_time = task.time;
        
        if (task_time > time_remaining) {
            printf("%d: Skipping task %d (priority %d, time %d)\n", time_remaining, task.id, task.priority, task_time);
            continue;
        }
        
        printf("%d: Executing task %d (priority %d, time %d)\n", time_remaining, task.id, task.priority, task_time);
        
        time_remaining -= task_time;
        
        if (time_remaining <= 0) {
            printf("Out of time, stopping task scheduler\n");
            break;
        }
    }
    
    return 0;
}