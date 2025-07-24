//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

// Function to calculate square of a number
double square(double num){
    return num * num;
}

// Structure for celestial bodies
typedef struct{
    char* name;
    double mass;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
} body;

// Function to calculate distance between two bodies
double distance(body b1, body b2){
    return sqrt(square(b1.x_pos - b2.x_pos) + square(b1.y_pos - b2.y_pos));
}

// Function to calculate angle between two bodies
double angle(body b1, body b2){
    return atan2(b2.y_pos - b1.y_pos , b2.x_pos - b1.x_pos);
}

// Function to calculate gravitational force between two bodies
double gravitational_force(body b1, body b2){
    double G = 6.67 * pow(10, -11);
    double r = distance(b1, b2);
    return G * (b1.mass * b2.mass) / square(r);
}

// Function to calculate gravitational acceleration acting on a body caused by all bodies in the system
void gravitational_acceleration(body* curr_body, body* bodies, int num_bodies){
    int i;
    double total_force = 0;
    double a_x = 0, a_y = 0;
    for(i = 0; i < num_bodies; i++){
        if(bodies[i].name != curr_body->name){
            double angle_between_bodies = angle(*curr_body, bodies[i]);
            double force_between_bodies = gravitational_force(*curr_body, bodies[i]);
            double accel_due_to_force = force_between_bodies / curr_body->mass;
            a_x += accel_due_to_force * cos(angle_between_bodies);
            a_y += accel_due_to_force * sin(angle_between_bodies);
            total_force += force_between_bodies;
        }
    }
    printf("Total gravitational force acting on %s: %.3f\n", curr_body->name, total_force);
    printf("Gravitational Acceleration on %s in x-direction: %.3f\n", curr_body->name, a_x);
    printf("Gravitational Acceleration on %s in y-direction: %.3f\n", curr_body->name, a_y);
}

int main(){
    // Define the bodies present in our solar system
    body sun = {"Sun", 1.989E+30, 0, 0, 0, 0};
    body mercury = {"Mercury", 3.285E+23, 5.791E+10, 0, 0, 4.792E+04};
    body venus = {"Venus", 4.867E+24, 1.082E+11, 0, 0, 3.502E+04};
    body earth = {"Earth", 5.972E+24, 1.496E+11, 0, 0, 2.978E+04};
    body mars = {"Mars", 6.390E+23, 2.279E+11, 0, 0, 2.407E+04};
    body jupiter = {"Jupiter", 1.898E+27, 7.785E+11, 0, 0, 1.308E+04};
    body saturn = {"Saturn", 5.683E+26, 1.429E+12, 0, 0, 9.654E+03};
    body uranus = {"Uranus", 8.681E+25, 2.871E+12, 0, 0, 6.809E+03};
    body neptune = {"Neptune", 1.024E+26, 4.495E+12, 0, 0, 5.439E+03};
    body pluto = {"Pluto", 1.309E+22, 5.906E+12, 0, 0, 4.733E+03};
    body bodies[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};
    int num_bodies = sizeof(bodies) / sizeof(body);
    
    // Print initial positions and velocities of bodies
    int i;
    for(i = 0; i < num_bodies; i++){
        printf("%s initial position: (%.3f, %.3f)\n", bodies[i].name, bodies[i].x_pos, bodies[i].y_pos);
        printf("%s initial velocity: (%.3f, %.3f)\n", bodies[i].name, bodies[i].x_vel, bodies[i].y_vel);
    }
    printf("\n");
    
    // Simulate the motion of bodies due to gravity
    int time_elapsed = 0;
    while(time_elapsed < 86400){
        // Print status of the system
        printf("Time Elapsed: %d\n", time_elapsed);
        printf("--------------------\n");
        for(i = 0; i < num_bodies; i++){
            printf("%s position: (%.3f, %.3f)\n", bodies[i].name, bodies[i].x_pos, bodies[i].y_pos);
            gravitational_acceleration(&bodies[i], bodies, num_bodies);
            printf("\n");
        }
        
        // Update the positions and velocities of each body
        for(i = 0; i < num_bodies; i++){
            body* curr_body = &bodies[i];
            curr_body->x_pos += curr_body->x_vel * 86400;
            curr_body->y_pos += curr_body->y_vel * 86400;
            int j;
            for(j = 0; j < num_bodies; j++){
                if(bodies[j].name != curr_body->name){
                    double angle_between_bodies = angle(*curr_body, bodies[j]);
                    double force_between_bodies = gravitational_force(*curr_body, bodies[j]);
                    double accel_due_to_force = force_between_bodies / curr_body->mass;
                    curr_body->x_vel += accel_due_to_force * cos(angle_between_bodies) * 86400;
                    curr_body->y_vel += accel_due_to_force * sin(angle_between_bodies) * 86400;
                }
            }
        }
        
        time_elapsed += 86400;
    }
    
    // Print final positions and velocities of bodies
    for(i = 0; i < num_bodies; i++){
        printf("%s final position: (%.3f, %.3f)\n", bodies[i].name, bodies[i].x_pos, bodies[i].y_pos);
        printf("%s final velocity: (%.3f, %.3f)\n", bodies[i].name, bodies[i].x_vel, bodies[i].y_vel);
    }

    return 0;
}