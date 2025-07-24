//FormAI DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>

int main() {
  printf("Welcome to the Task Scheduler program!\n");

  // Initialize task list
  char tasks[10][50] = {"Task A", "Task B", "Task C", "Task D", "Task E", "Task F", "Task G", "Task H", "Task I", "Task J"};

  // Initialize task priority
  int priorities[10] = {5, 3, 2, 7, 9, 8, 1, 4, 6, 10};

  // Initialize task time estimates (in minutes)
  int timeEstimates[10] = {30, 45, 20, 60, 90, 75, 15, 25, 50, 120};

  // Initialize task completion status
  int taskComplete[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  // Initialize current time
  int currentTime = 0;

  // Loop until all tasks are complete
  while (1) {
    // Print current time
    printf("Current Time: %d minutes\n", currentTime);

    // Find highest priority incomplete task
    int i;
    int highestPriority = -1;
    int currentTask = -1;
    for (i = 0; i < 10; i++) {
      if (!taskComplete[i] && priorities[i] > highestPriority) {
        highestPriority = priorities[i];
        currentTask = i;
      }
    }

    // If no incomplete tasks left, end program
    if (currentTask == -1) {
      printf("All tasks complete!\n");
      break;
    }

    // Print information about current task
    printf("Current Task: %s\n", tasks[currentTask]);
    printf("Priority: %d\n", priorities[currentTask]);
    printf("Time Estimate: %d minutes\n", timeEstimates[currentTask]);

    // Simulate working on task
    int timeRemaining = timeEstimates[currentTask];
    while (timeRemaining > 0) {
      // Wait 1 minute
      sleep(1);

      // Update time remaining
      timeRemaining--;

      // Update current time
      currentTime++;

      // Print status update
      printf("Time Remaining: %d minutes\n", timeRemaining);
    }

    // Mark task as complete
    taskComplete[currentTask] = 1;

    // Print task completion message
    printf("Task %s complete!\n", tasks[currentTask]);
  }

  return 0;
}