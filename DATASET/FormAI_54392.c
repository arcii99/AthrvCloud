//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>

struct Process {
    int pid;            // process ID
    int bt;             // burst time
    int art;            // arrival time
    int rem_bt;         // remaining burst time
};

void findWaitingTime(struct Process proc[], int n, int wt[], int quantum) {
    int i, t, rt[n];
    for (i = 0; i < n; i++)
        rt[i] = proc[i].bt;
    t = 0; 
    while (1) {
        int done = 1; 
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0; 
                if (rt[i] > quantum) {
                    t += quantum; 
                    rt[i] -= quantum;
                }
                else {
                    t += rt[i]; 
                    wt[i] = t - proc[i].bt;
                    rt[i] = 0; 
                }
            }
        }
        if (done == 1)
            break; 
    }
}

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    int i;
    for (i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findAvgTime(struct Process proc[], int n, int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0, i;
    findWaitingTime(proc, n, wt, quantum);
    findTurnAroundTime(proc, n, wt, tat);
    printf("Processes  Burst Time  Waiting Time  Turn-Around Time\n");
    for (i=0; i<n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("Average Waiting Time = %f\n", (float)total_wt / (float)n);
    printf("Average Turn-Around Time = %f", (float)total_tat / (float)n);
}

int main() {
    struct Process proc[] = {{1, 10, 0, 0}, {2, 5, 2, 0}, {3, 8, 1, 0}};
    int n = sizeof proc / sizeof proc[0];
    int quantum = 2;
    findAvgTime(proc, n, quantum);
    return 0;
}