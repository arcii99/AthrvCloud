//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dt 0.01
#define g -9.8
#define SECONDS_IN_A_DAY 86400
#define PI 3.14159265359

typedef struct{
    double x, y, z;
} Vector;

typedef struct{
    Vector position, velocity, acceleration;
} Particle;

void update(Particle* p){
    p->position.x += p->velocity.x*dt + 0.5*p->acceleration.x*dt*dt;
    p->position.y += p->velocity.y*dt + 0.5*p->acceleration.y*dt*dt;
    p->position.z += p->velocity.z*dt + 0.5*p->acceleration.z*dt*dt;

    p->velocity.x += p->acceleration.x*dt;
    p->velocity.y += p->acceleration.y*dt;
    p->velocity.z += p->acceleration.z*dt;
}

double get_distance(Vector a, Vector b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}

double get_speed(Vector a){
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

int main(){
    Particle ball;
    ball.position.x = 0;
    ball.position.y = 0;
    ball.position.z = 0;

    ball.velocity.x = 70*cos(60*PI/180);
    ball.velocity.y = 70*sin(60*PI/180);
    ball.velocity.z = 0;

    ball.acceleration.x = 0;
    ball.acceleration.y = g;
    ball.acceleration.z = 0;

    double t = 0;
    double max_height = 0;
    double distance = 0;
    double time_to_ground = 0;

    while(ball.position.y >= 0){
        update(&ball);

        if(ball.position.y > max_height){
            max_height = ball.position.y;
        }

        distance = get_distance(ball.position, (Vector){0, 0, 0});

        t += dt;
        time_to_ground = t;

        printf("Time: %f seconds\n", t);
        printf("Position: (%f, %f, %f)\n", ball.position.x, ball.position.y, ball.position.z);
        printf("Velocity: %fm/s\n", get_speed(ball.velocity));
        printf("Acceleration: %fm/s^2\n", get_distance(ball.acceleration, (Vector){0, 0, 0}));

        printf("\n");
    }

    printf("Maximum height: %fm\n", max_height);
    printf("Time to reach the ground: %f seconds\n", time_to_ground);
    printf("Total horizontal distance: %fm\n", distance);

    return 0;
}