//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main(){
    int red_light = 10, yellow_light = 3, green_light = 8;
    char current_color = 'r'; // red

    printf("Traffic Light Controller initialized!\n");

    while(1){ // infinite loop to keep the program running
        printf("Current light: %c\n", current_color);

        if(current_color == 'r'){
            printf("Red light on for %d seconds\n", red_light);
            sleep(red_light); // pause the program execution for given seconds
            current_color = 'y'; // switch to yellow light
        }
        else if(current_color == 'y'){
            printf("Yellow light on for %d seconds\n", yellow_light);
            sleep(yellow_light); // pause the program execution for given seconds
            current_color = 'g'; // switch to green light
        }
        else if(current_color == 'g'){
            printf("Green light on for %d seconds\n", green_light);
            sleep(green_light); // pause the program execution for given seconds
            current_color = 'r'; // switch to red light
        }
    }

    return 0;
}