//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

/* The number of processes to be scheduled */
#define PROCESS_NUM 5

/* The semaphore for mutual exclusion */
sem_t mutex;

/* The structure representing a process */
struct process {
  int pid;
  int arrival_time;
  int burst_time;
  int priority;
  int wait_time;
  int turnaround_time;
};

/* The array representing the processes */
struct process processes[PROCESS_NUM];

/* The function for the First-Come, First-Served (FCFS) algorithm */
void *FCFS(void *arg) {
  int i, j;
  struct process temp_process;
  
  for (i = 1; i < PROCESS_NUM; i++) {
    for (j = 0; j < PROCESS_NUM-i; j++) {
      if (processes[j].arrival_time > processes[j+1].arrival_time) {
        temp_process = processes[j];
        processes[j] = processes[j+1];
        processes[j+1] = temp_process;
      }
    }
  }
  
  int curr_time = 0;
  for (i = 0; i < PROCESS_NUM; i++) {
    curr_time += processes[i].burst_time;
    processes[i].turnaround_time = curr_time - processes[i].arrival_time;
    processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
  }
  
  sem_post(&mutex);
  pthread_exit(NULL);
}

/* The function for the Round Robin (RR) algorithm */
void *RR(void *arg) {
  int i, j, time_quantum = 2;
  struct process temp_process;
  
  for (i = 1; i < PROCESS_NUM; i++) {
    for (j = 0; j < PROCESS_NUM-i; j++) {
      if (processes[j].arrival_time > processes[j+1].arrival_time) {
        temp_process = processes[j];
        processes[j] = processes[j+1];
        processes[j+1] = temp_process;
      }
    }
  }
  
  int curr_time = 0;
  int remaining_time[PROCESS_NUM];
  for (i = 0; i < PROCESS_NUM; i++) {
    remaining_time[i] = processes[i].burst_time;
  }
  
  while (1) {
    int done = 1;
    for (i = 0; i < PROCESS_NUM; i++) {
      if (remaining_time[i] > 0) {
        done = 0;
        if (remaining_time[i] > time_quantum) {
          curr_time += time_quantum;
          remaining_time[i] -= time_quantum;
        } else {
          curr_time += remaining_time[i];
          processes[i].turnaround_time = curr_time - processes[i].arrival_time;
          processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
          remaining_time[i] = 0;
        }
      }
    }
    if (done == 1) {
      break;
    }
  }
  
  sem_post(&mutex);
  pthread_exit(NULL);
}

/* The function for the Priority (PR) algorithm */
void *PR(void *arg) {
  int i, j;
  struct process temp_process;
  
  for (i = 1; i < PROCESS_NUM; i++) {
    for (j = 0; j < PROCESS_NUM-i; j++) {
      if (processes[j].priority > processes[j+1].priority) {
        temp_process = processes[j];
        processes[j] = processes[j+1];
        processes[j+1] = temp_process;
      }
    }
  }
  
  int curr_time = 0;
  for (i = 0; i < PROCESS_NUM; i++) {
    curr_time += processes[i].burst_time;
    processes[i].turnaround_time = curr_time - processes[i].arrival_time;
    processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
  }
  
  sem_post(&mutex);
  pthread_exit(NULL);
}

int main() {
  pthread_t fcfs_tid, rr_tid, pr_tid;
  
  /* Initialize the semaphore for mutual exclusion */
  sem_init(&mutex, 0, 0);
  
  /* Generate random process arrival times, burst times, and priorities */
  srand(time(NULL));
  int i;
  for (i = 0; i < PROCESS_NUM; i++) {
    processes[i].pid = i+1;
    processes[i].arrival_time = rand()%10;
    processes[i].burst_time = rand()%10 + 1;
    processes[i].priority = rand()%10 + 1;
  }
  
  /* Print the generated processes */
  printf("Processes:\n");
  printf("PID   AT   BT   PR\n");
  for (i = 0; i < PROCESS_NUM; i++) {
    printf("%-5d%-5d%-5d%-5d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
  }
  
  /* Create threads for each scheduling algorithm */
  pthread_create(&fcfs_tid, NULL, FCFS, NULL);
  pthread_create(&rr_tid, NULL, RR, NULL);
  pthread_create(&pr_tid, NULL, PR, NULL);
  
  /* Wait for all threads to finish */
  sem_wait(&mutex);
  sem_wait(&mutex);
  sem_wait(&mutex);
  
  /* Print the results */
  printf("\nResults:\n");
  printf("PID   WT   TAT\n");
  for (i = 0; i < PROCESS_NUM; i++) {
    printf("%-5d%-5d%-5d\n", processes[i].pid, processes[i].wait_time, processes[i].turnaround_time);
  }
  
  /* Destroy the semaphore for mutual exclusion */
  sem_destroy(&mutex);
  
  return 0;
}