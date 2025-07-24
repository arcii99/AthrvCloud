//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include<stdio.h>
#include<unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main(){

  int status[3] = {0}; //initial status of traffic lights(0=off, 1=on)
  int green_time = 10; //green light on time in sec
  int yellow_time = 3; //yellow light on time in sec
  int red_time = 10; //red light on time in sec

  while(1){

    //RED LIGHT
    if(status[RED] == 0){
      printf("RED light is ON.\n");
      status[RED] = 1;
      sleep(red_time);
    }

    //YELLOW LIGHT
    else if(status[YELLOW] == 0){
      printf("YELLOW light is ON.\n");
      status[RED] = 0;
      status[YELLOW] = 1;
      sleep(yellow_time);
    }

    //GREEN LIGHT
    else if(status[GREEN] == 0){
      printf("GREEN light is ON.\n");
      status[GREEN] = 1;
      status[YELLOW] = 0;
      sleep(green_time);
    }

    //YELLOW LIGHT (from GREEN)
    else if(status[YELLOW] == 0){
      printf("YELLOW light is ON.\n");
      status[GREEN] = 0;
      status[YELLOW] = 1;
      sleep(yellow_time);
    }
  }
  return 0;
}