//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: rigorous
#include <stdio.h>

//function to switch lights and print the current state
void switchLights(int redTime, int greenTime, int yellowTime, int initialLight){
    int counter = 0; 
    int lightIndex = initialLight;
    while(counter < 10){
        switch(lightIndex){
            case 0:
                printf("Light is Green\n");
                counter += greenTime;
                break;
            case 1:
                printf("Light is Yellow\n");
                counter += yellowTime;
                break;
            case 2:
                printf("Light is Red\n");
                counter += redTime;
        }
        lightIndex = (lightIndex + 1) % 3;
    }
}

//main function
int main(){
    //initialize variables
    int redTime = 5;
    int greenTime = 10;
    int yellowTime = 2;
    int initialLight = 0;

    //call switchLights function 
    switchLights(redTime, greenTime, yellowTime, initialLight);

    return 0;
}