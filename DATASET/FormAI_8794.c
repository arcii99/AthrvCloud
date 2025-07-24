//FormAI DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include<stdio.h>

void task1() {
  printf("Task 1 is executed!\n");
}

void task2() {
  printf("Task 2 is executed!\n");
}

void task3() {
  printf("Task 3 is executed!\n");
}

int main() {
  int task_id;

  printf("Enter the number of tasks to schedule: ");
  scanf("%d", &task_id);

  // Declare function pointer array to hold all the tasks
  void (*task_functions[task_id])();

  // Initialize function pointer array with task functions
  task_functions[0] = task1;
  task_functions[1] = task2;
  task_functions[2] = task3;

  // Schedule tasks using a loop
  printf("\nScheduled tasks:\n");
  for(int i=0; i<task_id; i++) {
    (*task_functions[i])();   // Call the task function
  }

  return 0;
}