//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char start[50], dest[50];
    int route[50];
    float distance;

    // Prompt user to input starting point and destination
    printf("Enter starting point: ");
    fgets(start, 50, stdin);
    printf("Enter destination: ");
    fgets(dest, 50, stdin);

    // Code to calculate the route and distance goes here

    // Display the route and distance
    printf("Route: ");
    for (int i = 0; i < sizeof(route)/sizeof(int); i++) {
        printf("%d ", route[i]);
    }
    printf("\nDistance: %.2f km\n", distance);

    return 0;
}