//FormAI DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // A romance-themed task scheduler
  printf("Hello my love, welcome to our task scheduler!\n");
  printf("I prepared a special list of tasks for us to do together today.\n");

  // Creating a list of romantic tasks
  char tasks[5][50] = {"Cook a candle-lit dinner together",
                       "Take a walk on the beach",
                       "Watch a romantic movie together",
                       "Write each other love letters",
                       "Dance together to our favorite song"};

  // Initializing the random seed
  srand(time(0));

  // Selecting a random task from the list
  int task_index = rand() % 5;

  // Displaying the selected task
  printf("Our task for today is: %s\n", tasks[task_index]);

  // Asking if the task was completed
  printf("My love, have we completed the task yet? (Y/N)\n");
  char completed_task;
  scanf(" %c", &completed_task);

  // Checking if the task was completed
  if (completed_task == 'Y' || completed_task == 'y') {
    // If the task was completed, end the program
    printf("You make me so happy my love. Let's do another task soon.\n");
  } else {
    // If the task was not completed, come up with a backup plan
    printf("Oh no! Let's come up with a new plan.\n");
    printf("What is something else we can do together?\n");
    char new_task[50];
    scanf(" %[^\n]", new_task);
    printf("Great plan my love! Let's do %s instead.\n", new_task);
  }

  return 0;
}