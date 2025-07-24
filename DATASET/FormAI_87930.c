//FormAI DATASET v1.0 Category: Physics simulation ; Style: random
#include<stdio.h>
#include<math.h>
#define G 6.67408e-11 //gravitational constant

//function to calculate gravitational force
double gravitationalForce(double m1, double m2, double r){
    return (G * m1 * m2) / pow(r, 2);
}

int main(){
    double mass1, mass2, radius, distance, force;
    printf("Enter the mass of object 1 (in kg): ");
    scanf("%lf", &mass1);
    printf("Enter the mass of object 2 (in kg): ");
    scanf("%lf", &mass2);
    printf("Enter the distance between the two objects (in meters): ");
    scanf("%lf", &distance);

    radius = distance / 2.0; //assuming the two objects are evenly spaced
    force = gravitationalForce(mass1, mass2, radius);

    printf("Gravitational force between the two objects is: %.2lf N\n", force);
    return 0;
}