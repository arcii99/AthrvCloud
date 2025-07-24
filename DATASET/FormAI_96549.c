//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>

int main() {
    int inner_radius, outer_radius;
    float pi = 3.14159, area;

    printf("Welcome to the Doughnut Area Calculator!\n\n");
    printf("Please enter the inner radius of the doughnut: ");
    scanf("%d", &inner_radius);
    printf("Please enter the outer radius of the doughnut: ");
    scanf("%d", &outer_radius);

    area = pi * ((outer_radius * outer_radius) - (inner_radius * inner_radius));

    printf("\nThank you!\n");
    printf("The area of the doughnut with an inner radius of %d and an outer radius of %d is %.2f square units.", inner_radius, outer_radius, area);

    return 0;
}