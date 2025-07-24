//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main(){
  int current_color = RED;

  while(1){
    switch(current_color){
      case RED:
        printf("Red Light\n");
        sleep(10); //Red light duration
        current_color = GREEN;
        break;

      case YELLOW:
        printf("Yellow Light\n");
        sleep(2); //Yellow light duration
        current_color = RED;
        break;

      case GREEN:
        printf("Green Light\n"); 
        sleep(15); //Green light duration
        current_color = YELLOW;
        break;
    }
  } 

  return 0;
}