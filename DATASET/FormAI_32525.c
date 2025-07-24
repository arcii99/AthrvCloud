//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include<stdio.h>
#include<math.h>

struct planet{
    char name[50];
    double mass;
    double x,y,z;
    double vx,vy,vz;
};

struct planet create_planet(char name[],double mass,double x,double y,double z,double vx,double vy,double vz){
    struct planet p;
    strcpy(p.name,name);
    p.mass = mass;
    p.x = x;
    p.y = y;
    p.z = z;
    p.vx = vx;
    p.vy = vy;
    p.vz = vz;
    return p;
}

void apply_gravity(struct planet *p1, struct planet *p2){
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force = p1->mass * p2->mass / (distance * distance);
    double fx = force * dx / distance;
    double fy = force * dy / distance;
    double fz = force * dz / distance;
    p1->vx += fx / p1->mass;
    p1->vy += fy / p1->mass;
    p1->vz += fz / p1->mass;
    p2->vx -= fx / p2->mass;
    p2->vy -= fy / p2->mass;
    p2->vz -= fz / p2->mass;
}

void move_planet(struct planet *p, double time_step){
    p->x += p->vx * time_step;
    p->y += p->vy * time_step;
    p->z += p->vz * time_step;
}

void simulate(double time_step){
    struct planet p1 = create_planet("Earth",5.97E24,0,0,0,0,0,0);
    struct planet p2 = create_planet("Moon",7.35E22,3.84E8,0,0,0,1022,0);
    struct planet p3 = create_planet("Mars",6.39E23,0,-2.28E11,0,24043,0,0);
    struct planet p4 = create_planet("Jupiter",1.898E27,0,0,7.785E11,13107,0,0);

    int iterations = (int)(365 * 24 * 60 * 60 / time_step);
    for(int i=0;i<iterations;i++){
        apply_gravity(&p1,&p2);
        apply_gravity(&p1,&p3);
        apply_gravity(&p1,&p4);
        apply_gravity(&p2,&p3);
        apply_gravity(&p2,&p4);
        apply_gravity(&p3,&p4);
        move_planet(&p1,time_step);
        move_planet(&p2,time_step);
        move_planet(&p3,time_step);
        move_planet(&p4,time_step);
        printf("Iteration %d: Earth (%lf,%lf,%lf)\n",i,p1.x,p1.y,p1.z);
        printf("             Moon (%lf,%lf,%lf)\n",p2.x,p2.y,p2.z);
        printf("             Mars (%lf,%lf,%lf)\n",p3.x,p3.y,p3.z);
        printf("             Jupiter (%lf,%lf,%lf)\n",p4.x,p4.y,p4.z);
    }
}

int main(){
    double time_step = 3600;
    simulate(time_step);
    return 0;
}