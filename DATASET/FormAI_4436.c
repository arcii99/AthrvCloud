//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define constants for the different light states
#define RED 0
#define YELLOW 1
#define GREEN 2

//Create a struct to hold the state of each light
typedef struct {
    int red;
    int yellow;
    int green;
} lights;

//Define a function to change the state of the lights
void change_state(lights *state, int red, int yellow, int green) {
    state->red = red;
    state->yellow = yellow;
    state->green = green;
}

int main() {
    lights current_state;
    change_state(&current_state, 1, 0, 0); //Start with the red light on

    //Infinite loop to simulate the traffic light
    while(1) {
        //Print the current state of the traffic light
        printf("Current state: ");
        if(current_state.red) {
            printf("RED");
        } else if(current_state.yellow) {
            printf("YELLOW");
        } else {
            printf("GREEN");
        }
        printf("\n");

        //Delay to simulate time passing
        for(int i=0; i<10000000; i++){}

        //Change the state of the traffic light based on the current state
        if(current_state.red) {
            change_state(&current_state, 0, 1, 0); //Switch to yellow light
        } else if(current_state.yellow) {
            change_state(&current_state, 0, 0, 1); //Switch to green light
        } else {
            change_state(&current_state, 1, 0, 0); //Switch to red light
        }
    }

    return 0;
}