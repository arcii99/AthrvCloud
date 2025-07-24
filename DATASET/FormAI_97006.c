//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multivariable
#include <stdio.h>
int main()
{
    int battery, control, distance;

    printf("Enter battery level (out of 10): ");
    scanf("%d", &battery);
    printf("Enter control level (out of 10): ");
    scanf("%d", &control);
    printf("Enter distance (in meters): ");
    scanf("%d", &distance);

    if (battery < 5 && control < 5) {
        printf("Drone battery and control level are low. Please charge battery and ensure control distance is within range.\n");
    }
    else if (battery < 5) {
        printf("Drone battery level is low. Please charge battery.\n");
    }
    else if (control < 5) {
        printf("Drone control level is low. Please ensure control distance is within range.\n");
    }
    else if (distance > 100) {
        printf("Drone is out of range. Please ensure control distance is within range.\n");
    }
    else {
        printf("Drone ready for flight. Enjoy!\n");
    }

    return 0;
}