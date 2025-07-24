//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome to the Traffic Light Controller Program!\n");

    int red = 1, yellow = 0, green = 0;

    while (1) {
        // Red light
        if (red) {
            printf("Red light on\n");
            sleep(5);
            red = 0;
            yellow = 1;
        }
        // Yellow light
        else if (yellow) {
            printf("Yellow light on\n");
            sleep(2);
            yellow = 0;
            green = 1;
        }
        // Green light
        else if (green) {
            printf("Green light on\n");
            sleep(5);
            green = 0;
            yellow = 1;
        }
    }

    return 0;
}