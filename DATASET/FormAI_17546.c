//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <math.h>

/* Define Circuit Parameters */
#define R1 10000    /*Resistor 1*/
#define R2 20000    /*Resistor 2*/
#define R3 15000    /*Resistor 3*/
#define C1 0.0001   /*Capacitor 1*/
#define C2 0.00005  /*Capacitor 2*/

int main()
{
    /* Define simulation parameters */
    double t, dt, v_in, v_out, v_c1, v_c2, i_c1, i_c2, i_r1;

    dt = 0.0001;   /* Time step */
    t = 0;         /* Start time */
    v_in = 5.0;    /* Input Voltage */

    /* Initialize state variables */
    v_out = 0.0;
    v_c1 = 0.0;
    v_c2 = 0.0;
    i_c1 = 0.0;
    i_c2 = 0.0;
    i_r1 = 0.0;

    /* Loop through time steps */
    while(t < 0.1)
    {
        /* Calculate Circuit Parameters */
        i_c1 = C1 * ((v_in - v_c1) / R1);
        i_r1 = i_c1;
        i_c2 = C2 * ((v_c1 - v_c2) / R2);
        v_out = v_c2;
        v_c1 += (i_r1 - i_c1) * dt;   /* Update Capacitor 1 Voltage */
        v_c2 += (-i_c2) * dt;         /* Update Capacitor 2 Voltage */
        v_in = 5.0 * sin(2 * M_PI * 1000 * t);  /* Update Input Voltage */

        /* Print Output */
        printf("t = %f, v_in = %f, v_out = %f\n", t, v_in, v_out);

        /* Increment time step */
        t += dt;
    }

    return 0;
}