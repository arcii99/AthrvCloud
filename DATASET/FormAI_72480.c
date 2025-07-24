//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int counter = 0;
    while(counter < 10) {
        system("clear");
        printf("Traffic Light Controller System\n\n");
        printf("Red Light ON\n");
        sleep(3);
        system("clear");
        printf("Traffic Light Controller System\n\n");
        printf("Green Light ON\n");
        sleep(3);
        system("clear");
        printf("Traffic Light Controller System\n\n");
        printf("Yellow Light ON\n");
        sleep(1);
        counter++;
    }
    return 0;
}