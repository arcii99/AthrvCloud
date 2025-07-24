//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include<stdio.h>
enum COLORS {RED, YELLOW, GREEN};

int main(){
    int current_state = RED;  //start with red light
    int count = 0;
    while(count < 20){         //run for 20 cycles
        switch(current_state){
            case RED:
                printf("Red light: Stop!\n");
                sleep(3);       //wait for 3 seconds in red state
                current_state = GREEN;
                break;

            case YELLOW:
                printf("Yellow light: Get ready to stop!\n");
                sleep(1);       //wait for 1 second in yellow state
                current_state = RED;
                break;

            case GREEN:
                printf("Green light: Go!\n");
                sleep(5);       //wait for 5 seconds in green state
                current_state = YELLOW;
                break;
        }
        count++;
    }
    return 0;
}