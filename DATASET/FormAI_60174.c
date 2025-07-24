//FormAI DATASET v1.0 Category: Physics simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PARTICLES 100 //Maximum number of particles in system
#define MAX_ITERATIONS 1000 //Maximum number of iterations

//Structure for storing particle properties
struct particle{
    float mass,x,y,z,vx,vy,vz,fx,fy,fz;
};

//Function to calculate force between two particles
void calculate_force(struct particle *p1, struct particle *p2, float *fx, float *fy, float *fz, float epsilon, float sigma){
    float r = sqrt(pow(p1->x - p2->x,2) + pow(p1->y - p2->y,2) + pow(p1->z - p2->z,2));
    float f = 24*epsilon*(2*pow(sigma,12)/pow(r,13) - pow(sigma,6)/pow(r,7));
    *fx = f*(p1->x - p2->x)/r;
    *fy = f*(p1->y - p2->y)/r;
    *fz = f*(p1->z - p2->z)/r;
}

//Main function
int main(){
    struct particle particles[MAX_PARTICLES];
    int num_particles;
    float time_step, box_dimension, epsilon, sigma;
    //Take input from user
    printf("Enter the number of particles: ");
    scanf("%d",&num_particles);
    if(num_particles > MAX_PARTICLES){
        printf("Maximum particles limit exceeded!");
        exit(0);
    }
    printf("Enter the time step: ");
    scanf("%f",&time_step);
    printf("Enter the box dimension: ");
    scanf("%f",&box_dimension);
    printf("Enter the epsilon value: ");
    scanf("%f",&epsilon);
    printf("Enter the sigma value: ");
    scanf("%f",&sigma);
    //Initialize particle positions and velocities
    for(int i=0; i<num_particles; i++){
        particles[i].mass = 1;
        particles[i].x = (float)rand()/RAND_MAX*box_dimension;
        particles[i].y = (float)rand()/RAND_MAX*box_dimension;
        particles[i].z = (float)rand()/RAND_MAX*box_dimension;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].vz = 0;
    }
    //Main simulation loop
    for(int k=0; k<MAX_ITERATIONS; k++){
        //Calculate forces between particles
        for(int i=0; i<num_particles-1; i++){
            for(int j=i+1; j<num_particles; j++){
                float fx,fy,fz;
                calculate_force(&particles[i],&particles[j],&fx,&fy,&fz,epsilon,sigma);
                particles[i].fx += fx;
                particles[i].fy += fy;
                particles[i].fz += fz;
                particles[j].fx -= fx;
                particles[j].fy -= fy;
                particles[j].fz -= fz;
            }
        }
        //Update particle positions and velocities
        for(int i=0; i<num_particles; i++){
            particles[i].vx += particles[i].fx*time_step/particles[i].mass;
            particles[i].vy += particles[i].fy*time_step/particles[i].mass;
            particles[i].vz += particles[i].fz*time_step/particles[i].mass;
            particles[i].x += particles[i].vx*time_step;
            particles[i].y += particles[i].vy*time_step;
            particles[i].z += particles[i].vz*time_step;
            //Handle boundary conditions
            if(particles[i].x < 0) particles[i].x += box_dimension;
            if(particles[i].x > box_dimension) particles[i].x -= box_dimension;
            if(particles[i].y < 0) particles[i].y += box_dimension;
            if(particles[i].y > box_dimension) particles[i].y -= box_dimension;
            if(particles[i].z < 0) particles[i].z += box_dimension;
            if(particles[i].z > box_dimension) particles[i].z -= box_dimension;
            //Reset forces
            particles[i].fx = 0;
            particles[i].fy = 0;
            particles[i].fz = 0;
        }
    }
    return 0;
}