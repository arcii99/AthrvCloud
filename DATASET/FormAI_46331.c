//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Process {
  int pid;        // process id
  int arrival;    // arrival time
  int burst;      // cpu burst time
  int remaining;  // remaining time to complete execution
};

void round_robin(struct Process *processes, int n, int time_quantum) {
  int time = 0;
  int total_burst = 0;

  // calculate total cpu burst time
  for(int i = 0; i < n; i++) {
    total_burst = total_burst + processes[i].burst;
    processes[i].remaining = processes[i].burst;
  }

  // simulate cpu scheduling
  while(total_burst > 0) {
    for(int i = 0; i < n; i++) {
      if(processes[i].remaining <= time_quantum && processes[i].remaining > 0) {
        total_burst = total_burst - processes[i].remaining;
        time = time + processes[i].remaining;
        printf("Process %d executed from %d to %d\n", processes[i].pid, time - processes[i].remaining, time);
        processes[i].remaining = 0;
      }
      else if(processes[i].remaining > 0) {
        processes[i].remaining = processes[i].remaining - time_quantum;
        total_burst = total_burst - time_quantum;
        time = time + time_quantum;
        printf("Process %d executed from %d to %d\n", processes[i].pid, time - time_quantum, time);        
      }
    }
  }
}

int main() {
  // sample process data
  struct Process processes[] = {
    {1, 0, 5},
    {2, 1, 4},
    {3, 2, 2},
    {4, 3, 1}
  };

  int n = sizeof(processes) / sizeof(processes[0]);
  int time_quantum = 2;

  round_robin(processes, n, time_quantum);

  return 0;
}