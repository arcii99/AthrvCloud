//FormAI DATASET v1.0 Category: Physics simulation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const float PI = 3.14159265358979323846; // Defining pi with precision

int main()
{
    float g=9.81; // Defining gravitational constant
    
    float angle;
    printf("Enter angle of projection in degrees:"); 
    scanf("%f",&angle);

    float velocity;
    printf("Enter velocity of projection in m/s:"); 
    scanf("%f",&velocity);

    float angle_rad = angle * PI / 180; // conversion of angle from degree to radian

    float x=0;
    float y=0;
    float t=0;

    float x_max;
    x_max = (velocity*velocity*sin(2*angle_rad))/g; // calculation of maximum distance

    printf("Maximum horizontal distance is %f meters\n\n", x_max);

    while(y>=0)
    {
        x=(velocity*cos(angle_rad)*t); // Position in x-axis
        y=(velocity*sin(angle_rad)*t)-0.5*g*(t*t); // Position in y-axis

        if(y>0)
        {
            printf("Time: %f  X-Position: %f  Y-Position: %f\n", t, x, y);
            printf("-------------------------------------------------------------------------------\n");
        }
        else 
        {
            printf("\nTime of flight: %f seconds\n", t);
            printf("-------------------------------------------------------------------------------\n");
        }
        t += 0.1; // Incrementing time steps
    }

    return 0;
}