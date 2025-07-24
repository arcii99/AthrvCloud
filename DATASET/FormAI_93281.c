//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

void delay(int seconds){
  sleep(seconds);
}

int main(){

  int state = RED;
  int time_elapsed = 0;

  while(1){

    if(state == RED){
      printf("RED LIGHT\n");

      delay(5); //Red light stays on for 5 seconds

      state = GREEN; //Switch to green light
      time_elapsed = 0;
    }
    else if(state == GREEN){
      printf("GREEN LIGHT\n");

      delay(8); //Green light stays on for 8 seconds

      state = YELLOW; //Switch to yellow light
      time_elapsed = 0;
    }
    else{ //state == YELLOW
      printf("YELLOW LIGHT\n");

      delay(3); //Yellow light stays on for 3 seconds

      state = RED; //Switch to red light
      time_elapsed = 0;
    }

    time_elapsed += 1;

    if(time_elapsed >= 10){ //Switch to emergency mode after 10 cycles

      //Randomly select a new state
      srand(time(NULL));
      int new_state = rand() % 3;

      state = new_state;

      //Reset time elapsed
      time_elapsed = 0;
    }

  }

  return 0;
}