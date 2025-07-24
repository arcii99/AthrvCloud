//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int green_duration, yellow_duration, red_duration; // duration of each light
  int timer; // timer for each light
  int current_light; // current light state: 0 for red, 1 for yellow, 2 for green

    srand(time(NULL)); // seeding rand() for real random numbers

    while (1) { // infinite loop for the traffic lights
        // set initial values for each light's duration, timer, and current state
        green_duration = rand() % 30 + 50;
        yellow_duration = 3;
        red_duration = rand() % 30 + 50;
        timer = 0;
        current_light = 0; // start with red light

        printf("Red light for %d seconds\n", red_duration);

        // loop through each light state and display the appropriate message
        while (timer < red_duration + yellow_duration + green_duration) {
            switch (current_light) { 
                case 0: // red light
                    if (timer == red_duration) {
                        printf("Yellow light for %d seconds\n", yellow_duration);
                        current_light = 1; // change to yellow light after red light duration
                        timer++;
                    }
                    else {
                        printf("Red light\n");
                        timer++;
                    }
                    break;
                case 1: // yellow light
                    if (timer == red_duration + yellow_duration) {
                        printf("Green light for %d seconds\n", green_duration);
                        current_light = 2; // change to green light after yellow light duration
                        timer++;
                    }
                    else {
                        printf("Yellow light\n");
                        timer++;
                    }
                    break;
                case 2: // green light
                    if (timer == red_duration + yellow_duration + green_duration) {
                        printf("Red light for %d seconds\n", red_duration);
                        current_light = 0; // change to red light after green light duration
                        timer++;
                    }
                    else {
                        printf("Green light\n");
                        timer++;
                    }
                    break;
            }
        }
    }

    return 0;
}