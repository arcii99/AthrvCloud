//FormAI DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int main() {

    // Variables
    double x, y, z, r;
    double x0 = 0.5, y0 = -0.5, z0 = 0;
    double k = 0.02;

    // Get input from user
    printf("Enter the coordinates of the point (x,y,z): \n");
    scanf("%lf %lf %lf", &x, &y, &z);

    // Calculate distance from point to origin
    r = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

    // Calculate electric field due to point charge
    double Ex = k * (x - x0) / pow(r,3);
    double Ey = k * (y - y0) / pow(r,3);
    double Ez = k * (z - z0) / pow(r,3);

    // Output electric field in Cartesian coordinates
    printf("Electric field at point (%0.2lf,%0.2lf,%0.2lf):\n", x, y, z);
    printf("E_x = %0.5lf N/C\n", Ex);
    printf("E_y = %0.5lf N/C\n", Ey);
    printf("E_z = %0.5lf N/C\n", Ez);

    return 0;
}