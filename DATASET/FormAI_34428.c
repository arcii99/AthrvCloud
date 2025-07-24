//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: configurable
#include<stdio.h>

#define G 6.67430e-11 //universal gravitational constant

//structure for holding the data of each celestial body
typedef struct {
    char name[20];
    double mass;
    double x, y, z;
    double vx, vy, vz;
} celestial_body;

//function for calculating the force between two bodies
void calc_force(celestial_body *a, celestial_body *b, double *fx, double *fy, double *fz){
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    double dist_sq = dx*dx + dy*dy + dz*dz;
    double f = G * a->mass * b->mass / dist_sq;
    *fx = f * dx / sqrt(dist_sq);
    *fy = f * dy / sqrt(dist_sq);
    *fz = f * dz / sqrt(dist_sq);
}

//function for updating the position and velocity of a body based on the forces acting on it
void update(celestial_body *body, double fx, double fy, double fz, double dt){
    double ax = fx / body->mass;
    double ay = fy / body->mass;
    double az = fz / body->mass;

    body->vx += ax * dt;
    body->vy += ay * dt;
    body->vz += az * dt;

    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

int main(){
    int num_bodies = 3;
    double dt = 86400; //time step of 1 day
    int num_steps = 365; //simulate for 1 year

    celestial_body sun = {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0};
    celestial_body earth = {"Earth", 5.972e24, 1.496e11, 0, 0, 0, 29783, 0};
    celestial_body moon = {"Moon", 7.342e22, 1.496e11+3.844e8, 0, 0, 0, 29783+1022, 0};

    celestial_body *bodies[num_bodies];
    bodies[0] = &sun;
    bodies[1] = &earth;
    bodies[2] = &moon;

    for(int i=0; i<num_steps; i++){
        //calculate forces on each body
        double fx[num_bodies];
        double fy[num_bodies];
        double fz[num_bodies];
        for(int j=0; j<num_bodies; j++){
            fx[j] = fy[j] = fz[j] = 0;
            for(int k=0; k<num_bodies; k++){
                if(k != j){
                    double f_x, f_y, f_z;
                    calc_force(bodies[j], bodies[k], &f_x, &f_y, &f_z);
                    fx[j] += f_x;
                    fy[j] += f_y;
                    fz[j] += f_z;
                }
            }
        }

        //update position and velocity of each body
        for(int j=0; j<num_bodies; j++){
            update(bodies[j], fx[j], fy[j], fz[j], dt);
        }

        //print out the location of the earth and moon
        printf("Day %d: Earth (%.2f, %.2f, %.2f), Moon (%.2f, %.2f, %.2f)\n", i+1, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
    }

    return 0;
}