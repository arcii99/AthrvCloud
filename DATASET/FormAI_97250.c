//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
#include<stdio.h>
#include<math.h>

// structure to store the parameters of the planet
struct Planet{
    char name[20];
    float mass;
    float radius;
    float x;
    float y;
    float vx;
    float vy;
};

// function to calculate the gravitational force between two planets
float gravitationalForce(float mass1, float mass2, float distance){
    float constant = 6.67*pow(10,-11); // gravitational constant
    return constant*mass1*mass2/pow(distance,2);
}

int main(){

    // initializing the array of planets
    struct Planet planets[3] = {
        {"Earth", 5.97*pow(10,24), 6.371*pow(10,6), 0, 0, 0, 0},
        {"Moon", 7.34*pow(10,22), 1.737*pow(10,6), 3.844*pow(10,8), 0, 0, 1022},
        {"Mars", 6.39*pow(10,23), 3.371*pow(10,6), 2.279*pow(10,11), 0, 0, 0}
    };

    float time = 0.0; // initializing time to zero
    float deltaT = 3600*24; // time interval of one day
    float G = 6.67*pow(10,-11); // gravitational constant
    
    // simulating the motion of planets for 365 days
    for(int i=0; i<365; i++){
        printf("Day: %d\n", i+1);
        for(int j=0; j<3; j++){

            // calculating the net gravitational force acting on the planet
            float forceX = 0.0;
            float forceY = 0.0;
            for(int k=0; k<3; k++){
                if(k!=j){
                    float distance = sqrt(pow(planets[j].x-planets[k].x,2)+pow(planets[j].y-planets[k].y,2));
                    float force = gravitationalForce(planets[j].mass, planets[k].mass, distance);
                    float angle = atan2(planets[k].y-planets[j].y, planets[k].x-planets[j].x);
                    forceX += force*cos(angle);
                    forceY += force*sin(angle);
                }
            }

            // calculating the acceleration
            float ax = forceX/planets[j].mass;
            float ay = forceY/planets[j].mass;

            // calculating the new velocity
            planets[j].vx += ax*deltaT;
            planets[j].vy += ay*deltaT;

            // calculating the new position
            planets[j].x += planets[j].vx*deltaT;
            planets[j].y += planets[j].vy*deltaT;

            printf("%s: X: %f Y: %f VX: %f VY: %f\n", planets[j].name, planets[j].x, planets[j].y, planets[j].vx, planets[j].vy);
        }

        // increasing time by one day
        time += deltaT;
    }

    return 0;
}