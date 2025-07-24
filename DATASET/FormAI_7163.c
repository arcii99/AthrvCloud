//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hello friend! Let's play around with some CPU scheduling algorithms!\n\n");

  // Process table
  int processes[] = {1, 2, 3, 4, 5};
  int n = sizeof(processes)/sizeof(processes[0]);

  // Burst time of processes
  int burst_time[] = {5, 3, 8, 4, 6};

  // Display input data
  printf("Process ID\tBurst Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\n", processes[i], burst_time[i]);
  }

  // FCFS algorithm
  int completion_time_fcfs = 0;
  for (int i = 0; i < n; i++) {
    completion_time_fcfs += burst_time[i];

    // Display completion time for each process under FCFS
    printf("Process %d completed at time %d under FCFS.\n", processes[i], completion_time_fcfs);
  }

  // SJF algorithm
  int waiting_time_sjf = 0;
  int completion_time_sjf = 0;
  for (int i = 0; i < n; i++) {
    int min_index = i;
    for (int j = i+1; j < n; j++) {
      if (burst_time[j] < burst_time[min_index]) {
        min_index = j;
      }
    }

    // Swap processes[i] and processes[min_index]
    int temp_p = processes[i];
    processes[i] = processes[min_index];
    processes[min_index] = temp_p;

    // Swap burst_time[i] and burst_time[min_index]
    int temp_b = burst_time[i];
    burst_time[i] = burst_time[min_index];
    burst_time[min_index] = temp_b;

    completion_time_sjf += burst_time[i];
    waiting_time_sjf += completion_time_sjf - burst_time[i];

    // Display completion time and waiting time for each process under SJF
    printf("Process %d completed at time %d with waiting time %d under SJF.\n", processes[i], completion_time_sjf, waiting_time_sjf);
  }

  // Round Robin algorithm
  int time_quantum = 2;
  int remaining_burst_time[n];
  for (int i = 0; i < n; i++) {
    remaining_burst_time[i] = burst_time[i];
  }

  int completion_time_rr = 0;
  while (1) {
    int flag = 1;

    for (int i = 0; i < n; i++) {
      if (remaining_burst_time[i] > 0) {
        flag = 0;

        if (remaining_burst_time[i] > time_quantum) {
          completion_time_rr += time_quantum;
          remaining_burst_time[i] -= time_quantum;
        } else {
          completion_time_rr += remaining_burst_time[i];
          remaining_burst_time[i] = 0;

          // Display completion time for each process under round robin
          printf("Process %d completed at time %d under Round Robin.\n", processes[i], completion_time_rr);
        }
      }
    }

    if (flag == 1) {
      break;
    }
  }

  printf("\nThat was fun! All CPU scheduling algorithms completed successfully.");
  return 0;
}