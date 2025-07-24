//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include<stdio.h>
#include<math.h>
#define PI 3.1415926535

int main() {
    float radius, slant_height, base_height, volume, surface_area;

    // prompt the user for input
    printf("Enter the radius of the cone: ");
    scanf("%f", &radius);
    printf("Enter the slant height of the cone: ");
    scanf("%f", &slant_height);
    printf("Enter the base height of the cone: ");
    scanf("%f", &base_height);

    // Calculate the volume of the cone
    volume = (PI * pow(radius, 2) * base_height) / 3.0;

    // Calculate the surface area of the cone
    surface_area = PI * radius * (radius + slant_height);

    // Print out the results
    printf("\nGiven:\nRadius: %.2f units\nSlant Height: %.2f units\nBase Height: %.2f units\n\n", radius, slant_height, base_height);
    printf("The volume of the cone is %.2f cubic units.\n", volume);
    printf("The surface area of the cone is %.2f square units.\n", surface_area);

    return 0;
}