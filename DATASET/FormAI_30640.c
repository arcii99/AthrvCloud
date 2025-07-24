//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int task_time[10];
  int priority[10];
  int i, j;
  int sum = 0;

  // Generate random time for each task
  for (i = 0; i < 10; i++) {
    task_time[i] = rand() % 10 + 1;
    sum += task_time[i];
  }

  // Generate random priority for each task
  for (i = 0; i < 10; i++) {
    priority[i] = rand() % 5 + 1;
  }

  // Sort tasks based on priority using bubble sort
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9-i; j++) {
      if (priority[j] > priority[j+1]) {
        // Swap priority
        int temp = priority[j];
        priority[j] = priority[j+1];
        priority[j+1] = temp;

        // Swap task time
        temp = task_time[j];
        task_time[j] = task_time[j+1];
        task_time[j+1] = temp;
      }
    }
  }

  // Execute tasks in order of priority
  int time_elapsed = 0;
  for (i = 0; i < 10; i++) {
    printf("Executing task %d with priority %d for %d seconds\n", i+1, priority[i], task_time[i]);
    time_elapsed += task_time[i];
  }

  printf("All tasks completed in %d seconds\n", time_elapsed);

  return 0;
}