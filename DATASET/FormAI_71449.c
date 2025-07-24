//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979323846
#define G 6.6743e-11

struct particle{
    double x;
    double y;
    double mass;
    double vx;
    double vy;
};

double distance(struct particle p1, struct particle p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double angle(struct particle p1, struct particle p2){
    return atan2(p1.y - p2.y, p1.x - p2.x);
}

double force(struct particle p1, struct particle p2){
    double r = distance(p1, p2);
    double f = G * p1.mass * p2.mass / (r * r);
    return f;
}

double acceleration(double f, double m){
    return f / m;
}

void update(struct particle* p, double ax, double ay, double time_step){
    p->vx += ax * time_step;
    p->vy += ay * time_step;
    p->x += p->vx * time_step;
    p->y += p->vy * time_step;
}

int main(){
    int num_particles = 3;
    struct particle particles[num_particles];
    particles[0].x = 0;
    particles[0].y = 0;
    particles[0].mass = 1e17;
    particles[0].vx = 0;
    particles[0].vy = 0;

    particles[1].x = 1e7;
    particles[1].y = 0;
    particles[1].mass = 1e15;
    particles[1].vx = 0;
    particles[1].vy = 1e3;

    particles[2].x = 0;
    particles[2].y = 1e7;
    particles[2].mass = 1e16;
    particles[2].vx = -1e3;
    particles[2].vy = 0;

    double time_step = 0.1;
    double duration = 365 * 24 * 3600;
    int steps = duration / time_step;

    for(int i = 0; i < steps; i++){
        for(int j = 0; j < num_particles; j++){
            struct particle p1 = particles[j];
            double ax = 0;
            double ay = 0;
            for(int k = 0; k < num_particles; k++){
                if(j != k){
                    struct particle p2 = particles[k];
                    double f = force(p1, p2);
                    double theta = angle(p1, p2);
                    double ax_ = acceleration(f * cos(theta), p1.mass);
                    double ay_ = acceleration(f * sin(theta), p1.mass);
                    ax += ax_;
                    ay += ay_;
                }
            }
            update(&particles[j], ax, ay, time_step);
        }
        printf("Step %d - Particle positions:\n", i+1);
        for(int j = 0; j < num_particles; j++){
            printf("Particle %d - x = %e, y = %e\n", j+1, particles[j].x, particles[j].y);
        }
    }
    return 0;
}