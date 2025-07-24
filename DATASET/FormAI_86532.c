//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int state = 0; // initially the traffic light will be in the green state
  int timer = 0; //initializing timer
  srand(time(NULL)); //seeding the random generator with the current time
  int random_time = rand() % 10 + 1; // generates a random time between 1 and 10

  while(1) // loop to keep the traffic light running indefinitely
  {
    if(state==0) // Green traffic light; cars can pass
    {
      printf("Green light on, cars can pass!\n");
      for(timer=0; timer<random_time; timer++){ // count down timer for green light
        printf("Remaining time for green light: %d seconds\n",random_time-timer);
        sleep(1); // delay of 1 second
      }
      state = 1; // change state to yellow
      random_time = rand() % 6 + 1; // generate a new random time for yellow light
    }
    else if(state==1) // yellow traffic light; cars should slow down and prepare to stop
    {
      printf("Yellow light on, cars should slow down and prepare to stop!\n");
      for(timer=0; timer<random_time; timer++){ // count down timer for yellow light
        printf("Remaining time for yellow light: %d seconds\n",random_time-timer);
        sleep(1); // delay of 1 second
      }
      state = 2; // change state to red
      random_time = rand() % 11 + 1; // generate a new random time for red light
    }
    else if(state==2) // red traffic light; cars should stop
    {
      printf("Red light on, cars should stop!\n");
      for(timer=0; timer<random_time; timer++){ // count down timer for red light
        printf("Remaining time for red light: %d seconds\n",random_time-timer);
        sleep(1); // delay of 1 second
      }
      state = 0; // change state to green
      random_time = rand() % 16 + 1; // generate a new random time for green light
    }
  }
  return 0;
}