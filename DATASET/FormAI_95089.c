//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
// This program implements a simple task scheduler which allows users to schedule tasks with a specific time interval.
// The scheduling algorithm used in this program is similar to the one used in Unix systems, designed by Ken Thompson.
// The maximum number of tasks that can be scheduled is 10.
// Written by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 50

typedef struct {
  char name[MAX_TASK_NAME_LENGTH];
  int interval; // in seconds
  time_t last_run;
  void (*func)();
  int active; // 1 if active, 0 if inactive
} task;

task tasks[MAX_TASKS];
int num_tasks = 0;

time_t current_time; // current time

// Function to add a new task
void add_task(char name[], int interval, void (*func)()) {
  if (num_tasks >= MAX_TASKS) {
    printf("Unable to add task. Maximum number of tasks reached.\n");
    return;
  }

  task new_task;
  strcpy(new_task.name, name);
  new_task.interval = interval;
  new_task.last_run = current_time;
  new_task.func = func;
  new_task.active = 1;

  tasks[num_tasks++] = new_task;

  printf("New task added: %s\n", name);
}

// Function to remove a task
void remove_task(char name[]) {
  int i;
  for (i = 0; i < num_tasks; i++) {
    if (tasks[i].active && strcmp(tasks[i].name, name) == 0) {
      tasks[i].active = 0;
      printf("Task removed: %s\n", name);
      return;
    }
  }

  printf("Unable to remove task. Task not found.\n");
}

// Function to run all scheduled tasks
void run_tasks() {
  int i;
  for (i = 0; i < num_tasks; i++) {
    if (tasks[i].active && difftime(current_time, tasks[i].last_run) >= tasks[i].interval) {
      tasks[i].last_run = current_time;
      printf("Task %s running.\n", tasks[i].name);
      tasks[i].func();
    }
  }
}

// Example task function
void task1() {
  printf("Task 1 executed.\n");
}

// Example task function
void task2() {
  printf("Task 2 executed.\n");
}

// Function to get the current time
void get_current_time() {
  current_time = time(NULL);
}

// Main function
int main() {
  get_current_time();
  
  add_task("Task 1", 2, task1); // Add example task 1
  add_task("Task 2", 5, task2); // Add example task 2

  while (1) {
    get_current_time();
    run_tasks();
    sleep(1); // Sleep for 1 second
  }
  return 0;
}