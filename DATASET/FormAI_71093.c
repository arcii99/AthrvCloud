//FormAI DATASET v1.0 Category: Math exercise ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main() {
    float radius, volume;
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);
    
    volume = (4.0 / 3.0) * M_PI * pow(radius, 3.0);
    
    printf("The volume of the sphere with radius %.2f is %.2f\n", radius, volume);
    
    return 0;
}