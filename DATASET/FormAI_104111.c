//FormAI DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5
#define MAX_PRIORITY 10

typedef struct task {
    int id;
    int priority;
    time_t start_time;
    int duration;
} task_t;

task_t task_queue[MAX_TASKS]; // declaring a queue of tasks

int head = 0; // the index of the first element in the queue
int tail = 0; // the index where the next element would be inserted

void schedule_task(int priority, int duration) {
  if (tail >= MAX_TASKS) {
    printf("Task queue is full.\n");
    return;
  }
  
  task_t new_task;
  new_task.id = tail + 1; // assigning a unique id to the task
  new_task.priority = priority;
  new_task.start_time = time(NULL);
  new_task.duration = duration;
  
  // adding the new task to the end of the queue
  task_queue[tail] = new_task;
  tail++;
  
  printf("Task with priority %d and duration %d added to queue with id %d.\n",
         priority, duration, new_task.id);
}

void execute_task(task_t task) {
  printf("Executing task with id %d and duration %d.\n", task.id, task.duration);
  time_t current_time = time(NULL);
  
  // busy loop for the duration of the task
  while (difftime(time(NULL), current_time) < task.duration) {}
  
  printf("Task with id %d completed at %s", task.id, ctime(&current_time));
}

void run_scheduler() {
  while (head < tail) {
    task_t highest_priority_task = task_queue[head];
    
    // finding the task with the highest priority in the queue
    for (int i = head + 1; i < tail; i++) {
      if (task_queue[i].priority > highest_priority_task.priority) {
        highest_priority_task = task_queue[i];
      }
    }
    
    // executing the highest priority task
    execute_task(highest_priority_task);
    
    // removing the task from the queue
    for (int i = head; i < tail - 1; i++) {
      task_queue[i] = task_queue[i + 1];
    }
    tail--;
  }
  
  printf("All tasks completed!\n");
}

int main() {
  srand(time(NULL)); // seeding the random number generator
  
  // adding random tasks to the queue
  for (int i = 0; i < MAX_TASKS; i++) {
    int priority = rand() % MAX_PRIORITY;
    int duration = (rand() % 10 + 1) * 1000; // duration in milliseconds
    schedule_task(priority, duration);
  }
  
  run_scheduler();
  
  return 0;
}