//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

#define G 6.6743 * pow(10, -11)   //Gravitational constant

typedef struct Coord_3D{
    double x;
    double y;
    double z;
} Coord_3D;

typedef struct Velocity_3D{
    double x;
    double y;
    double z;
} Velocity_3D;

typedef struct Acceleration_3D{
    double x;
    double y;
    double z;
} Acceleration_3D;

typedef struct Planet{
    char name[20];
    double mass;      //kg
    double radius;    //m
    Coord_3D c;       //coordinates
    Velocity_3D v;    //velocity
    Acceleration_3D a; //acceleration
} Planet;

double get_distance(Planet p1, Planet p2){
    return sqrt(pow(p1.c.x - p2.c.x, 2) + pow(p1.c.y - p2.c.y, 2) + pow(p1.c.z - p2.c.z, 2));
}

Acceleration_3D get_gravity_acceleration(Planet p1, Planet p2){
    double distance = get_distance(p1, p2);
    double force = G * p1.mass * p2.mass / pow(distance, 2);
    double accel = force / p1.mass;
    Acceleration_3D result;
    result.x = accel * (p2.c.x - p1.c.x) / distance;
    result.y = accel * (p2.c.y - p1.c.y) / distance;
    result.z = accel * (p2.c.z - p1.c.z) / distance;
    return result;
}

void update_position(Planet *p, double dt){
    p->c.x += p->v.x * dt;
    p->c.y += p->v.y * dt;
    p->c.z += p->v.z * dt;
}

void update_velocity(Planet *p, double dt){
    p->v.x += p->a.x * dt;
    p->v.y += p->a.y * dt;
    p->v.z += p->a.z * dt;
}

int main(){
    Planet earth = {"Earth", 5.972 * pow(10, 24), 6371000, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Planet moon = {"Moon", 7.342 * pow(10, 22), 1737100, {385000000, 0, 0}, {0, 1022, 0}, {0, 0, 0}};

    double dt = 3600; //1 hour
    int num_steps = 8760; //1 year

    for(int i=0; i<num_steps; i++){
        earth.a = get_gravity_acceleration(earth, moon);
        moon.a = get_gravity_acceleration(moon, earth);

        update_velocity(&earth, dt/2);
        update_velocity(&moon, dt/2);

        update_position(&earth, dt);
        update_position(&moon, dt);

        earth.a = get_gravity_acceleration(earth, moon);
        moon.a = get_gravity_acceleration(moon, earth);

        update_velocity(&earth, dt/2);
        update_velocity(&moon, dt/2);

        //output coordinates
        printf("Step %d\n", i+1);
        printf("Earth: (%lf, %lf, %lf)\n", earth.c.x, earth.c.y, earth.c.z);
        printf("Moon:  (%lf, %lf, %lf)\n", moon.c.x, moon.c.y, moon.c.z);
    }

    return 0;
}