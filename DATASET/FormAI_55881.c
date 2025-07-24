//FormAI DATASET v1.0 Category: Task Scheduler ; Style: cheerful
/* Welcome to the Happy Task Scheduler! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task1(void){
  printf("Hooray! Task 1 has been completed!\n");
}

void task2(void){
  printf("Woohoo! Task 2 has been completed!\n");
}

void task3(void){
  printf("Yippee! Task 3 has been completed!\n");
}

int main(void){

  /* Set up task schedule */
  srand(time(NULL)); // Seed random number generator
  int interval1 = rand() % 5 + 1; // Generate random interval for task 1 (between 1 and 5 seconds)
  int interval2 = rand() % 5 + 1; // Generate random interval for task 2 (between 1 and 5 seconds)
  int interval3 = rand() % 5 + 1; // Generate random interval for task 3 (between 1 and 5 seconds)

  printf("Task 1 will run every %d seconds.\n", interval1);
  printf("Task 2 will run every %d seconds.\n", interval2);
  printf("Task 3 will run every %d seconds.\n", interval3);

  /* Start running tasks */
  while(1){
    for(int i = 0; i < 10; i++){ // Run tasks 10 times (for demonstration purposes)

      int rand_num = rand() % 3 + 1; // Generate random number between 1 and 3

      switch(rand_num){
        case 1:
          task1();
          sleep(interval1);
          break;
        case 2:
          task2();
          sleep(interval2);
          break;
        case 3:
          task3();
          sleep(interval3);
          break;
        default:
          printf("Oops, something went wrong!\n");
          break;
      }
    }
    printf("Tasks have been completed 10 times. Press any key to continue...\n");
    getchar(); // Pause program until user presses a key
  }

  return 0;
}