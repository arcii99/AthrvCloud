//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TASKS_MAX 10
#define NAME_LEN_MAX 20
#define DESC_LEN_MAX 50

typedef struct {
    char name[NAME_LEN_MAX];
    char description[DESC_LEN_MAX];
    int priority;
    int duration;
} Task;

void print_task(Task task) {
    printf("\nName: %s\n", task.name);
    printf("Description: %s\n", task.description);
    printf("Priority: %d\n", task.priority);
    printf("Duration: %d\n", task.duration);
}

Task generate_random_task(int id) {
    Task task;
    sprintf(task.name, "Task %d", id);
    sprintf(task.description, "This is task %d description", id);
    task.priority = rand() % 10 + 1;
    task.duration = rand() % 10 + 1;
    return task;
}

bool insert_task(Task tasks[], Task task, int *count) {
    if (*count >= TASKS_MAX) {
        return false;
    }
    tasks[*count] = task;
    *count = *count + 1;
    return true;
}

void sort_tasks(Task tasks[], int count) {
    int i, j;
    Task temp;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int count = 0;
    Task tasks[TASKS_MAX];

    int i;
    for (i = 0; i < TASKS_MAX; i++) {
        Task task = generate_random_task(i);
        if (!insert_task(tasks, task, &count)) {
            break;
        }
    }

    sort_tasks(tasks, count);

    printf("Scheduled tasks:\n");
    for (i = 0; i < count; i++) {
        print_task(tasks[i]);
    }

    return 0;
}