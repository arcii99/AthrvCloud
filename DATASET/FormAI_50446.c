//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Cyberpunk-themed geometric algorithm to simulate a stealth navigation system

#define PI 3.14159265

//Function to calculate the distance between two points
float distance(float x1, float x2, float y1, float y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

//Function to calculate the angle between two points
float angle(float x1, float x2, float y1, float y2)
{
    return atan2(y2-y1,x2-x1)*180/PI;
}

//Main function to test the navigation algorithm
int main()
{
    float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    float distance1, distance2, distance3, distance4, distance5;
    float angle1, angle2, angle3, angle4, angle5;
    srand(time(NULL));
    printf("Initializing stealth navigation system...\n");
    
    //generate 5 random points within a 10x10 grid
    x1 = rand() % 10 + 1;
    y1 = rand() % 10 + 1;
    x2 = rand() % 10 + 1;
    y2 = rand() % 10 + 1;
    x3 = rand() % 10 + 1;
    y3 = rand() % 10 + 1;
    x4 = rand() % 10 + 1;
    y4 = rand() % 10 + 1;
    x5 = rand() % 10 + 1;
    y5 = rand() % 10 + 1;
    
    printf("Generating coordinates...\n");
    printf("Point 1: (%.2f,%.2f)\n", x1, y1);
    printf("Point 2: (%.2f,%.2f)\n", x2, y2);
    printf("Point 3: (%.2f,%.2f)\n", x3, y3);
    printf("Point 4: (%.2f,%.2f)\n", x4, y4);
    printf("Point 5: (%.2f,%.2f)\n", x5, y5);
    printf("Calculating distances and angles...\n");
    
    //calculate distances and angles between points
    distance1 = distance(x1, x2, y1, y2);
    distance2 = distance(x2, x3, y2, y3);
    distance3 = distance(x3, x4, y3, y4);
    distance4 = distance(x4, x5, y4, y5);
    distance5 = distance(x5, x1, y5, y1);
    
    angle1 = angle(x1, x2, y1, y2);
    angle2 = angle(x2, x3, y2, y3);
    angle3 = angle(x3, x4, y3, y4);
    angle4 = angle(x4, x5, y4, y5);
    angle5 = angle(x5, x1, y5, y1);
    
    printf("Distance from Point 1 to Point 2: %.2f units\n", distance1);
    printf("Distance from Point 2 to Point 3: %.2f units\n", distance2);
    printf("Distance from Point 3 to Point 4: %.2f units\n", distance3);
    printf("Distance from Point 4 to Point 5: %.2f units\n", distance4);
    printf("Distance from Point 5 to Point 1: %.2f units\n", distance5);
    
    printf("Angle from Point 1 to Point 2: %.2f degrees\n", angle1);
    printf("Angle from Point 2 to Point 3: %.2f degrees\n", angle2);
    printf("Angle from Point 3 to Point 4: %.2f degrees\n", angle3);
    printf("Angle from Point 4 to Point 5: %.2f degrees\n", angle4);
    printf("Angle from Point 5 to Point 1: %.2f degrees\n", angle5);
    
    printf("System initialized. Enter stealth mode...\n");
    return 0;
}