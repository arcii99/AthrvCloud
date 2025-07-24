//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // for sleep() function

int main() {
    // Initialize traffic light variables
    bool redLight = true, yellowLight = false, greenLight = false;
    // Loop infinitely
    while (true) {
        // Display current traffic light status
        printf("Red Light: %d, Yellow Light: %d, Green Light: %d\n", redLight, yellowLight, greenLight);
        // Delay execution for 3 seconds
        sleep(3);
        if (redLight) {
            // Switch from red to green
            redLight = false;
            yellowLight = true;
        } else if (yellowLight) {
            // Switch from yellow to green
            yellowLight = false;
            greenLight = true;
        } else if (greenLight) {
            // Switch from green to red
            greenLight = false;
            redLight = true;
        }
    }
    return 0;
}