//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>

int main() {
  int n, burst_time[20], wait_time[20], turnaround_time[20], avg_wait_time = 0, avg_turnaround_time = 0, i, j, temp;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter the burst time for each process: ");
  for(i = 0; i < n; i++) {
    scanf("%d", &burst_time[i]);
  }
  //Sort the burst time in ascending order using Bubble Sort
  for(i = 0; i < n-1; i++) {
    for(j = 0; j < n-i-1; j++) {
      if(burst_time[j] > burst_time[j+1]) {
        temp = burst_time[j];
        burst_time[j] = burst_time[j+1];
        burst_time[j+1] = temp;
      }
    }
  }
  wait_time[0] = 0;
  // Calculate Waiting Time
  for(i = 1; i < n; i++) {
    wait_time[i] = 0;
    for(j = 0; j < i; j++) {
      wait_time[i] += burst_time[j];
    }
  }
  // Calculate Turnaround Time
  for(i = 0; i < n; i++) {
    turnaround_time[i] = burst_time[i] + wait_time[i];
    avg_wait_time += wait_time[i];
    avg_turnaround_time += turnaround_time[i];
  }
  avg_wait_time /= n;
  avg_turnaround_time /= n;
  printf("\nProcess\t  Burst Time \tWaiting Time\tTurnaround Time\n");
  for(i = 0; i < n; i++) {
    printf("   P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turnaround_time[i]);
  }
  printf("\nAverage Waiting Time = %d", avg_wait_time);
  printf("\nAverage Turnaround Time = %d", avg_turnaround_time);
  return 0;
}