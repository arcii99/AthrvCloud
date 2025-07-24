//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  printf("Welcome to the Mind-Bending Task Scheduler!\n");
  printf("Get ready for a unique task scheduling experience...\n");

  srand(time(NULL)); // Seed the random number generator with current time
  int num_tasks = rand() % 6 + 5; // Generate random number of tasks from 5 to 10
  int task_durations[num_tasks];
  int total_duration = 0;

  printf("Generating %d tasks with varying durations...\n", num_tasks);

  for (int i = 0; i < num_tasks; i++) {
    int duration = rand() % 11 + 1; // Generate random duration from 1 to 11
    task_durations[i] = duration;
    total_duration += duration;
    printf("Task %d: %d seconds\n", i+1, duration);
  }

  printf("Total duration of all tasks: %d seconds\n", total_duration);

  printf("Starting task scheduler...\n");

  int time_elapsed = 0;
  int current_task = 1;

  while (current_task <= num_tasks) {
    printf("Time elapsed: %d seconds\n", time_elapsed);
    printf("Current task: %d\n", current_task);

    if (task_durations[current_task-1] == 1) {
      printf("Task %d will finish in 1 second.\n", current_task);
    } else {
      printf("Task %d will finish in %d seconds.\n", current_task, task_durations[current_task-1]);
    }

    task_durations[current_task-1]--; // Decrement duration of current task
    time_elapsed++; // Increment time elapsed

    if (task_durations[current_task-1] == 0) {
      printf("Task %d complete!\n", current_task);
      current_task++; // Move on to next task
    }
  }

  printf("All tasks complete! Total time elapsed: %d seconds\n", time_elapsed);

  return 0;
}