//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

// Function that chooses a random light duration
int random_duration() {
    srand(time(NULL));
    int duration = rand() % 6 + 5;
    return duration;
}

int main() {
    int current_light = RED;
    int red_duration = random_duration();
    int green_duration = random_duration();
    int yellow_duration = 3; // Fixed duration for yellow light

    while(1) {
        // Switch statement to control traffic light states
        switch(current_light) {
            case RED:
                printf("\nRED Light ON\n");
                printf("Green Light in %d seconds\n", green_duration);
                sleep(red_duration);

                current_light = GREEN;
                break;

            case GREEN:
                printf("\nGREEN Light ON\n");
                printf("Yellow Light in %d seconds\n", yellow_duration);
                sleep(green_duration);

                current_light = YELLOW;
                break;

            case YELLOW:
                printf("\nYELLOW Light ON\n");
                printf("Red Light in %d seconds\n", red_duration);
                sleep(yellow_duration);

                current_light = RED;
                break;
        }
    }

    return 0;
}