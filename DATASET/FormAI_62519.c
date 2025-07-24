//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define PI 3.14
#define G 0.0001
#define DT 0.1

struct vec{
    double x, y;
};

struct planet{
    char name[20];
    double mass;
    double radius;
    struct vec pos;
    struct vec vel;
};

struct planet create_planet(char* name, double mass, double radius, struct vec pos, struct vec vel){
    struct planet p; 
    p.mass = mass;
    p.radius = radius;
    p.pos = pos;
    p.vel = vel;
    strcpy(p.name, name);
    return p; 
}

struct vec force(struct planet p1, struct planet p2){
    double r = sqrt(pow(p1.pos.x - p2.pos.x, 2) + pow(p1.pos.y - p2.pos.y, 2));
    double m = p1.mass * p2.mass;
    double F = G * m / pow(r, 2);
    struct vec dir = { (p2.pos.x - p1.pos.x)/r, (p2.pos.y - p1.pos.y)/r };
    struct vec f = { dir.x * F, dir.y * F };
    return f;
}

void update(struct planet *p, struct vec f, int n){
    p->vel.x += (f.x / p->mass) * DT;
    p->vel.y += (f.y / p->mass) * DT;
    p->pos.x += p->vel.x * DT;
    p->pos.y += p->vel.y * DT;
    printf("Planet %d:\tx = %lf\ty = %lf\n", n, p->pos.x, p->pos.y);
}

int main(){
    struct planet sun = create_planet("Sun", 1989.0, 695510.0, (struct vec){0, 0}, (struct vec){0, 0});
    struct planet earth = create_planet("Earth", 5.97, 6371.0, (struct vec){150000000, 0}, (struct vec){0, 30000});
    struct planet mars = create_planet("Mars", 6.41693, 3389.5, (struct vec){0, -227900000}, (struct vec){24000, 0});
    
    int i = 0;
    while(1){
        printf("\n\nIteration %d:\n", i);
        struct vec F1 = force(sun, earth);
        struct vec F2 = force(sun, mars);
        struct vec F3 = force(earth, mars);
        printf("Force on Earth: x = %lf\ty = %lf\n", F1.x + F3.x, F1.y + F3.y);
        printf("Force on Mars: x = %lf\ty = %lf\n", F2.x - F3.x, F2.y - F3.y);

        update(&sun, (struct vec){-(F1.x + F2.x), -(F1.y + F2.y)}, 1);
        update(&earth, (struct vec){F1.x - F3.x, F1.y - F3.y}, 2);
        update(&mars, (struct vec){F2.x + F3.x, F2.y + F3.y}, 3);

        i++;
    }

    return 0;
}