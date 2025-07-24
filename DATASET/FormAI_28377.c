//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redLight() {
    printf("STOP! Red Light On\n");
}

void yellowLight() {
    printf("GET READY! Yellow Light On\n");
}

void greenLight() {
    printf("GO! Green Light On\n");
}

int main() {
    printf("TRAFFIC LIGHT CONTROLLER\n");

    while (1) {
        redLight(); // Initial State
        sleep(10); // Red Light remains On for 10 seconds
        yellowLight();
        sleep(5); // Yellow Light remains On for 5 seconds
        greenLight();
        sleep(15); // Green Light remains On for 15 seconds
        yellowLight(); // Yellow Light before the Red Light
        sleep(5);
    }

    return 0;
}