//FormAI DATASET v1.0 Category: Physics simulation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_PARTICLES 50
#define MAX_TIME 1000

typedef struct {
    double x,y;
} Vector2D; 

typedef struct {
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    double mass;
    int charge;
} Particle;

Particle particles[MAX_PARTICLES];
int num_particles = 0;

double get_distance(Vector2D a, Vector2D b)
{
    double dist = sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
    return dist;
}

void simulate_particles(double time_step)
{
    Vector2D forces[num_particles];
    for(int i=0; i<num_particles; i++)
    {
        Vector2D net_force = {0,0};
        for(int j=0; j<num_particles; j++)
        {
            if(i==j) continue;

            double distance = get_distance(particles[i].position, particles[j].position);

            if(distance<=0.1) continue;

            double magnitude = (particles[i].charge*particles[j].charge)/(distance*distance);
            Vector2D force = {(particles[j].position.x - particles[i].position.x)/distance,
                              (particles[j].position.y - particles[i].position.y)/distance};
            force.x *= magnitude;
            force.y *= magnitude;
            net_force.x += force.x;
            net_force.y += force.y;
        }
        forces[i] = net_force;
    }

    for(int i=0; i<num_particles; i++)
    {
        particles[i].acceleration.x = forces[i].x / particles[i].mass;
        particles[i].acceleration.y = forces[i].y / particles[i].mass;

        particles[i].velocity.x += particles[i].acceleration.x * time_step;
        particles[i].velocity.y += particles[i].acceleration.y * time_step;

        particles[i].position.x += particles[i].velocity.x*time_step;
        particles[i].position.y += particles[i].velocity.y*time_step;
   }
}

int main()
{
    printf("Initializing particle positions and charges...\n");
    particles[0] = (Particle) {{-1,-1},{0,0},{0,0},1,1};
    particles[1] = (Particle) {{1,1},{0,0},{0,0},1,-1};
    num_particles = 2;

    printf("Simulating particles...\n");
    for(int t=0; t<MAX_TIME; t++)
    {
        simulate_particles(0.01);
        for(int i=0; i<num_particles; i++)
        {
            printf("Particle %d position: (%lf,%lf)\n",i+1,particles[i].position.x,particles[i].position.y);
        }
    }
    return 0;
}