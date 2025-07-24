//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//structure for planets
struct Planets {
    char name[20];
    double radius;
    double mass;
    double x, y, z;
    double vx, vy, vz;
    struct Planets *next;
};
typedef struct Planets planet;

//define gravitational constant
const double G = 6.674 * pow(10, -11);

//function to initialize planets
planet* init_planet(char* name, double radius, double mass, double x, double y, double z, double vx, double vy, double vz){
    planet* newPlanet = (planet*)malloc(sizeof(planet));
    strncpy(newPlanet->name, name, sizeof(newPlanet->name)-1);
    newPlanet->radius = radius;
    newPlanet->mass = mass;
    newPlanet->x = x;
    newPlanet->y = y;
    newPlanet->z = z;
    newPlanet->vx = vx;
    newPlanet->vy = vy;
    newPlanet->vz = vz;
    newPlanet->next = NULL;
    return newPlanet;
}

//function to add planets to the linked list
void add_planet(planet **root, char* name, double radius, double mass, double x, double y, double z, double vx, double vy, double vz){
    if(*root == NULL){
        *root = init_planet(name, radius, mass, x, y, z, vx, vy, vz);
    }
    else {
        planet* curr = *root;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = init_planet(name, radius, mass, x, y, z, vx, vy, vz);
    }
}

//function to remove a planet from the linked list
void remove_planet(planet **root, char* name){
    planet *curr = *root;
    planet *prev = NULL;
    while(curr != NULL){
        if(strcmp(curr->name, name) == 0){
            if(prev == NULL) {
                *root = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

//function to calculate the force due gravitation between two planets
void get_gravity(planet* p1, planet* p2, double *fx, double *fy, double *fz){
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));

    double f = (G * p1->mass * p2->mass)/(r*r);
    *fx += f*dx/r;
    *fy += f*dy/r;
    *fz += f*dz/r;
}

//function to calculate the force on a planet due to all other planets
void calculate_forces(planet* root){
    planet *p1 = root;
    planet *p2;
    double fx, fy, fz;
    while(p1 != NULL){
        fx = fy = fz = 0;
        p2 = root;
        while(p2 != NULL){
            if(p1 != p2){
                get_gravity(p1, p2, &fx, &fy, &fz);
            }
            p2 = p2->next;
        }
        p1->vx += fx/p1->mass;
        p1->vy += fy/p1->mass;
        p1->vz += fz/p1->mass;
        p1 = p1->next;
    }
}

//function to update the positions of the planets based on the forces
void update_positions(planet* root, double t){
    planet* curr = root;
    while(curr != NULL){
        curr->x += curr->vx*t;
        curr->y += curr->vy*t;
        curr->z += curr->vz*t;
        curr = curr->next;
    }
}

//main program
int main()
{
    planet* root = NULL;

    //add planets to the simulation
    add_planet(&root, "Sun", 696340000, 1.989*pow(10, 30), 0, 0, 0, 0, 0, 0);
    add_planet(&root, "Earth", 6371000, 5.97*pow(10, 24), 147110000000, 0, 0, 0, 29000, 0);
    add_planet(&root, "Mars", 3389000, 6.39*pow(10, 23), 227940000000, 0, 0, 0, 24000, 0);

    //simulation loop for 365 days
    for(int i=0; i<365; i++){
        calculate_forces(root);
        update_positions(root, 86400);
    }

    //print final positions of planets
    planet* curr = root;
    while(curr != NULL){
        printf("%s at (%.2f, %.2f, %.2f)\n", curr->name, curr->x, curr->y, curr->z);
        curr = curr->next;
    }

    //remove Mars from the simulation
    remove_planet(&root, "Mars");

    //simulation loop for 365 days without Mars
    for(int i=0; i<365; i++){
        calculate_forces(root);
        update_positions(root, 86400);
    }

    //print final positions of planets without Mars
    curr = root;
    while(curr != NULL){
        printf("%s at (%.2f, %.2f, %.2f)\n", curr->name, curr->x, curr->y, curr->z);
        curr = curr->next;
    }

    return 0;
}