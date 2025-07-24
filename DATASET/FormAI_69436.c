//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
//This is a traffic light controller program written by Claude Shannon style

//Declare necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

//Define global variables for traffic lights
bool green1 = true;
bool yellow1 = false;
bool red1 = false;
bool green2 = false;
bool yellow2 = false;
bool red2 = true;

//Function to switch lights
void switch_lights(bool *green, bool *yellow, bool *red) {
    *green = false;
    *yellow = true;
    *red = false;
    sleep(2);
    *yellow = false;
    *red = true;
    sleep(2);
    *green = true;
    *red = false;
}

//Main function of program
int main() {
    srand(time(NULL));
    int random_num;
    printf("Starting traffic light simulation...\n\n");
    //Run simulation for 60 seconds
    for(int i=0; i<=60; i++) {
        random_num = (rand() % 10) + 1;
        //If random number is odd, switch lights for Traffic Light 1
        if(random_num % 2 == 1) {
            printf("Traffic Light 1: ");
            switch_lights(&green1, &yellow1, &red1);
        }
        //If random number is even, switch lights for Traffic Light 2
        else {
            printf("Traffic Light 2: ");
            switch_lights(&green2, &yellow2, &red2);
        }
        printf("\n");
        sleep(1);
    }
    printf("\nTraffic light simulation ended.\n");

    return 0;
}