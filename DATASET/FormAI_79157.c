//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define ARMED 1
#define DISARMED 0
#define MAX_HEIGHT 200
#define MIN_HEIGHT 0

int main(){
    int height = MIN_HEIGHT;
    int armed = DISARMED;

    printf("Welcome to the Drone Remote Control Program\n\n");
    printf("Press 'A' to arm the drone\n");
    printf("Press 'D' to disarm the drone\n");
    printf("Use the arrow keys to control the height of the drone\n\n");

    while(1){
        char c = getchar();
        // Handle arming and disarming
        if(c == 'a' || c == 'A'){
            armed = ARMED;
            printf("Drone armed\n\n");
        }
        else if(c == 'd' || c == 'D'){
            armed = DISARMED;
            printf("Drone disarmed\n\n");
        }
        // Handle height changes
        else if(c == 27){ // arrow key escape sequences
            getchar(); // Ignore the [
            switch(getchar()){
                case 'A': // Up arrow
                    if(height < MAX_HEIGHT) height++;
                    break;
                case 'B': // Down arrow
                    if(height > MIN_HEIGHT) height--;
                    break;
            }
            printf("Height: %d meters\n", height);
        }

        // Check if the drone has exceeded its height limit
        if(height > MAX_HEIGHT){
            printf("Height limit reached, drone landing.\n");
            armed == DISARMED;
            break;
        }

        // Check if the drone has been disarmed
        if(armed == DISARMED){
            printf("Drone disarmed, landing.\n");
            break;
        }
    }

    return 0;
}