//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include<stdio.h>
#include<math.h>

#define G 6.674*pow(10,-11) //gravitational constant
#define TIME_STEP 100.0 //time step in seconds

//structure to represent a planet
struct planet{
    char name[20];
    double mass; //in kg
    double radius; //in m
    double x_pos; //in m
    double y_pos; //in m
    double x_vel; //in m/s
    double y_vel; //in m/s
};

typedef struct planet Planet;

int main(){
    Planet sun, earth, moon;

    //initializing the planets
    strcpy(sun.name, "Sun");
    sun.mass = 1.989*pow(10,30);
    sun.radius = 696340000;
    sun.x_pos = 0;
    sun.y_pos = 0;
    sun.x_vel = 0;
    sun.y_vel = 0;

    strcpy(earth.name, "Earth");
    earth.mass = 5.972*pow(10,24);
    earth.radius = 6371000;
    earth.x_pos = 147098074000;
    earth.y_pos = 0;
    earth.x_vel = 0;
    earth.y_vel = 30290; //avg velocity in m/s 

    strcpy(moon.name, "Moon");
    moon.mass = 7.342*pow(10,22);
    moon.radius = 1737100;
    moon.x_pos = 147100000000;
    moon.y_pos = 384400000; //dist from earth in m
    moon.x_vel = 1022; //avg velocity in m/s
    moon.y_vel = 30665; //avg velocity in m/s

    double distance, force, acceleration, x_accel, y_accel, x_vel_new, y_vel_new;
    double time = 0;
    
    //simulation loop
    while(time <= 31536000){ //1 year in seconds
        //find distance between sun and earth, and force of gravity acting on earth
        distance = sqrt(pow((earth.x_pos - sun.x_pos), 2) + pow((earth.y_pos - sun.y_pos), 2));
        force = (G * earth.mass * sun.mass) / pow(distance, 2);

        //calculate acceleration of earth
        acceleration = force / earth.mass;
        x_accel = acceleration * cos(atan2((earth.y_pos - sun.y_pos), (earth.x_pos - sun.x_pos)));
        y_accel = acceleration * sin(atan2((earth.y_pos - sun.y_pos), (earth.x_pos - sun.x_pos)));

        //update earth's velocity and position
        x_vel_new = earth.x_vel + (x_accel * TIME_STEP);
        y_vel_new = earth.y_vel + (y_accel * TIME_STEP);
        earth.x_pos = earth.x_pos + (x_vel_new * TIME_STEP);
        earth.y_pos = earth.y_pos + (y_vel_new * TIME_STEP);

        //find distance between earth and moon, and force of gravity acting on moon
        distance = sqrt(pow((moon.x_pos - earth.x_pos), 2) + pow((moon.y_pos - earth.y_pos), 2));
        force = (G * moon.mass * earth.mass) / pow(distance, 2);

        //calculate acceleration of moon
        acceleration = force / moon.mass;
        x_accel = acceleration * cos(atan2((moon.y_pos - earth.y_pos), (moon.x_pos - earth.x_pos)));
        y_accel = acceleration * sin(atan2((moon.y_pos - earth.y_pos), (moon.x_pos - earth.x_pos)));

        //update moon's velocity and position
        moon.x_vel = moon.x_vel + (x_accel * TIME_STEP);
        moon.y_vel = moon.y_vel + (y_accel * TIME_STEP);
        moon.x_pos = moon.x_pos + (moon.x_vel * TIME_STEP);
        moon.y_pos = moon.y_pos + (moon.y_vel * TIME_STEP);

        printf("Time: %f s | Earth Position: (%e, %e) m | Moon Position: (%e, %e) m\n", time, earth.x_pos, earth.y_pos, moon.x_pos, moon.y_pos);
        time += TIME_STEP;
    }

    return 0;
}