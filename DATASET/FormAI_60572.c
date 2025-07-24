//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure for storing information regarding a task
struct task {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

// Function to initialize a task with random values
void initTask(struct task* t) {
    t->id = rand() % 100;
    t->priority = rand() % 10 + 1;
    t->arrival_time = rand() % 50;
    t->burst_time = rand() % 20 + 1;
    t->remaining_time = t->burst_time;
    t->waiting_time = 0;
    t->turnaround_time = 0;
}

// Function to print information about a task
void printTask(struct task t) {
    printf("Task ID: %d\n", t.id);
    printf("Priority: %d\n", t.priority);
    printf("Arrival Time: %d\n", t.arrival_time);
    printf("Burst Time: %d\n", t.burst_time);
    printf("Remaining Time: %d\n", t.remaining_time);
    printf("Waiting Time: %d\n", t.waiting_time);
    printf("Turnaround Time: %d\n", t.turnaround_time);
}

// Function to swap two tasks
void swap(struct task* a, struct task* b) {
    struct task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement selection sort on an array of tasks based on arrival time
void sortOnArrivalTime(struct task tasks[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(tasks[j].arrival_time < tasks[min_idx].arrival_time) {
                min_idx = j;
            }
        }
        swap(&tasks[i], &tasks[min_idx]);
    }
}

// Function to implement selection sort on an array of tasks based on priority
void sortOnPriority(struct task tasks[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(tasks[j].priority < tasks[min_idx].priority) {
                min_idx = j;
            }
        }
        swap(&tasks[i], &tasks[min_idx]);
    }
}

// Function to schedule tasks using First-Come-First-Serve algorithm
void executeFCFS(struct task tasks[], int n) {
    int time = 0;
    for(int i = 0; i < n; i++) {
        if(time < tasks[i].arrival_time) {
            time = tasks[i].arrival_time;
        }
        tasks[i].waiting_time = time - tasks[i].arrival_time;
        tasks[i].turnaround_time = tasks[i].waiting_time + tasks[i].burst_time;
        time += tasks[i].burst_time;
    }
}

// Function to schedule tasks using Round-Robin algorithm with time quantum of q
void executeRoundRobin(struct task tasks[], int n, int q) {
    int time = 0;
    int curr_idx = 0;
    while(1) {
        int flag = 1;
        for(int i = 0; i < n; i++) {
            if(tasks[i].remaining_time > 0) {
                flag = 0;
                if(tasks[i].arrival_time <= time) {
                    int min_time = (tasks[i].remaining_time < q) ? tasks[i].remaining_time : q;
                    tasks[i].remaining_time -= min_time;
                    time += min_time;
                    if(tasks[i].remaining_time == 0) {
                        tasks[i].waiting_time = time - tasks[i].arrival_time - tasks[i].burst_time;
                        tasks[i].turnaround_time = tasks[i].waiting_time + tasks[i].burst_time;
                    }
                }
            }
        }
        if(flag == 1) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 5;
    struct task tasks[n];
    for(int i = 0; i < n; i++) {
        initTask(&tasks[i]);
    }
    printf("Tasks Before Scheduling\n");
    for(int i = 0; i < n; i++) {
        printTask(tasks[i]);
        printf("\n");
    }
    sortOnArrivalTime(tasks, n);
    executeFCFS(tasks, n);
    printf("Tasks After Scheduling Using FCFS\n");
    for(int i = 0; i < n; i++) {
        printTask(tasks[i]);
        printf("\n");
    }
    sortOnPriority(tasks, n);
    executeRoundRobin(tasks, n, 5);
    printf("Tasks After Scheduling Using Round-Robin\n");
    for(int i = 0; i < n; i++) {
        printTask(tasks[i]);
        printf("\n");
    }
    return 0;
}