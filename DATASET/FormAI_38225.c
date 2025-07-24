//FormAI DATASET v1.0 Category: Computer Biology ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

/* This program calculates the population growth of bacteria over time
   using the exponential growth equation: y = Ce^(rt), where y is the 
   population size, C is the initial population size, r is the growth rate,
   and t is the time in hours. */

int main()
{
    double C, r, t;     // declaring variables for the equation
    double y;           // declaring variable for the population size

    printf("Enter the initial population size (C): ");
    scanf("%lf", &C);   // input the initial population

    printf("Enter the growth rate (r) in terms of e: ");
    scanf("%lf", &r);   // input the growth rate

    printf("Enter the time (t) in hours: ");
    scanf("%lf", &t);   // input the time

    y = C * exp(r * t); // calculating the population size

    printf("The population size is %.2f\n", y); // output the result

    return 0;           // return 0 to indicate success
}