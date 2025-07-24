//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_PROCESSES 100
#define QUANTUM_TIME 5

struct Process {
  char name[25];
  int arrival_time;
  int burst_time;
  int remaining_time;
};

typedef struct Process Process;

void run(Process process_list[], int num_processes) {
  int current_time = 0, completed_processes = 0, current_process = -1,
      waiting_time[num_processes], turnaround_time[num_processes];

  memset(waiting_time, 0, sizeof(waiting_time));
  memset(turnaround_time, 0, sizeof(turnaround_time));

  // Round-robin iteration
  while (completed_processes < num_processes) {
    current_process = (current_process + 1) % num_processes;

    // Check if the process has arrived
    if (process_list[current_process].arrival_time > current_time)
      continue;

    // Proceed to the next process if current process is completed
    if (process_list[current_process].remaining_time == 0) {
      completed_processes++;
      continue;
    }

    // Simulate quantum time
    for (int i = 0; i < QUANTUM_TIME && process_list[current_process].remaining_time > 0; i++) {
      printf("Sherlock Holmes: Running process %s for 1 unit of time...\n", process_list[current_process].name);
      process_list[current_process].remaining_time--;
    }

    // Update waiting and turnaround time
    if (process_list[current_process].remaining_time > 0) {
      printf("Sherlock Holmes: Process %s is being interrupted...\n", process_list[current_process].name);
    }
    else {
      waiting_time[current_process] = current_time - process_list[current_process].arrival_time - process_list[current_process].burst_time;
      turnaround_time[current_process] = current_time - process_list[current_process].arrival_time;
    }

    // Keep track of the current time
    current_time++;
  }

  // Print the report
  printf("\nSherlock Holmes: CPU Scheduling Report\n");
  printf("-------------------------------------\n");
  printf("%-10s %-10s %-10s %-10s\n", "Process", "Arrival", "Burst", "Waiting");
  for (int i = 0; i < num_processes; i++) {
    printf("%-10s %-10d %-10d %-10d\n", process_list[i].name, process_list[i].arrival_time, process_list[i].burst_time, waiting_time[i]);
  }

  printf("\nAverage waiting time: %.2f\n", (double) (current_time - waiting_time[0]) / num_processes);
  printf("Average turnaround time: %.2f\n", (double) (current_time - turnaround_time[0]) / num_processes);
}

int main() {
  // Define the process list
  Process process_list[] = {
      {"P1", 0, 6, 6},
      {"P2", 1, 4, 4},
      {"P3", 2, 2, 2},
      {"P4", 3, 7, 7},
      {"P5", 7, 5, 5}
  };
  int num_processes = sizeof(process_list) / sizeof(Process);

  // Report the process list
  printf("Sherlock Holmes: CPU Scheduling Simulation\n");
  printf("-----------------------------------------\n\n");
  printf("The following processes will be simulated:\n");
  for (int i = 0; i < num_processes; i++) {
    printf("Process %s - Arrival Time: %d, Burst Time: %d\n", process_list[i].name, process_list[i].arrival_time, process_list[i].burst_time);
  }

  // Execute the program
  printf("\nSherlock Holmes: Starting CPU simulation with Round Robin algorithm...\n\n");
  run(process_list, num_processes);

  return 0;
}