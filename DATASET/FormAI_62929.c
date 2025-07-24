//FormAI DATASET v1.0 Category: Physics simulation ; Style: mind-bending
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8     // Standard Acceleration due to gravity (m/s^2)
#define PI 3.14159265  // Value of Pi

// Define object structure
typedef struct {
    float mass;     // mass of object in kg
    float radius;   // radius of object in m
    float x_pos;    // current x position of object in m
    float y_pos;    // current y position of object in m
    float x_vel;    // current x velocity of object in m/s
    float y_vel;    // current y velocity of object in m/s
} Object;

// Function to calculate the gravitational force acting on object
float calc_gravity(Object obj1, Object obj2) {
    float r = sqrt(pow((obj2.x_pos - obj1.x_pos), 2) + pow((obj2.y_pos - obj1.y_pos), 2));
    float F = (GRAVITY * obj1.mass * obj2.mass) / pow(r, 2);
    return F;
}

int main() {
    Object ball = { 0.5, 0.1, 0.0, 10.0, 10.0, 0.0 };     // Create ball object and initialize variables
    Object planet = { 5.7 * pow(10, 24), 6.371 * pow(10, 6), 0.0, 0.0, 0.0, 0.0 };    // Create planet object and initialize variables (Earth)
    float time_step = 0.01;     // Time step (in seconds) for simulation
    float time = 0.0;   // Starting time
    float theta = 45.0;   // Angle of initial velocity
    
    while (ball.y_pos > 0.0) {  // Simulation loop continues until ball reaches ground (y = 0)
        float Fg = calc_gravity(ball, planet);    // Calculate gravitational force
        float Fgx = -Fg * sin(theta * PI / 180);   // Calculate gravitational force in x direction
        float Fgy = -Fg * cos(theta * PI / 180);   // Calculate gravitational force in y direction
        
        float ax = Fgx / ball.mass;     // Calculate acceleration in x direction
        float ay = Fgy / ball.mass;     // Calculate acceleration in y direction
        
        ball.x_vel += ax * time_step;   // Update x velocity of ball
        ball.y_vel += ay * time_step;   // Update y velocity of ball
        
        ball.x_pos += ball.x_vel * time_step;  // Update x position of ball
        ball.y_pos += ball.y_vel * time_step;   // Update y position of ball
        
        printf("Time: %.2f s, Ball Position: (%.2f, %.2f)\n", time, ball.x_pos, ball.y_pos);  // Output current time and position of ball
        time += time_step;  // Update time
        
        if (ball.y_pos <= 0.0) {   // If ball reaches the ground, output total time of flight and quit loop
            printf("Time of Flight: %.2f seconds\n", time);
            break;
        }
    }
    
    return 0;
}