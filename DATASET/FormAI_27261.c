//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>

void fcfs(int bt[], int n) {
  int wt[n], tat[n], total_wt = 0, total_tat = 0;

  // Calculating waiting time for each process
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      wt[i] = 0;
    } else {
      wt[i] = bt[i - 1] + wt[i - 1];
    }
    total_wt += wt[i];
  }

  // Calculating turn around time for each process
  for (int i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    total_tat += tat[i];
  }

  // Displaying result
  printf("FCFS Scheduling\n");
  printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
  }
  printf("Average Waiting Time = %f\n", (float)total_wt / n);
  printf("Average Turnaround Time = %f\n", (float)total_tat / n);
}

int main() {
  int n, bt[100];
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter Burst Time for each process: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &bt[i]);
  }
  fcfs(bt, n);
  return 0;
}