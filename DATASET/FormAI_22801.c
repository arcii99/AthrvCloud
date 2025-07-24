//FormAI DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Task Struct
typedef struct Task {
  int id;
  char description[100];
  int priority;
} Task;

// Define Scheduler Struct
typedef struct Scheduler {
  int numTasks;
  Task tasks[100];
} Scheduler;

// Function to Add Task
void addTask(Scheduler* scheduler, Task task) {
  // Check if Scheduler is Full
  if (scheduler->numTasks >= 100) {
    printf("Sorry, Scheduler is Full!\n");
  }
  else {
    scheduler->tasks[scheduler->numTasks] = task;
    scheduler->numTasks++;
    printf("Task Added Successfully!\n");
  }
}

// Function to Remove Task
void removeTask(Scheduler* scheduler, int id) {
  int index = -1;
  // Find Task Index
  for (int i = 0; i < scheduler->numTasks; i++) {
    if (scheduler->tasks[i].id == id) {
      index = i;
      break;
    }
  }
  // Remove Task
  if (index != -1) {
    for (int i = index; i < scheduler->numTasks - 1; i++) {
      scheduler->tasks[i] = scheduler->tasks[i + 1];
    }
    scheduler->numTasks--;
    printf("Task Removed Successfully!\n");
  }
  else {
    printf("Sorry, Task ID Not Found!\n");
  }
}

// Function to Display Tasks
void displayTasks(Scheduler* scheduler) {
  if (scheduler->numTasks == 0) {
    printf("No Tasks to Display!\n");
  }
  else {
    printf("ID\tPriority\tDescription\n");
    for (int i = 0; i < scheduler->numTasks; i++) {
      printf("%d\t%d\t\t%s\n", scheduler->tasks[i].id, scheduler->tasks[i].priority, scheduler->tasks[i].description);
    }
  }
}

// Main Function
int main() {
  // Initialize Scheduler
  Scheduler scheduler = {0};
  
  // Add Tasks
  Task task1 = {1, "Complete Happy Project", 1};
  addTask(&scheduler, task1);
  Task task2 = {2, "Buy Groceries", 2};
  addTask(&scheduler, task2);
  Task task3 = {3, "Go for a Walk", 3};
  addTask(&scheduler, task3);
  
  // Display Tasks
  printf("Initial Tasks:\n");
  displayTasks(&scheduler);
  
  // Remove Task
  printf("\nRemoving Task with ID 2...\n");
  removeTask(&scheduler, 2);
  
  // Display Tasks
  printf("\nUpdated Tasks:\n");
  displayTasks(&scheduler);
  
  return 0;
}