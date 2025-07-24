//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task1() {
  printf("Task 1 Executed!\n");
}

void task2() {
  printf("Task 2 Executed!\n");
}

void task3() {
  printf("Task 3 Executed!\n");
}

int main() {
  srand(time(NULL)); // Seed the random number generator

  int task_count = 3; // Number of tasks to execute
  int task_array[task_count]; // Array to hold task execution order

  // Generate random task order
  for (int i = 0; i < task_count; i++) {
    int rand_task = rand() % task_count; // Generate random number from 0 to task_count - 1

    // Loop until unique random number is generated
    while (1) {
      int unique = 1;
      for (int j = 0; j < i; j++) {
        if (task_array[j] == rand_task) { // Check if number already exists in array
          unique = 0;
          break;
        }
      }
      if (unique) { // If number is unique, add to array and break loop
        task_array[i] = rand_task;
        break;
      }
      else { // If number is not unique, generate new random number
        rand_task = rand() % task_count;
      }
    }
  }

  // Execute tasks in generated order
  for (int i = 0; i < task_count; i++) {
    switch (task_array[i]) {
      case 0:
        task1();
        break;
      case 1:
        task2();
        break;
      case 2:
        task3();
        break;
    }
  }

  return 0;
}