//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: romantic
#include <stdio.h>
#include <math.h>

int main()
{
    float G = 6.67 * pow(10, -11);
    float m1, m2, r, F, a;
    printf("Enter the mass of the first planet (in kg): ");
    scanf("%f", &m1);
    printf("Enter the mass of the second planet (in kg): ");
    scanf("%f", &m2);
    printf("Enter the distance between the two planets (in meters): ");
    scanf("%f", &r);
    
    F = G * ((m1 * m2) / pow(r, 2)); //calculate gravitational force
    a = F / m2; //calculate acceleration
    printf("The gravitational force between the two planets is %.2f N.\n", F);
    printf("The acceleration of the second planet is %.2f m/s^2.\n", a);

    return 0;
}