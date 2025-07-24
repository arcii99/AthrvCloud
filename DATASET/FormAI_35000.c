//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include<stdio.h>

void FCFS(int bt[], int n){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wt[0] = 0;
    for(int i = 1; i < n; i++){
        wt[i] = bt[i - 1] + wt[i - 1];
    }
    printf("Processes   Burst Time   Waiting Time   Turnaround Time\n");
    for(int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d           %d             %d                %d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_wt/(float)n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat/(float)n);
    return;
}

void SJF(int bt[], int n){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int temp_bt[n];
    for(int i = 0; i < n; i++){
        temp_bt[i] = bt[i];
    }
    int complete = 0, t = 0, minm = 9999, shortest = 0, finish_time;
    while(complete != n){
        for(int j = 0; j < n; j++){
            if((temp_bt[j] < minm) && (temp_bt[j] > 0) && (t >= finish_time)){
                minm = temp_bt[j];
                shortest = j;
            }
        }
        temp_bt[shortest] = 0;
        finish_time = t + minm;
        t = finish_time;
        wt[shortest] = t - bt[shortest];
        if(wt[shortest] < 0) wt[shortest] = 0;
        tat[shortest] = bt[shortest] + wt[shortest];
        total_wt += wt[shortest];
        total_tat += tat[shortest];
        minm = 9999;
        complete++;
    }
    printf("Processes   Burst Time   Waiting Time   Turnaround Time\n");
    for(int i = 0; i < n; i++){
        printf("   %d           %d             %d                %d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_wt/(float)n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat/(float)n);
    return;
}

void RoundRobin(int bt[], int n, int quantum){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int rem_bt[n];
    for(int i = 0; i < n; i++){
        rem_bt[i] = bt[i];
    }
    int t = 0;
    while(1){
        int done = 1;
        for(int i = 0; i < n; i++){
            if(rem_bt[i] > 0){
                done = 0;
                if(rem_bt[i]>quantum){
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    t += rem_bt[i];
                    wt[i] = t - bt[i] - rem_bt[i];
                    if(wt[i] < 0) wt[i] = 0;
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == 1) break;
    }
    for(int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Processes   Burst Time   Waiting Time   Turnaround Time\n");
    for(int i = 0; i < n; i++){
        printf("   %d           %d             %d                %d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_wt/(float)n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat/(float)n);
    return;
}

int main(){
    int n, choice;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n];
    printf("Enter burst time for each process: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &bt[i]);
    }
    printf("Enter the algorithm of your choice:\n1. FCFS\n2. SJF\n3. Round Robin\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            FCFS(bt, n);
            break;
        case 2:
            SJF(bt, n);
            break;
        case 3:
            int quantum;
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            RoundRobin(bt, n, quantum);
            break;
        default:
            printf("Invalid choice! Please enter again.");
            break;
    }
    return 0;
}