//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 10 //Maximum tasks allowed in the queue
#define MAX_TASK_TIME 5 //Maximum task time allowed in seconds

typedef struct task{
    char name[20];
    int time;
    bool complete;
} Task;

typedef struct taskQueue{
    int front, rear, count;
    Task tasks[MAX_TASKS];
} TaskQueue;

void initializeQueue(TaskQueue *q){
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isQueueFull(TaskQueue *q){
    return q->count == MAX_TASKS;
}

bool isQueueEmpty(TaskQueue *q){
    return q->count == 0;
}

void enqueue(TaskQueue *q, Task t){
    if(isQueueFull(q)){
        printf("Queue is full. Task '%s' cannot be added!\n", t.name);
        return;
    }
    q->rear = (q->rear + 1) % MAX_TASKS;
    q->tasks[q->rear] = t;
    q->count++;
    printf("Task '%s' added to the queue successfully!\n", t.name);
}

Task dequeue(TaskQueue *q){
    if(isQueueEmpty(q)){
        printf("Queue is empty. No task to complete!\n");
        Task emptyTask = {"", 0, false};
        return emptyTask;
    }
    Task t = q->tasks[q->front];
    q->front = (q->front + 1) % MAX_TASKS;
    q->count--;
    printf("Task '%s' completed successfully!\n", t.name);
    return t;
}

void displayQueue(TaskQueue *q){
    if(isQueueEmpty(q)){
        printf("Task Queue is empty!\n");
        return;
    }
    TaskQueue temp;
    initializeQueue(&temp);
    printf("Current Task queue:\n");
    while(!isQueueEmpty(q)){
        Task t = dequeue(q);
        printf("| %15s | %5d |\n", t.name, t.time);
        enqueue(&temp, t);
    }
    while(!isQueueEmpty(&temp)){
        enqueue(q, dequeue(&temp));
    }
}

void runTask(Task t){
    printf("Executing task '%s'...\n", t.name);
    time_t start_time = time(NULL);
    while(time(NULL) - start_time < t.time){
        //Busy waiting
    }
    t.complete = true;
    printf("Task '%s' completed!\n", t.name);
}

int main(){
    TaskQueue q;
    initializeQueue(&q);

    printf("-------Task Scheduler----------\n");
    printf("| Task Name        | Time (s) |\n");
    printf("|------------------|----------|\n");
    Task t1 = {"Task 1", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t1.name, t1.time);
    Task t2 = {"Task 2", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t2.name, t2.time);
    Task t3 = {"Task 3", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t3.name, t3.time);
    Task t4 = {"Task 4", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t4.name, t4.time);
    Task t5 = {"Task 5", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t5.name, t5.time);
    Task t6 = {"Task 6", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t6.name, t6.time);
    Task t7 = {"Task 7", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t7.name, t7.time);
    Task t8 = {"Task 8", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t8.name, t8.time);
    Task t9 = {"Task 9", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t9.name, t9.time);
    Task t10 = {"Task 10", rand() % MAX_TASK_TIME + 1, false};
    printf("| %15s | %5d |\n", t10.name, t10.time);
    printf("|------------------|----------|\n");

    enqueue(&q, t1);
    enqueue(&q, t2);
    enqueue(&q, t3);
    enqueue(&q, t4);
    enqueue(&q, t5);
    enqueue(&q, t6);
    enqueue(&q, t7);
    enqueue(&q, t8);
    enqueue(&q, t9);
    enqueue(&q, t10);

    displayQueue(&q);

    while(!isQueueEmpty(&q)){
        Task t = dequeue(&q);
        runTask(t);
    }

    printf("All tasks completed successfully!\n");

    return 0;
}