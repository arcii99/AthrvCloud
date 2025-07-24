//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    float radius, height, slant_height, base_area, surface_area, volume;

    printf("Enter radius: ");
    scanf("%f", &radius);

    printf("Enter height: ");
    scanf("%f", &height);

    slant_height = sqrt(pow(radius, 2) + pow(height, 2));
    base_area = PI * pow(radius, 2);
    surface_area = PI * radius * slant_height + 2 * base_area;
    volume = base_area * height / 3;

    printf("Slant height: %.2f\n", slant_height);
    printf("Base area: %.2f\n", base_area);
    printf("Surface area: %.2f\n", surface_area);
    printf("Volume: %.2f\n", volume);

    return 0;
}