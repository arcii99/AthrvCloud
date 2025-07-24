//FormAI DATASET v1.0 Category: Scientific ; Style: content
/* This program demonstrates the use of a scientific equation to calculate
the energy of a photon given its frequency and Planck's constant */

#include <stdio.h>
#include <math.h>

#define PLANCK_CONSTANT 6.62607004e-34 /* meters squared kilograms per second */

int main()
{
    double frequency; 
    double energy; 

    printf("Enter the frequency of the photon in hertz: ");
    scanf("%lf", &frequency);

    energy = PLANCK_CONSTANT * frequency;

    printf("The energy of the photon is %e joules.\n", energy);
    return 0;
}