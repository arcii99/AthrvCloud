//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>
#define G 6.6743E-11

struct Object{       //defining a structure for celestial objects
    char name[20];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
    double acceleration[3];
};

typedef struct Object Object;

void update_velocity(Object *obj, double time_step){
    for(int i=0;i<3;i++){
        obj->velocity[i] += obj->acceleration[i]*time_step;
    }
}

void update_position(Object *obj, double time_step){
    for(int i=0;i<3;i++){
        obj->position[i] += obj->velocity[i]*time_step + 0.5*obj->acceleration[i]*time_step*time_step;
    }
}

void apply_gravity(Object *obj1, Object *obj2){
    double dx=obj2->position[0]-obj1->position[0];
    double dy=obj2->position[1]-obj1->position[1];
    double dz=obj2->position[2]-obj1->position[2];

    double distance=sqrt(dx*dx + dy*dy + dz*dz);

    double force= G*obj1->mass*obj2->mass/(distance*distance);
    double fx= force*dx/distance;
    double fy= force*dy/distance;
    double fz= force*dz/distance;

    obj1->acceleration[0]+=fx/obj1->mass;
    obj1->acceleration[1]+=fy/obj1->mass;
    obj1->acceleration[2]+=fz/obj1->mass;

    obj2->acceleration[0]-=fx/obj2->mass;
    obj2->acceleration[1]-=fy/obj2->mass;
    obj2->acceleration[2]-=fz/obj2->mass;
}

void print_info(Object *obj, int time){
    printf("%s \t%.2f \t(%.2f, %.2f, %.2f) \t",obj->name,obj->mass,obj->position[0],obj->position[1],obj->position[2]);
    printf("\t(%.2f, %.2f, %.2f) \t(%.2f, %.2f, %.2f)\n", obj->velocity[0],obj->velocity[1],obj->velocity[2], obj->acceleration[0],obj->acceleration[1],obj->acceleration[2]);
}

int main(){
    Object objs[5]={
        {"Sun",1.989E30,696340E3,{0,0,0},{0,0,0},{0,0,0}},
        {"Mercury",3.3011E23,2439700,{0,0,57909170000},{47362,0,0},{0,0,0}},
        {"Venus",4.8675E24,6051800,{0,0,108208930000},{35020,0,0},{0,0,0}},
        {"Earth",5.97237E24,6371000,{0,0,149597890000},{29300,0,0},{0,0,0}},
        {"Mars",6.4171E23,3389500,{0,0,227936640000},{21970,0,0},{0,0,0}}
    };

    int total_time=365*24*3600;
    int time_step=3600*24;

    for(int t=0; t<total_time; t+=time_step){
        for(int i=0;i<5;i++){
            for(int j=i+1;j<5;j++){
                apply_gravity(&objs[i],&objs[j]);
            }
        }

        for(int i=0;i<5;i++){
            update_velocity(&objs[i],time_step);
            update_position(&objs[i],time_step);
            print_info(&objs[i],t);
        }
    }

    return 0;
}