//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ada Lovelace
#include <stdio.h>
#include <unistd.h>

int main() {
    int seconds = 0;
    char color;
    
    while(1) {
        seconds += 1;

        // Red light
        if (seconds >= 0 && seconds <= 10) {
            color = 'R';
        }
        // Yellow light
        else if (seconds > 10 && seconds <= 15) {
            color = 'Y';
        }
        // Green light
        else if (seconds > 15 && seconds <= 25) {
            color = 'G';
        }
        // Yellow light
        else if (seconds > 25 && seconds <= 30) {
            color = 'Y';
        }
        // Reset timer and go back to red light
        else {
            seconds = 0;
            color = 'R';
        }
        
        // Print the current light color
        printf("The traffic light is %c\n", color);
        
        // Wait 1 second before switching to the next light
        sleep(1);
    }
    
    return 0;
}