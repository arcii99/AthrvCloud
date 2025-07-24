//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>

int main() {
    int red = 1, yellow = 0, green = 0;
    int time = 0;

    printf("Traffic Light Controller\n");

    while (time < 60) {
        time++;

        if (red) {
            printf("RED\n");
            yellow = 1;
            red = 0;
        } else if (yellow) {
            printf("YELLOW\n");
            green = 1;
            yellow = 0;
        } else if (green) {
            printf("GREEN\n");
            red = 1;
            green = 0;
        }
    }

    return 0;
}