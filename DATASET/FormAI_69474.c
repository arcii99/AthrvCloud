//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
} Process;

int main() {
  int n, i;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  Process* processes = (Process*) malloc(n * sizeof(Process));
  
  printf("Enter the arrival time and burst time of each process:\n");
  for (i = 0; i < n; i++) {
    printf("Process %d: ", i + 1);
    scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    processes[i].remaining_time = processes[i].burst_time;
    processes[i].pid = i + 1;
  }

  // Implement a CPU scheduling algorithm here

  free(processes);
  return 0;
}