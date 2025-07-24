//FormAI DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_TIME 5
#define MAX_PRIORITY 5

typedef struct {
    int task_id;
    int priority;
    int time_left;
} Task;

int num_tasks = 0;
Task task_queue[MAX_TASKS];

int generate_task_id() {
  static int current_id = 0;
  return ++current_id;
}

void generate_tasks() {
  srand(time(NULL));

  int i, random_time, random_priority;

  for (i = 0; i < MAX_TASKS; i++) {
    random_time = (rand() % MAX_TASK_TIME) + 1;
    random_priority = (rand() % MAX_PRIORITY) + 1;

    task_queue[i].task_id = generate_task_id();
    task_queue[i].priority = random_priority;
    task_queue[i].time_left = random_time;

    num_tasks++;
  }
}

void print_tasks() {
  int i;
  printf("TASK QUEUE:\n");
  for (i = 0; i < num_tasks; i++) {
    printf("Task ID: %d, Priority: %d, Time Left: %d\n", 
      task_queue[i].task_id, task_queue[i].priority, task_queue[i].time_left);
  }
}

void execute_task(Task task) {
  printf("Executing task %d\n", task.task_id);
  while (task.time_left > 0) {
    printf("Time left for task %d: %d seconds\n", task.task_id, task.time_left);
    task.time_left--;
    sleep(1);
  }
  printf("Task %d has been completed!\n", task.task_id);
}

void schedule_tasks() {
  int i, j;
  Task temp;

  for (i = 0; i < num_tasks; i++) {
    for (j = i+1; j < num_tasks; j++) {
      if (task_queue[i].priority < task_queue[j].priority) {
        temp = task_queue[i];
        task_queue[i] = task_queue[j];
        task_queue[j] = temp;
      }
    }
  }

  printf("SCHEDULING:\n");
  for (i = 0; i < num_tasks; i++) {
    execute_task(task_queue[i]);
  }
}

int main() {
  generate_tasks();
  print_tasks();
  schedule_tasks();

  return 0;
}