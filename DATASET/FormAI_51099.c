//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int blue = rand() % 10 + 1;
    int green = rand() % 10 + 1;
    int red = rand() % 10 + 1;

    printf("Starting the traffic light controller...\n");
    printf("Blue light time: %d seconds\n", blue);
    printf("Green light time: %d seconds\n", green);
    printf("Red light time: %d seconds\n", red);

    printf("The traffic light is now green.\n");
    int count = 0;
    while (count < green) {
        printf("%d seconds left until green light is turned off.\n", green - count);
        count++;
        sleep(1);
    }

    printf("The traffic light is now yellow.\n");
    sleep(2);

    printf("The traffic light is now red.\n");
    count = 0;
    while (count < red) {
        printf("%d seconds left until red light is turned off.\n", red - count);
        count++;
        sleep(1);
    }

    printf("The traffic light is now blue.\n");
    count = 0;
    while (count < blue) {
        printf("%d seconds left until blue light is turned off.\n", blue - count);
        count++;
        sleep(1);
    }

    printf("The traffic light controller has finished.\n");
    return 0;
}