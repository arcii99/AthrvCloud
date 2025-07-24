//FormAI DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int x, y, direction, distance;
    
    printf("Enter starting x-coordinate: ");
    scanf("%d", &x);
    
    printf("Enter starting y-coordinate: ");
    scanf("%d", &y);
    
    printf("Enter direction (0-359 degrees): ");
    scanf("%d", &direction);
    
    printf("Enter distance to move: ");
    scanf("%d", &distance);
    
    // Convert direction from degrees to radians
    double radian = direction * PI / 180.0;
    
    // Calculate new x and y coordinates after movement
    int new_x = x + (int)(distance * cos(radian));
    int new_y = y + (int)(distance * sin(radian));
    
    printf("\nRobot has moved to (%d, %d)", new_x, new_y);
    
    return 0;
}