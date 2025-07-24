//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include<stdio.h>

/* This program calculates the distance between two points using Geometric algorithms */

int main(){
    float x1, y1, x2, y2, distance;
    
    printf("Enter the coordinates of the first point with space separation (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    
    printf("Enter the coordinates of the second point with space separation (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    
    // Calculation of distance
    distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    
    printf("The distance between the two points (%.2f,%.2f) and (%.2f,%.2f) is %.2f units.", x1, y1, x2, y2, distance);
    
    return 0;
}