//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main(){
    int currentState = RED;
    int greenCounter = 0;
    int yellowCounter = 0;
    int redCounter = 0;

    srand(time(NULL));

    printf("Traffic Light Controller Program\n");

    while(1){
        if(currentState == RED){
            printf("RED Light On\n");
            greenCounter = 0;
            yellowCounter = 0;
            redCounter++;
            if(redCounter == 3){ // Change to GREEN after 3 cycles
                currentState = GREEN;
                redCounter = 0;
            }
        }
        else if(currentState == GREEN){
            printf("GREEN Light On\n");
            redCounter = 0;
            yellowCounter = 0;
            greenCounter++;
            if(greenCounter == 10){ // Change to YELLOW after 10 seconds
                currentState = YELLOW;
                greenCounter = 0;
            }
        }
        else if(currentState == YELLOW){
            printf("YELLOW Light On\n");
            redCounter = 0;
            greenCounter = 0;
            yellowCounter++;
            if(yellowCounter == 3){ // Change to RED after 3 seconds
                currentState = RED; 
                yellowCounter = 0;
            }
        }
        int delay = rand() % 4 + 1; // Random delay between 1-4 seconds
        printf("Delay: %d seconds\n", delay);
        sleep(delay);
    }

    return 0;
}