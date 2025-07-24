//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUANTUM 5 // time quantum for Round Robin algorithm

// process structure
typedef struct Process {
    char name[10]; // process name
    int burstTime; // burst time of the process
    int arrivalTime; // arrival time of the process
    int waitingTime; // waiting time of the process
    int turnaroundTime; // turnaround time of the process
    int remainingTime; // remaining time of the process
} Process;

// function to display the process table
void displayProcessTable(Process *processes, int n) {
  int i;

  printf("\nProcess Table:\n");
  printf("+--------+------------+--------------+----------------+----------------+------------------+\n");
  printf("| Name   | Burst Time | Arrival Time | Waiting Time   | Turnaround Time | Remaining Time   |\n");
  printf("+--------+------------+--------------+----------------+----------------+------------------+\n");

  for (i = 0; i < n; i++) {
    printf("| %s\t | %d\t   | %d\t      | %d\t\t| %d\t\t | %d\t\t   |\n", processes[i].name, processes[i].burstTime, 
           processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnaroundTime, processes[i].remainingTime);
  }

  printf("+--------+------------+--------------+----------------+----------------+------------------+\n\n");
}

// function for First Come First Serve (FCFS) algorithm
void FCFS(Process *processes, int n) {
  int i, currentTime = processes[0].arrivalTime;

  for (i = 0; i < n; i++) {
    if(currentTime < processes[i].arrivalTime) {
      currentTime = processes[i].arrivalTime;
    }

    processes[i].waitingTime = currentTime - processes[i].arrivalTime;
    processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    currentTime += processes[i].burstTime;
  }

  displayProcessTable(processes, n);
}

// function for Round Robin algorithm
void roundRobin(Process *processes, int n) {
  int i, timeLeft, completed, timeElapsed = 0;
  Process *queue, temp;

  queue = (Process*) malloc(sizeof(Process) * n);

  for(i = 0; i < n; i++) {
    queue[i] = processes[i];
    queue[i].remainingTime = queue[i].burstTime;
  }

  while(completed < n) {
    for(i = 0; i < n; i++) {
      if(queue[i].remainingTime > 0) {
        if(queue[i].remainingTime > QUANTUM) {
          timeElapsed += QUANTUM;
          queue[i].remainingTime -= QUANTUM;
        } else {
          timeElapsed += queue[i].remainingTime;
          queue[i].waitingTime = timeElapsed - queue[i].burstTime - queue[i].arrivalTime;
          queue[i].turnaroundTime = timeElapsed - queue[i].arrivalTime;
          queue[i].remainingTime = 0;
          completed++;
        }
      }
    }

    // sort the queue by arrival time
    for(i = 0; i < n; i++) {
      if(queue[i].remainingTime == 0) {
        temp = queue[i];
        queue[i] = queue[completed];
        queue[completed] = temp;
        completed++;

      }
    }
  }

  for(i = 0; i < n; i++) {
    processes[i] = queue[i];
  }

  displayProcessTable(processes, n);
}

// main function
int main() {
  int n, choice, i;
  Process *processes;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  processes = (Process*) malloc(sizeof(Process) * n);

  for(i = 0; i < n; i++) {
    printf("Enter process name, burst time and arrival time for process %d: ", i+1);
    scanf("%s%d%d", processes[i].name, &processes[i].burstTime, &processes[i].arrivalTime);
  }

  printf("\nChoose a scheduling algorithm:\n");
  printf("1) First Come First Serve (FCFS)\n");
  printf("2) Round Robin\n");

  scanf("%d", &choice);

  switch(choice) {
    case 1: 
      FCFS(processes, n);
      break;

    case 2:
      roundRobin(processes, n);
      break;

    default:
      printf("Invalid choice!\n");
      break;
  }

  free(processes);

  return 0;
}