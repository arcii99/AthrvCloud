//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

// A task struct to hold process info
struct Task {
  int pid; // Unique process ID
  int arrival_time; // Time arrived in the queue
  int burst_time; // Time required to complete the task
  int wait_time; // Time spent waiting in the queue
  int turnaround_time; // Time taken from arrival to completion
};

// Calculates priority of a task for HRRN algorithm
float calculate_priority(struct Task task, int current_time) {
  return (float)(task.wait_time + task.burst_time) / task.burst_time;
}

// Updates wait time of all tasks in the queue
void update_wait_time(struct Task tasks[], int n, int current_time) {
  for (int i = 0; i < n; i++) {
    if (tasks[i].arrival_time <= current_time && tasks[i].burst_time > 0) {
      tasks[i].wait_time++;
    }
  }
}

int main() {

  // Initialize task queue
  struct Task task_queue[MAX_TASKS] = {
    {1, 0, 5, 0}, // pid, arrival_time, burst_time, wait_time
    {2, 1, 3, 0},
    {3, 2, 8, 0},
    {4, 3, 6, 0},
    {5, 4, 4, 0},
  };
  int num_tasks = 5;

  // Initialize variables for HRRN algorithm
  int current_time = 0;
  struct Task current_task = task_queue[0];
  int total_wait_time = 0;
  int total_turnaround_time = 0;

  // Execute tasks in the queue
  while (num_tasks > 0) {

    // Find task with highest HRRN priority that has not completed
    int highest_priority_index = -1;
    float highest_priority = -1;
    for (int i = 0; i < num_tasks; i++) {
      if (task_queue[i].burst_time > 0) {
        float priority = calculate_priority(task_queue[i], current_time);
        if (priority > highest_priority) {
          highest_priority = priority;
          highest_priority_index = i;
        }
      }
    }

    // Execute current task for one time unit
    current_task = task_queue[highest_priority_index];
    current_task.burst_time--;
    current_time++;

    // Update wait time of all tasks in the queue
    update_wait_time(task_queue, num_tasks, current_time);

    // If current task has completed, calculate turnaround time and remove from queue
    if (current_task.burst_time == 0) {
      current_task.turnaround_time = current_time - current_task.arrival_time;
      total_wait_time += current_task.wait_time;
      total_turnaround_time += current_task.turnaround_time;
      for (int i = highest_priority_index; i < num_tasks - 1; i++) {
        task_queue[i] = task_queue[i + 1];
      }
      num_tasks--;
    }
  }

  // Print average wait and turnaround times
  printf("Average wait time: %0.2f\n", (float)total_wait_time / (float)num_tasks);
  printf("Average turnaround time: %0.2f\n", (float)total_turnaround_time / (float)num_tasks);

  return 0;
}