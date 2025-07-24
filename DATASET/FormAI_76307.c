//FormAI DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>

int main() {
    float distance, time, speed;

    printf("Enter distance in kilometers: ");
    scanf("%f", &distance);

    printf("Enter time taken in hours: ");
    scanf("%f", &time);

    speed = distance / time;

    printf("Speed is %.2f km/h\n", speed);

    return 0;
}