//FormAI DATASET v1.0 Category: Scientific ; Style: happy
#include<stdio.h>

// This program calculates the area of a circle

int main(){
    float radius, area;
    
    printf("Welcome to Area Calculator!\n");

    printf("Please enter the radius of circle: ");
    scanf("%f", &radius);
    
    area = 3.14 * radius * radius; // Calculate area
    
    printf("Great job!!!\n");
    printf("The area of the circle with radius %.2f is %.2f.\n", radius, area);
    printf("Keep up the good work!\n");
    
    return 0;
}