//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL)); // initialize random seed

  int r, y, g; // declare variables for red, yellow and green traffic lights
  int counter = 0; // initialize counter to 0
  int flag = 0; // initialize the flag to 0

  printf("\n*** Welcome to the Surreal Traffic Light Controller Program ***\n\n");

  while(1) { // infinite loop

    counter++; // increment the counter on each run

    r = rand() % 10 + 1; // set the red traffic light randomly between 1 and 10 seconds
    y = rand() % 5 + 1; // set the yellow traffic light randomly between 1 and 5 seconds
    g = rand() % 15 + 1; // set the green traffic light randomly between 1 and 15 seconds

    printf("\nRun #%d\n", counter);

    if(flag == 0) { // if the flag is 0
      printf("Red Light: %d seconds\n", r); // print the red light duration
      sleep(r); // wait for the red light duration
      flag = 1; // set the flag to 1
    }

    if(flag == 1) { // if the flag is 1
      printf("Green Light: %d seconds\n", g); // print the green light duration
      sleep(g); // wait for the green light duration
      flag = 2; // set the flag to 2
    }

    if(flag == 2) { // if the flag is 2
      printf("Yellow Light: %d seconds\n", y); // print the yellow light duration
      sleep(y); // wait for the yellow light duration
      flag = 0; // set the flag to 0
    }
  }

  return 0; // end program
}