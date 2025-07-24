//FormAI DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

int main() {
    int time = 0; // in seconds
    double x_position = 0.0; // in meters
    double y_position = 0.0; // in meters
    double x_velocity = 50.0; // in m/s
    double y_velocity = 0.0; // in m/s
    double theta = 45.0; // in degrees
    double g = 9.8; // in m/s^2
    double mass = 0.05; // in kilograms
    double air_resistance = 0.0;
    double area = 0.0001; // in meters^2
    double density_air = 1.2041; // in kg/m^3
    double coefficient = 0.47;
    double delta_time = 0.01; // in seconds
    double acceleration_x = 0.0; // in m/s^2
    double acceleration_y = 0.0; // in m/s^2
    
    while (y_position >= 0.0) {
        time += 1;
        
        // calculate air resistance
        air_resistance = 0.5 * density_air * coefficient * area * pow(x_velocity, 2);
        
        // calculate acceleration
        acceleration_x = -(air_resistance / mass) * cos(theta);
        acceleration_y = -g - ((air_resistance / mass) * sin(theta));
        
        // calculate velocity
        x_velocity += acceleration_x * delta_time;
        y_velocity += acceleration_y * delta_time;
        
        // calculate position
        x_position += x_velocity * delta_time;
        y_position += y_velocity * delta_time;
        
        printf("Time: %ds | X position: %.2fm | Y position: %.2fm\n", time, x_position, y_position);
    }
    
    printf("Projectile landed at X position: %.2fm | Total flight time: %ds", x_position, time);
    
    return 0;
}