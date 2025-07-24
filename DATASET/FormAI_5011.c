//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    float angle = 0, velocity = 0, height = 0, time = 0;
    float x = 0, y = 0, t = 0;
    float g = 9.8, radian;
    
    printf("Enter the initial velocity (m/s): ");
    scanf("%f", &velocity);
    
    printf("Enter the angle of projection (degrees): ");
    scanf("%f", &angle);

    printf("Enter the initial height (m): ");
    scanf("%f", &height);
    
    radian = angle * PI / 180;
    
    x = 0;
    y = height;
    
    printf("\nTime(s)  X(m)  Y(m)\n");
    
    while (y >= 0)
    {
        x = velocity * cos(radian) * t;
        y = height + (velocity * sin(radian) * t) - (0.5 * g * t * t);
        
        printf("%5.2f   %5.2f   %5.2f\n", t, x, y);
        
        t += 0.1;
    }
    
    return 0;
}