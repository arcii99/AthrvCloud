//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define BUTTON 3

int currentColor = RED;
int secondsToWait = 5;
int buttonPressed = 0;

void changeColor() {
    switch(currentColor) {
        case RED:
            currentColor = GREEN;
            secondsToWait = 10;
            break;
        case YELLOW:
            currentColor = RED;
            secondsToWait = 5;
            break;
        case GREEN:
            currentColor = YELLOW;
            secondsToWait = 2;
            break;
    }
}

void buttonInterrupt() {
    buttonPressed = 1;
}

int main() {
    while(1) {
        // Check for button press
        if(buttonPressed) {
            buttonPressed = 0;
            // If we are currently on red light, turn it green
            if(currentColor == RED) {
                printf("Button pressed, changing to green light\n");
                currentColor = GREEN;
                secondsToWait = 10;
            }
        }
        
        // Check which light to activate
        if(currentColor == RED) {
            printf("RED\n");
            sleep(secondsToWait);
            changeColor();
        } else if(currentColor == YELLOW) {
            printf("YELLOW\n");
            sleep(secondsToWait);
            changeColor();
        } else if(currentColor == GREEN) {
            printf("GREEN\n");
            sleep(secondsToWait);
            changeColor();
        } else {
            printf("BUTTON\n");
            sleep(1);
            buttonInterrupt();
        }
    }
    return 0;
}