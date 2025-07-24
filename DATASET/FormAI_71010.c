//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char color = 'R';  // initializes the traffic light to red
    int i = 0;

    printf("Traffic Light Controller\n\n");

    // loop for 10 cycles
    while (i < 10) {
        printf("Cycle %d:\n", i+1);
        printf("Current color: %c\n\n", color);

        // checks what the current color of the traffic light is and sets the next color accordingly
        if (color == 'R') {
            color = 'G';
        }
        else if (color == 'G') {
            color = 'Y';
        }
        else if (color == 'Y') {
            color = 'R';
        }

        // pauses for 2 seconds before moving on to the next cycle
        system("sleep 2");
        i++;
    }

    printf("Simulation complete.\n");

    return 0;
}