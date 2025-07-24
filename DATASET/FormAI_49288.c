//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

//Constants
#define PI 3.14159265358979323846  //pi value for calculations

//Main program
int main()
{
    //Initialize variables
    double velocity = 50.0;  //Initial velocity in m/s
    double angle = 45.0;  //Angle of projection in degrees
    double elevation = 0.0;  //Initial elevation in meters
    double time_interval = 0.01;  //Time interval in seconds
    double time = 0.0;  //Initial time in seconds
    double acceleration = -9.8;  //Gravitational acceleration in m/s^2
    double x_position = 0.0;  //Initial x position in meters
    double y_position = elevation;  //Initial y position includes elevation
    double x_velocity = velocity * cos(angle * PI / 180.0);  //Initial x velocity in m/s
    double y_velocity = velocity * sin(angle * PI / 180.0);  //Initial y velocity in m/s

    //Calculate trajectory
    while (y_position >= elevation)
    {
        x_position = x_velocity * time;
        y_position = elevation + y_velocity * time + 0.5 * acceleration * pow(time, 2.0);
        time += time_interval;

        //Print trajectory information
        printf("Time: %.2f s\tX Position: %.2f m\tY Position: %.2f m\n", time, x_position, y_position);
    }

    //Print maximum height and total distance travelled
    double max_height = elevation + pow(y_velocity, 2.0) / (2 * (-acceleration));
    double total_distance = x_velocity * 2 * y_velocity / -acceleration;
    printf("\nMaximum Height: %.2f m\nTotal Distance: %.2f m\n", max_height, total_distance);

    return 0;
}