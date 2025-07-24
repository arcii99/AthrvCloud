//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  time_t now = time(NULL); // get current time
  char *timeString = ctime(&now); // convert time to a string

  printf("Current time: %s", timeString);

  // define task structs
  struct Task {
    char *name;
    int priority;
    int duration;
    int deadline;
  } task1 = {"Task A", 3, 5, now + 10}, // task with 10 second deadline
    task2 = {"Task B", 1, 10, now + 20}, // task with 20 second deadline
    task3 = {"Task C", 2, 15, now + 30}; // task with 30 second deadline

  // array of task structs
  struct Task tasks[] = {task1, task2, task3};
  int numOfTasks = sizeof(tasks) / sizeof(struct Task);

  // run tasks with scheduler
  printf("Running Tasks:\n");
  for (int i = 0; i < numOfTasks; i++) {
    printf("%s\n", tasks[i].name);
    time_t startTime = time(NULL);
    int secondsLeft = tasks[i].duration;
    while (secondsLeft > 0) {
      time_t currentTime = time(NULL);
      double timeElapsed = difftime(currentTime, startTime);
      if (timeElapsed >= 1) { // 1 second has passed
        secondsLeft--;
        printf("%d seconds left for %s\n", secondsLeft, tasks[i].name);
        startTime = time(NULL);
      }
      if (currentTime > tasks[i].deadline) { // task missed deadline
        printf("%s missed deadline\n", tasks[i].name);
        break; // exit loop early
      }
    }
  }

  printf("\nAll tasks complete\n");

  return 0;
}