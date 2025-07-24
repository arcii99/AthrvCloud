//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>

int main() {
    int red = 0; // red light is initially off
    int yellow = 0; // yellow light is initially off
    int green = 1; // green light is initially on
    int countdown = 10; // countdown time for each light is initially set to 10 seconds
    
    printf("Traffic Light Simulation:\n\n");
    
    while (countdown > 0) { // loop until countdown reaches 0
        printf("%s%s%s\n", (red ? "Red " : ""), (yellow ? "Yellow " : ""), (green ? "Green" : "")); // print the current light sequence
        
        if (green && countdown == 5) { // change from green to yellow when countdown reaches 5 seconds
            green = 0;
            yellow = 1;
            printf("Yellow\n"); // print "Yellow" when the light changes
        } else if (yellow && countdown == 2) { // change from yellow to red when countdown reaches 2 seconds
            yellow = 0;
            red = 1;
            printf("Red\n"); // print "Red" when the light changes
        } else if (red && countdown == 10) { // change from red to green when countdown reaches 10 seconds
            red = 0;
            green = 1;
            printf("Green\n"); // print "Green" when the light changes
        }
        
        countdown--; // decrement the countdown timer
    }
    
    printf("\nEnd of Simulation\n"); // print "End of Simulation" when countdown reaches 0
    
    return 0;
}