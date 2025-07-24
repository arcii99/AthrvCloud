//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//define processes
struct Process {
    char name[10];
    int burstTime;
    int priority;
} p[5];

//compare function to sort processes based on priority
int comparePriority(const void *a, const void *b) {
    return ((struct Process*)b)->priority - ((struct Process*)a)->priority;
}

//compare function to sort processes based on burst time
int compareBurstTime(const void *a, const void *b) {
    return ((struct Process*)a)->burstTime - ((struct Process*)b)->burstTime;
}

int main() {
    int i, j, k, l = 0, m = 0, n = 0;
    float averageTurnaroundTime = 0, averageWaitingTime = 0;
    int totalTurnaroundTime = 0, totalWaitingTime = 0;

    //initialize processes
    for(i = 0; i < 5; i++) {
        sprintf(p[i].name, "P%d", i+1);
        p[i].burstTime = rand()%11+1;
        p[i].priority = rand()%10+1;
    }

    //print initial state of processes
    printf("Initial Processes State:\n");
    printf("Process\tBurst Time\tPriority\n");
    for(i = 0; i < 5; i++) {
        printf("%s\t%d\t\t%d\n", p[i].name, p[i].burstTime, p[i].priority);
    }
    printf("\n");

    //sort based on priority
    qsort(p, 5, sizeof(struct Process), comparePriority);

    //print after sorting based on priority
    printf("Processes After Sorting Based on Priority:\n");
    printf("Process\tBurst Time\tPriority\n");
    for(i = 0; i < 5; i++) {
        printf("%s\t%d\t\t%d\n", p[i].name, p[i].burstTime, p[i].priority);
    }
    printf("\n");

    //sort based on burst time
    qsort(p, 5, sizeof(struct Process), compareBurstTime);

    //print after sorting based on burst time
    printf("Processes After Sorting Based on Burst Time:\n");
    printf("Process\tBurst Time\tPriority\n");
    for(i = 0; i < 5; i++) {
        printf("%s\t%d\t\t%d\n", p[i].name, p[i].burstTime, p[i].priority);
    }
    printf("\n");

    //FCFS
    printf("FCFS Scheduling Algorithm Output:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < 5; i++) {
        if(i == 0) {
            totalWaitingTime += 0;
        }
        else {
            totalWaitingTime += p[i-1].burstTime;
        }
        totalTurnaroundTime += p[i].burstTime;
        printf("%s\t%d\t\t%d\t\t%d\n", p[i].name, p[i].burstTime, totalWaitingTime, totalTurnaroundTime);
    }
    averageWaitingTime = (float)totalWaitingTime / 5;
    averageTurnaroundTime = (float)totalTurnaroundTime / 5;
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n\n", averageTurnaroundTime);

    //SJF
    printf("SJF Scheduling Algorithm Output:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    totalWaitingTime = 0;
    totalTurnaroundTime = 0;
    for(i = 0; i < 5; i++) {
        totalWaitingTime += l;
        l += p[i].burstTime;
        totalTurnaroundTime += l;
        printf("%s\t%d\t\t%d\t\t%d\n", p[i].name, p[i].burstTime, totalWaitingTime, totalTurnaroundTime);
    }
    averageWaitingTime = (float)totalWaitingTime / 5;
    averageTurnaroundTime = (float)totalTurnaroundTime / 5;
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n\n", averageTurnaroundTime);

    //Priority
    printf("Priority Scheduling Algorithm Output:\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    totalWaitingTime = 0;
    totalTurnaroundTime = 0;
    for(i = 0; i < 5; i++) {
        for(j = i+1; j < 5; j++) {
            if(p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for(i = 0; i < 5; i++) {
        totalWaitingTime += m;
        m += p[i].burstTime;
        totalTurnaroundTime += m;
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", p[i].name, p[i].burstTime, p[i].priority, totalWaitingTime, totalTurnaroundTime);
    }
    averageWaitingTime = (float)totalWaitingTime / 5;
    averageTurnaroundTime = (float)totalTurnaroundTime / 5;
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n\n", averageTurnaroundTime);

    return 0;
}