//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include<stdio.h>

int main(){
    int n, i, j, sum = 0, pos = 0;
    float avg = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], p[n], pos_bt[n];
    printf("Enter burst time for each process:\n");
    for(i=0;i<n;i++){
        printf("Process %d: ", i+1);
        scanf("%d", &bt[i]);
        pos_bt[i] = bt[i];
        p[i] = i+1;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(pos_bt[i] > pos_bt[j]){
                int temp = pos_bt[i];
                pos_bt[i] = pos_bt[j];
                pos_bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i=1;i<n;i++){
        sum += pos_bt[i-1];
        wt[i] = sum;
    }
    for(i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        avg += tat[i];
    }
    avg /= n;
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Turnaround Time: %.2f", avg);
    return 0;
}