//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <math.h>

int main() {
    float lat[5], lon[5];
    float distance_array[4];

    printf("Enter the latitude and longitude readings for 5 different locations:\n");
    for (int i=0; i<5; i++) {
        printf("Location %d:\n", i+1);
        scanf("%f %f", &lat[i], &lon[i]);
    }

    printf("\n");

    for (int i=0; i<4; i++) {
        distance_array[i] = sqrt(pow((lat[i+1]-lat[i]), 2) + pow((lon[i+1]-lon[i]), 2));
        printf("The distance between location %d and location %d is: %f\n", i+1, i+2, distance_array[i]);
    }

    return 0;
}