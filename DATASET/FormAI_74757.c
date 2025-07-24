//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

int current_time = 0;
int number_of_processes = 0;
int completed_processes = 0;
int current_process_index = 0;
int waiting_time = 0;
int turnaround_time = 0;
float average_waiting_time;
float average_turnaround_time;

struct Process {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int completion_time;
  int waiting_time;
  int turnaround_time;
};

struct Process processes[MAX_PROCESSES];
struct Process waiting_queue[MAX_PROCESSES];

void add_process(int pid, int arrival_time, int burst_time) {
  struct Process process = {pid, arrival_time, burst_time, burst_time, 0, 0, 0};
  processes[number_of_processes++] = process;
}

void print_greeting() {
  printf("--------------------------------------------\n");
  printf("|         Paranoid CPU Scheduling         |\n");
  printf("--------------------------------------------\n");
}

void print_processes() {
  printf("\n====================Processes====================\n\n");
  printf("| PID | Arrival Time | Burst Time |\n");
  printf("--------------------------------------\n");
  for(int i = 0; i < number_of_processes; i++) {
    printf("| %2d  |      %2d      |     %2d     |\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
  }
  printf("\n");
}

void handle_process_completion() {
  printf("Process %d completed. (Completion Time: %d)\n", waiting_queue[0].pid, current_time);
  waiting_queue[0].completion_time = current_time;
  waiting_queue[0].turnaround_time = waiting_queue[0].completion_time - waiting_queue[0].arrival_time;
  waiting_queue[0].waiting_time = waiting_queue[0].turnaround_time - waiting_queue[0].burst_time;
  turnaround_time += waiting_queue[0].turnaround_time;
  waiting_time += waiting_queue[0].waiting_time;
  completed_processes++;
  for(int i = 0; i < number_of_processes - 1; i++) {
    processes[i] = processes[i+1];
  }
  number_of_processes--;
  for(int i = 0; i < MAX_PROCESSES - 1; i++) {
    waiting_queue[i] = waiting_queue[i+1];
  }
  waiting_queue[MAX_PROCESSES - 1] = (struct Process){0};
}

void handle_process_switch() {
  printf("Process %d switched out. (Time Quantum: %d)\n", waiting_queue[0].pid, TIME_QUANTUM);
  struct Process tmp = waiting_queue[0];
  for(int i = 0; i < MAX_PROCESSES - 1; i++) {
    waiting_queue[i] = waiting_queue[i+1];
  }
  waiting_queue[MAX_PROCESSES - 1] = tmp;
}

void schedule_processes() {
  while(completed_processes < number_of_processes) {
    int flag = 0;
    for(int i = 0; i < number_of_processes; i++) {
      if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
        waiting_queue[number_of_processes - completed_processes - 1] = processes[i];
        for(int j = i; j < number_of_processes - 1; j++) {
          processes[j] = processes[j+1];
        }
        number_of_processes--;
        flag = 1;
      }
    }
    if(flag == 0) {
      current_time++;
      continue;
    }
    while(1) {
      if(waiting_queue[0].remaining_time <= TIME_QUANTUM) {
    current_time += waiting_queue[0].remaining_time;
    waiting_queue[0].remaining_time = 0;
    handle_process_completion();
    break;
      } else {
    current_time += TIME_QUANTUM;
    waiting_queue[0].remaining_time -= TIME_QUANTUM;
    handle_process_switch();
      }
    }
  }
}

void calculate_averages() {
  average_waiting_time = (float) waiting_time / (float) completed_processes;
  average_turnaround_time = (float) turnaround_time / (float) completed_processes;
}

void print_statistics() {
  printf("====================Statistics====================\n\n");
  printf("| PID | Completion Time | Waiting Time | Turnaround Time |\n");
  printf("-----------------------------------------------------\n");
  for(int i = 0; i < completed_processes; i++) {
    printf("| %2d  |        %2d       |      %2d      |         %2d         |\n", waiting_queue[i].pid, waiting_queue[i].completion_time, waiting_queue[i].waiting_time, waiting_queue[i].turnaround_time);
  }
  printf("\n");
  printf("Average waiting time: %.2f\n", average_waiting_time);
  printf("Average turnaround time: %.2f\n\n", average_turnaround_time);
}

int main() {
  add_process(1, 0, 4);
  add_process(2, 1, 3);
  add_process(3, 2, 2);
  add_process(4, 3, 1);
  add_process(5, 4, 5);
  print_greeting();
  print_processes();
  schedule_processes();
  calculate_averages();
  print_statistics();
  return 0;
}