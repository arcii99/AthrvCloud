//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define GREEN_LIGHT_TIME 10
#define YELLOW_LIGHT_TIME 5
#define RED_LIGHT_TIME 15

int main(void) {
    int time_remaining;
    char status[10];
    while (1) {
        time_remaining = GREEN_LIGHT_TIME;
        sprintf(status, "%s", "Green");

        printf("The traffic light is %s\n", status);
 
        while (time_remaining > 0) {
            printf("Time remaining: %d\n", time_remaining);
            sleep(1);
            time_remaining--;
        }
 
        time_remaining = YELLOW_LIGHT_TIME;
        sprintf(status, "%s", "Yellow");

        printf("The traffic light is %s\n", status);
 
        while (time_remaining > 0) {
            printf("Time remaining: %d\n", time_remaining);
            sleep(1);
            time_remaining--;
        }
 
        time_remaining = RED_LIGHT_TIME;
        sprintf(status, "%s", "Red");

        printf("The traffic light is %s\n", status);
 
        while (time_remaining > 0) {
            printf("Time remaining: %d\n", time_remaining);
            sleep(1);
            time_remaining--;
        }
    }

    return 0;
}