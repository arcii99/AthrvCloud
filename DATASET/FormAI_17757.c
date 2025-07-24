//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10  // Number of processes
#define MAX_TIME_QUANTUM 5  // Maximum time quantum for Round Robin scheduling
#define MIN_ARRIVAL_TIME 0
#define MAX_ARRIVAL_TIME 10

typedef struct process {
   int pid;  // Process ID
   int arrival_time;  // Arrival Time
   int burst_time;  // Burst Time
   int waiting_time;  // Waiting Time
   int turnaround_time;  // Turnaround Time
   int remaining_time;  // Remaining Time
   int response_time;  // Response Time
} Process;

// Function to create processes with random arrival and burst times
void create_processes(Process *processes) {
   srand(time(NULL));
   int i;
   for (i = 0; i < MAX_PROCESSES; i++) {
      processes[i].pid = i + 1;
      processes[i].arrival_time = rand() % (MAX_ARRIVAL_TIME - MIN_ARRIVAL_TIME + 1) + MIN_ARRIVAL_TIME;
      processes[i].burst_time = rand() % MAX_TIME_QUANTUM + 1;  // Max CPU burst time is the time quantum
      processes[i].remaining_time = processes[i].burst_time;
      processes[i].response_time = -1;
   }
}

// Function to print the table of the processes with their respective scheduling time
void print_table(Process *processes, int *scheduling_times) {
   int i;
   printf("\n\nProcess Table:\n");
   printf("  +----+----------------+-------------+--------------+---------------+----------------+--------------+\n");
   printf("  | PID| Arrival Time   | Burst Time  | Scheduling T | Turnaround T  | Waiting Time  | Response Time|\n");
   printf("  +----+----------------+-------------+--------------+---------------+----------------+--------------+\n");
   for (i = 0; i < MAX_PROCESSES; i++) {
      printf("  | %2d | %5d          | %4d        | %5d        | %5d         | %5d         | %5d        |\n", 
             processes[i].pid,
             processes[i].arrival_time,
             processes[i].burst_time,
             scheduling_times[i],
             processes[i].turnaround_time,
             processes[i].waiting_time,
             processes[i].response_time);
   }
   printf("  +----+----------------+-------------+--------------+---------------+----------------+--------------+\n");
}

// Function to run the First-Come-First-Serve (FCFS) Algorithm
void FCFS(Process *processes, int *scheduling_times) {
   int i, j;
   int total_waiting_time = 0;
   int total_turnaround_time = 0;
   for (i = 0; i < MAX_PROCESSES; i++) {
      for (j = 0; j < processes[i].burst_time; j++) {
         scheduling_times[i] = j + processes[i].arrival_time;
      }
      processes[i].waiting_time = scheduling_times[i] - processes[i].arrival_time;
      processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
      total_waiting_time += processes[i].waiting_time;
      total_turnaround_time += processes[i].turnaround_time;
   }
   print_table(processes, scheduling_times);
   printf("\n\nAverage Waiting Time: %f", (float) total_waiting_time / MAX_PROCESSES);
   printf("\nAverage Turnaround Time: %f", (float) total_turnaround_time / MAX_PROCESSES);
}

// Function to run the Shortest-Job-First (SJF) Algorithm
void SJF(Process *processes, int *scheduling_times) {
   int i, j, min_burst_time_idx, time_elapsed = 0;
   int total_waiting_time = 0;
   int total_turnaround_time = 0;
   Process temp_process;
   for (i = 0; i < MAX_PROCESSES; i++) {
      min_burst_time_idx = i;
      for (j = i + 1; j < MAX_PROCESSES; j++) {
         if (processes[j].burst_time < processes[min_burst_time_idx].burst_time) {
            min_burst_time_idx = j;
         }
      }
      temp_process = processes[i];
      processes[i] = processes[min_burst_time_idx];
      processes[min_burst_time_idx] = temp_process;
   }
   for (i = 0; i < MAX_PROCESSES; i++) {
      for (j = 0; j < processes[i].burst_time; j++) {
         scheduling_times[i] = j + time_elapsed;
      }
      processes[i].waiting_time = scheduling_times[i] - processes[i].arrival_time;
      processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
      time_elapsed += processes[i].burst_time;
      total_waiting_time += processes[i].waiting_time;
      total_turnaround_time += processes[i].turnaround_time;
   }
   print_table(processes, scheduling_times);
   printf("\n\nAverage Waiting Time: %f", (float) total_waiting_time / MAX_PROCESSES);
   printf("\nAverage Turnaround Time: %f", (float) total_turnaround_time / MAX_PROCESSES);
}

// Function to run the Round Robin (RR) Algorithm
void RR(Process *processes, int *scheduling_times) {
   int i, j, time_elapsed = 0, time_quantum;
   int total_waiting_time = 0;
   int total_turnaround_time = 0;
   for (i = 0; i < MAX_PROCESSES; i++) {
      processes[i].waiting_time = 0;
      processes[i].turnaround_time = 0;
      processes[i].response_time = -1;
   }
   printf("\nEnter the Time Quantum: ");
   scanf("%d", &time_quantum);
   int completed_processes = 0;
   while (completed_processes < MAX_PROCESSES) {
      for (i = 0; i < MAX_PROCESSES; i++) {
         if (processes[i].remaining_time > 0) {
            if (processes[i].response_time == -1) {
               processes[i].response_time = time_elapsed;
            }
            scheduling_times[i] = time_elapsed;
            if (processes[i].remaining_time <= time_quantum) {
               time_elapsed += processes[i].remaining_time;
               processes[i].remaining_time = 0;
               processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
               completed_processes++;
               total_waiting_time += processes[i].waiting_time;
               total_turnaround_time += processes[i].turnaround_time;
            } else {
               time_elapsed += time_quantum;
               processes[i].remaining_time -= time_quantum;
            }
         }
      }
   }
   print_table(processes, scheduling_times);
   printf("\n\nAverage Waiting Time: %f", (float) total_waiting_time / MAX_PROCESSES);
   printf("\nAverage Turnaround Time: %f", (float) total_turnaround_time / MAX_PROCESSES);
}

int main() {
   int option;
   Process processes[MAX_PROCESSES];
   int scheduling_times[MAX_PROCESSES];
   create_processes(processes);
   printf("Select a CPU Scheduling Algorithm:\n");
   printf("1. First-Come-First-Serve (FCFS)\n");
   printf("2. Shortest-Job-First (SJF)\n");
   printf("3. Round Robin (RR)\n");
   scanf("%d", &option);
   switch(option) {
      case 1:
         FCFS(processes, scheduling_times);
         break;
      case 2:
         SJF(processes, scheduling_times);
         break;
      case 3:
         RR(processes, scheduling_times);
         break;
      default:
         printf("\nInvalid Option!\n");
         break;
   }
   return 0;
}