//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the Traffic Light Controller Program!\n\n");
    int lightTime = 30; // in seconds
    printf("The traffic lights will change every %d seconds.\n", lightTime);
    int redTime = 10;
    int yellowTime = 5;
    int greenTime = 15;
    while (1) {
        printf("Red Light for %d seconds.\n", redTime);
        for (int i = redTime; i >= 0; i--) {
            printf("%d\n", i);
            sleep(1);
        }
        printf("Green Light for %d seconds.\n", greenTime);
        for (int i = greenTime; i >= 0; i--) {
            printf("%d\n", i);
            sleep(1);
        }
        printf("Yellow Light for %d seconds.\n", yellowTime);
        for (int i = yellowTime; i >= 0; i--) {
            printf("%d\n", i);
            sleep(1);
        }
    }
    return 0;
}