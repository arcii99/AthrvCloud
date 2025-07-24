//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    printf("Welcome to the Shocking Solar System Simulation Program!\n");
    printf("Get ready to have your mind blown!\n");

    //Initializing variables
    double G = 6.6743 * pow(10,-11);
    double m1 = 1.9885 * pow(10,30); //mass of sun
    double m2 = 5.9722 * pow(10,24); //mass of earth
    double r = 149.6 * pow(10,9); //distance of earth from sun
    double t = 365.25 * 24 * 3600; //time period of earth
    double a = (G * m1)/(r*r); //acceleration of earth

    //Calculating the position, velocity and acceleration of earth
    double x = r;
    double y = 0;
    double vx = 0;
    double vy = sqrt(a*r);
    double ax = -a;
    double ay = 0;

    //Printing initial values
    printf("\nInitial values of:\n");
    printf("x = %lf km\n", x/1000);
    printf("y = %lf km\n", y/1000);
    printf("vx = %lf km/s\n", vx/1000);
    printf("vy = %lf km/s\n", vy/1000);
    printf("ax = %lf m/s^2\n", ax);
    printf("ay = %lf m/s^2\n", ay);

    //Simulation
    int i;
    for(i=1; i<=t; i++)
    {
        x += vx + 0.5 * ax * pow(2, i);
        y += vy + 0.5 * ay * pow(2, i);
        double r = sqrt(x*x + y*y);
        double a = (G * m1)/(r*r);
        ax = -a * x / r;
        ay = -a * y / r;
        vx += ax * pow(2, i);
        vy += ay * pow(2, i);
    }

    //Printing final values
    printf("\nFinal values of:\n");
    printf("x = %lf km\n", x/1000);
    printf("y = %lf km\n", y/1000);
    printf("vx = %lf km/s\n", vx/1000);
    printf("vy = %lf km/s\n", vy/1000);
    printf("ax = %lf m/s^2\n", ax);
    printf("ay = %lf m/s^2\n", ay);

    printf("\nWow, that was an amazing simulation of the Solar System!\n");
    printf("The Earth has completed its orbit around the Sun in %lf seconds.\n", t);
    printf("Thanks for running this program. See you soon!\n");

    return 0;
}