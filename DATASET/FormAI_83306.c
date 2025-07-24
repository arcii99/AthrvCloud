//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int main() {

    int state = GREEN; // initialize state variable to green
    int counter = 0; // initialize counter variable to 0
    bool emergency = false; // initialize emergency variable to false
    
    while (true) { // infinite loop
        
        if (state == GREEN) { // green light state
            
            if (counter == 30) { // if time on green light elapsed
                if (!emergency) { // if no emergency vehicles approaching
                    state = YELLOW; // change state to yellow
                    counter = 0; // reset counter variable
                } else { // if emergency vehicles approaching
                    state = RED; // change state to red
                    counter = 0; // reset counter variable
                    emergency = false; // reset emergency variable
                }
            } else { // if time on green light not elapsed
                printf("Green light. Time remaining: %d seconds.\n", 30 - counter);
                counter++; // increment counter variable
            }
            
        } else if (state == YELLOW) { // yellow light state
            
            if (counter == 5) { // if time on yellow light elapsed
                state = RED; // change state to red
                counter = 0; // reset counter variable
            } else { // if time on yellow light not elapsed
                printf("Yellow light. Time remaining: %d seconds.\n", 5 - counter);
                counter++; // increment counter variable
            }

        } else if (state == RED) { // red light state
            
            if (counter == 25) { // if time on red light elapsed
                state = GREEN; // change state to green
                counter = 0; // reset counter variable
            } else { // if time on red light not elapsed
                printf("Red light. Time remaining: %d seconds.\n", 25 - counter);
                counter++; // increment counter variable
            }
            
            if (rand() % 100 < 2) { // simulate emergency vehicle arrival with 2% chance
                printf("EMERGENCY VEHICLE APPROACHING. LIGHTS CHANGING TO ALLOW PASSAGE.\n");
                emergency = true; // set emergency variable to true
            }
        }
    }
    
    return 0;
}