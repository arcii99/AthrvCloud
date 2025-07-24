//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: synchronous
#include <stdio.h>

enum colors {RED, YELLOW, GREEN}; // Enumeration to represent different colors

int main() {
    enum colors curr_color = RED; // Starting the traffic light with RED color
    
    while(1) { // Infinite loop to keep the program running
        
        // Switch statement to change the traffic light colors
        switch(curr_color) {
            case RED:
                printf("Stop!\n");
                sleep(5); // Traffic light remains red for 5 seconds
                curr_color = GREEN;
                break;
            case YELLOW:
                printf("Prepare to stop!\n");
                sleep(2); // Traffic light remains yellow for 2 seconds
                curr_color = RED;
                break;
            case GREEN:
                printf("Go!\n");
                sleep(10); // Traffic light remains green for 10 seconds
                curr_color = YELLOW;
                break;
            default:
                printf("Invalid color!\n");
                break;
        }
    }
    
    return 0;
}