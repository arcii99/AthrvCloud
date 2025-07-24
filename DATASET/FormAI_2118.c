//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Surrealist CPU Scheduling Algorithm */

int main() {

  int num_processes = 5;
  int burst_times[5] = {3, 7, 4, 2, 5};
  int priority[5] = {2, 1, 5, 3, 4};
  int time_quantum = 2;
  int remaining_time[5] = {0};
  int running_time = 0;
  int current_process = 0;
  int i;

  printf("Welcome to the Surrealist CPU Scheduling Algorithm!\n\n");

  printf("Starting processes:\n");
  for (i = 0; i < num_processes; i++) {
    printf("Process %d - Burst Time: %d - Priority: %d\n", i+1, burst_times[i], priority[i]);
  }

  printf("\n");

  printf("Running...\n\n");

  while (1) {

    /* Check if all processes have completed */
    int completed = 1;
    for (i = 0; i < num_processes; i++) {
      if (remaining_time[i] > 0) {
        completed = 0;
      }
    }
    if (completed == 1) {
      break;
    }

    /* Check if current process has completed */
    if (remaining_time[current_process] == 0) {
      current_process = (current_process + 1) % num_processes;
    }

    printf("Running Process %d...\n", current_process+1);
    remaining_time[current_process] = remaining_time[current_process] - time_quantum;
    running_time = running_time + time_quantum;

    /* Check priority of remaining processes and switch if necessary */
    for (i = 0; i < num_processes; i++) {
      if (i != current_process && remaining_time[i] > 0 && priority[i] > priority[current_process]) {
        printf("Switching from Process %d to Process %d due to higher priority.\n", current_process+1, i+1);
        current_process = i;
      }
    }
  }

  printf("\n");

  printf("All processes completed after %d seconds.\n", running_time);

  return 0;
}