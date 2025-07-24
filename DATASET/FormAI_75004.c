//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Definition of a task
struct Task {
  int id; // Unique identifier
  int priority; // Priority of the task (1-10)
  int time_to_execute; // Time to execute the task
};

// Structure for the Task Scheduler
struct TaskScheduler {
  int current_task_id; // Id of the currently executing task
  int current_task_time_left; // Time left for the currently executing task
  struct Task task_list[10]; // Array of tasks (max 10)
};

// Function to initialize the Task Scheduler with some tasks
void init_task_scheduler(struct TaskScheduler *ts) {
  // Task 1
  ts->task_list[0].id = 1;
  ts->task_list[0].priority = 3;
  ts->task_list[0].time_to_execute = 5;

  // Task 2
  ts->task_list[1].id = 2;
  ts->task_list[1].priority = 8;
  ts->task_list[1].time_to_execute = 3;

  // Task 3
  ts->task_list[2].id = 3;
  ts->task_list[2].priority = 5;
  ts->task_list[2].time_to_execute = 10;

  // Task 4
  ts->task_list[3].id = 4;
  ts->task_list[3].priority = 2;
  ts->task_list[3].time_to_execute = 7;
}

// Function to print the state of the task scheduler
void print_task_scheduler(struct TaskScheduler *ts) {
  printf("Current task id: %d\n", ts->current_task_id);
  printf("Current task time left: %d\n", ts->current_task_time_left);
  printf("Task list:\n");
  for (int i = 0; i < 4; i++) {
    printf("Task id: %d, priority: %d, time to execute: %d\n", ts->task_list[i].id, ts->task_list[i].priority, ts->task_list[i].time_to_execute);
  }
}

// Function to find the highest priority task in the task list
int find_highest_priority_task(struct TaskScheduler *ts) {
  int highest_priority = 0;
  int highest_priority_index = -1;
  for (int i = 0; i < 4; i++) {
    if (ts->task_list[i].priority > highest_priority && ts->task_list[i].time_to_execute > 0) {
      highest_priority = ts->task_list[i].priority;
      highest_priority_index = i;
    }
  }
  return highest_priority_index;
}

// Function to execute the next task in the task list
void execute_next_task(struct TaskScheduler *ts) {
  int next_task_index = find_highest_priority_task(ts);
  if (next_task_index == -1) {
    printf("No tasks left to execute.\n");
    return;
  }
  ts->current_task_id = ts->task_list[next_task_index].id;
  ts->current_task_time_left = ts->task_list[next_task_index].time_to_execute;
  printf("Executing task %d ...\n", ts->current_task_id);
  ts->task_list[next_task_index].time_to_execute = 0;
}

// Function to decrement the time left for the current task
void decrement_current_task_time_left(struct TaskScheduler *ts) {
  if (ts->current_task_id != 0) {
    ts->current_task_time_left--;
    printf("Time left for task %d: %d\n", ts->current_task_id, ts->current_task_time_left);
    if (ts->current_task_time_left == 0) {
      printf("Task %d completed.\n", ts->current_task_id);
      ts->current_task_id = 0;
    }
  }
}

int main() {
  struct TaskScheduler ts;
  ts.current_task_id = 0;
  ts.current_task_time_left = 0;
  init_task_scheduler(&ts);
  print_task_scheduler(&ts);

  while (ts.current_task_id != 0 || find_highest_priority_task(&ts) != -1) {
    if (ts.current_task_id == 0) {
      execute_next_task(&ts);
    }
    decrement_current_task_time_left(&ts);
  }

  printf("All tasks completed.\n");
  return 0;
}