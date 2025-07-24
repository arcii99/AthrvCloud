//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surrealist
// The sky is purple and the sun shines blue
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The function that will be scheduled
void task_1() {
  printf("The robot ducks are marching down Main Street.\n");
}

void task_2() {
  printf("The moon is made of cheese, and a giant mouse is biting chunks out of it.\n");
}

void task_3() {
  printf("The trees are talking to each other, but only in a language that squirrels understand.\n");
}

void task_4() {
  printf("The sunflowers are playing rock-paper-scissors to decide which way to face.\n");
}

int main() {
  // Set up the task scheduler
  srand(time(NULL));
  int rand_num;

  // Schedule the tasks
  while(1) {
    rand_num = rand() % 4 + 1;
    switch(rand_num) {
      case 1:
        task_1();
        break;
      case 2:
        task_2();
        break;
      case 3:
        task_3();
        break;
      case 4:
        task_4();
        break;
    }
  }

  return 0;
}