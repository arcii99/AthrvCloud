//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task Task;

struct Task {
    int id;
    int priority;
    int time;
    bool running;
};

void run(Task tasks[], int size, int time) {
    int i;
    for (i = 0; i < size; ++i) {
        if (!tasks[i].running) {
            if (time % tasks[i].priority == 0) {
                tasks[i].running = true;
                printf("Task %d started running\n", tasks[i].id);
            }
        } else {
            tasks[i].time--;
            if (tasks[i].time == 0) {
                tasks[i].running = false;
                printf("Task %d finished\n", tasks[i].id);
            }
        }
    }
}

int main() {
    Task tasks[] = {
        {1, 2, 4, false},
        {2, 3, 6, false},
        {3, 5, 10, false},
    };

    int size = sizeof(tasks) / sizeof(tasks[0]);
    int i, time;
    for (time = 1; time <= 30; ++time) {
        printf("Time: %d\n", time);
        run(tasks, size, time);
        printf("\n");
    }

    return 0;
}