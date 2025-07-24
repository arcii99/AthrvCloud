//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char trafficLightColor[3] = {'R', 'Y', 'G'};     // You can add more colors here
    int currentColorIndex = 0;
    
    srand(time(0));
    int randomDelay = (rand() % (10 - 3 + 1)) + 3;    // Generates random delay between 3 and 10 seconds
    
    printf("\n-------TRAFFIC LIGHT SIMULATOR-------\n");
    printf("Starting in %d seconds...\n", randomDelay);
    sleep(randomDelay);
    
    while(1) {
        switch(trafficLightColor[currentColorIndex++ % 3]) {
            case 'R':
                printf("\nRed Light ON\n");
                sleep(5);                               // Red light stays on for 5 seconds
                break;
            case 'Y':
                printf("\nYellow Light ON\n");
                sleep(2);                               // Yellow light stays on for 2 seconds
                break;
            case 'G':
                printf("\nGreen Light ON\n");
                sleep(5);                               // Green light stays on for 5 seconds
                break;
        }
    }
    
    return 0;
}