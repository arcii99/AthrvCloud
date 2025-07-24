//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: all-encompassing
#include<stdio.h>
#include<math.h>

#define G 6.674e-11 // Gravitational constant
#define mass_of_earth 5.972e24 // mass of earth in kg
#define radius_of_earth 6.371e6 // radius of earth in meters
#define time_step 1 // time step for simulation in seconds
#define simulation_time 86400 // simulation time in seconds

int main(){

    float t = 0; // initializing time

    // initializing the initial conditions of the planets
    float mass_of_planet1 = 3.0e29; // mass of planet1 in kg
    float x1 = 4.0e11; // x coordinate of planet1 in meters
    float y1 = 0; // y coordinate of planet1 in meters
    float vx1 = 0; // x component of velocity of planet1 in m/s
    float vy1 = 1.0e4; // y component of velocity of planet1 in m/s

    float mass_of_planet2 = 6.0e24; // mass of planet2 in kg
    float x2 = 0; // x coordinate of planet2 in meters
    float y2 = radius_of_earth + 500e3; // y coordinate of planet2 in meters
    float vx2 = 7.9e3; // x component of velocity of planet2 in m/s
    float vy2 = 0; // y component of velocity of planet2 in m/s

    // initializing the accelerations of the planets
    float ax1 = 0; // x component of acceleration of planet1 in m/s^2
    float ay1 = 0; // y component of acceleration of planet1 in m/s^2
    float ax2 = 0; // x component of acceleration of planet2 in m/s^2
    float ay2 = 0; // y component of acceleration of planet2 in m/s^2

    // initializing distance between the planets
    float r = sqrt(pow(x1-x2,2)+pow(y1-y2,2));

    // printing the initial conditions of the system
    printf("Initial conditions of the system : \n\n");
    printf("Mass of planet1 : %.2e kg\n",mass_of_planet1);
    printf("Coordinates of planet1 : (%.2e,%.2e) meters\n",x1,y1);
    printf("Velocity of planet1 : (%.2e,%.2e) m/s\n",vx1,vy1);
    printf("Mass of planet2 : %.2e kg\n",mass_of_planet2);
    printf("Coordinates of planet2 : (%.2e,%.2e) meters\n",x2,y2);
    printf("Velocity of planet2 : (%.2e,%.2e) m/s\n\n",vx2,vy2);

    // running the simulation loop
    while(t<=simulation_time){

        // calculating the acceleration of planet1
        ax1 = -G*mass_of_planet2*(x1-x2)/(r*r*r);
        ay1 = -G*mass_of_planet2*(y1-y2)/(r*r*r);

        // calculating the acceleration of planet2
        ax2 = -G*mass_of_planet1*(x2-x1)/(r*r*r);
        ay2 = -G*mass_of_planet1*(y2-y1)/(r*r*r);

        // calculating the new velocities of planet1 and planet2
        vx1 = vx1 + ax1*time_step;
        vy1 = vy1 + ay1*time_step;
        vx2 = vx2 + ax2*time_step;
        vy2 = vy2 + ay2*time_step;

        // calculating the new positions of planet1 and planet2
        x1 = x1 + vx1*time_step;
        y1 = y1 + vy1*time_step;
        x2 = x2 + vx2*time_step;
        y2 = y2 + vy2*time_step;

        // calculating the new distance between the planets
        r = sqrt(pow(x1-x2,2)+pow(y1-y2,2));

        // printing the results after each time step
        printf("\nAfter time step %.2f seconds : \n\n",t+time_step);
        printf("Coordinates of planet1 : (%.2e,%.2e) meters\n",x1,y1);
        printf("Velocity of planet1 : (%.2e,%.2e) m/s\n",vx1,vy1);
        printf("Coordinates of planet2 : (%.2e,%.2e) meters\n",x2,y2);
        printf("Velocity of planet2 : (%.2e,%.2e) m/s\n\n",vx2,vy2);

        t = t + time_step; // updating time        

    }

    return 0; // exiting the program

}