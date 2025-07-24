//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define NUM_TASKS 5

void task1(int);
void task2(int);
void task3(int);
void task4(int);
void task5(int);

void *task_functions[NUM_TASKS] = { task1, task2, task3, task4, task5 };
int task_execution_times[NUM_TASKS] = { 6, 2, 8, 3, 4 };

volatile int current_task = 0;

void task_manager(int signo) {
  if(signo == SIGALRM) {
    alarm(task_execution_times[current_task]);
    (*(void (*)()) task_functions[current_task])(current_task);
    current_task = (current_task + 1) % NUM_TASKS;
  }
}

int main() {
  int i;
  
  signal(SIGALRM, task_manager);
  
  struct itimerval timer;
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  timer.it_value.tv_sec = 1;
  timer.it_value.tv_usec = 0;
  
  setitimer(ITIMER_REAL, &timer, NULL);
  
  while(1) {
    // Keep the main program running
  }
  return 0;
}

void task1(int task_id) {
  printf("Executing Task %d for %d seconds.\n", task_id, task_execution_times[task_id]);
}

void task2(int task_id) {
  printf("Executing Task %d for %d seconds.\n", task_id, task_execution_times[task_id]);
}

void task3(int task_id) {
  printf("Executing Task %d for %d seconds.\n", task_id, task_execution_times[task_id]);
}

void task4(int task_id) {
  printf("Executing Task %d for %d seconds.\n", task_id, task_execution_times[task_id]);
}

void task5(int task_id) {
  printf("Executing Task %d for %d seconds.\n", task_id, task_execution_times[task_id]);
}