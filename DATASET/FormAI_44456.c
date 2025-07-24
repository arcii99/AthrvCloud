//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14159

struct planet{
    char name[20];
    double orbit_a, orbit_b, theta, speed;
};

int main(){
    int days, i;
    printf("Welcome to the Solar System Simulation!\n");
    printf("Enter number of days to simulate: ");
    scanf("%d",&days);

    struct planet sun = {"Sun",0,0,0,0};
    struct planet earth = {"Earth",149.6,149.6,0,360.0/365.0};
    struct planet mars = {"Mars",227.9,207.3,0,360.0/687.0};
    struct planet jupiter = {"Jupiter",778.5,740.5,0,360.0/4333.0};
    struct planet saturn = {"Saturn",1433.5,1352.6,0,360.0/10759.0};
    struct planet uranus = {"Uranus",2872.5,2741.3,0,360.0/30687.0};
    struct planet neptune = {"Neptune",4495.1,4444.5,0,360.0/60190.0};

    struct planet planets[7] = {sun, earth, mars, jupiter, saturn, uranus, neptune};

    double curr_time = 0.0;
    double delta_time = 0.001;

    while(curr_time < days){
        for(i=1; i<=6; i++){
            struct planet p = planets[i];
            p.theta += p.speed*delta_time*2*pi;
            double x = p.orbit_a * cos(p.theta);
            double y = p.orbit_b * sin(p.theta);
            printf("Time:%lf, Planet:%s, X: %lf, Y:%lf\n", curr_time, p.name, x, y);
        }
        printf("--------------------------------------\n");
        curr_time += delta_time;
    }
    return 0;
}