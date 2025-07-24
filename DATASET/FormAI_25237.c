//FormAI DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int priority;
    int time;
    int executed;
} Task;

int generate_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

Task generate_task(int id) {
    Task t;
    t.id = id;
    t.priority = generate_random_int(1, 10);
    t.time = generate_random_int(1, 10);
    t.executed = 0;
    return t;
}

void print_task(Task t) {
    printf("Task ID: %d, Priority: %d, Time: %d, Executed: %d\n", t.id, t.priority, t.time, t.executed);
}

void print_tasks(Task tasks[], int num_tasks) {
    printf("Current Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("[%d] ", i);
        print_task(tasks[i]);
    }
}

int main() {
    srand(time(NULL));
    
    Task tasks[MAX_TASKS];
    int num_tasks = generate_random_int(1, MAX_TASKS);
    
    printf("Generating %d tasks...\n", num_tasks);
    for (int i = 0; i < num_tasks; i++) {
        tasks[i] = generate_task(i+1);
        print_task(tasks[i]);
    }
    printf("\n");
    
    for (int i = 0; i < num_tasks; i++) {
        int highest_priority_task_index = -1;
        for (int j = 0; j < num_tasks; j++) {
            if (tasks[j].executed == 0) {
                if (highest_priority_task_index == -1 || tasks[j].priority > tasks[highest_priority_task_index].priority) {
                    highest_priority_task_index = j;
                }
            }
        }
        
        if (highest_priority_task_index != -1) {
            printf("Executing task %d\n", tasks[highest_priority_task_index].id);
            tasks[highest_priority_task_index].executed = 1;
        }
    }
    
    printf("\nAll tasks executed\n");
    
    return 0;
}