//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle;

int main() {
    int num_particles = 20;
    double dt = 0.1;
    double G = 6.67e-11;

    Particle particles[num_particles];

    //initialize particles
    for(int i=0; i<num_particles; i++){
        particles[i].x = (double)(rand()%1000)/1000.0;
        particles[i].y = (double)(rand()%1000)/1000.0;
        particles[i].z = (double)(rand()%1000)/1000.0;
        particles[i].vx = (double)(rand()%1000)/1000.0;
        particles[i].vy = (double)(rand()%1000)/1000.0;
        particles[i].vz = (double)(rand()%1000)/1000.0;
    }

    //simulation loop
    for(int t=0; t<1000; t++){
        for(int i=0; i<num_particles; i++){
            Particle p = particles[i];
            double ax = 0.0;
            double ay = 0.0;
            double az = 0.0;

            //calculate forces on particle i due to all other particles
            for(int j=0; j<num_particles; j++){
                if(j==i) continue;

                Particle p2 = particles[j];
                double dx = p2.x - p.x;
                double dy = p2.y - p.y;
                double dz = p2.z - p.z;
                double dist = sqrt(dx*dx + dy*dy + dz*dz);

                double f = G / (dist * dist);

                ax += f * dx / dist;
                ay += f * dy / dist;
                az += f * dz / dist;
            }

            //update position and velocity of particle i
            particles[i].x += p.vx * dt + 0.5 * ax * dt * dt;
            particles[i].y += p.vy * dt + 0.5 * ay * dt * dt;
            particles[i].z += p.vz * dt + 0.5 * az * dt * dt;

            particles[i].vx += ax * dt;
            particles[i].vy += ay * dt;
            particles[i].vz += az * dt;
        }

        //print positions of particles every 10 timesteps
        if(t%10 == 0){
            for(int i=0; i<num_particles; i++){
                printf("%lf %lf %lf\n", particles[i].x, particles[i].y, particles[i].z);
            }
            printf("\n");
        }
    }

    return 0;
}