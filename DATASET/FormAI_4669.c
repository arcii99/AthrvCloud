//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>

// define constants for calculation
#define R1 1000
#define R2 1500
#define C 0.00001
#define V1 5

// function to calculate voltage across the capacitor
float calc_v_cap(float t, float v_in)
{
    float v_cap;
    v_cap = V1 - ((V1 - v_in) * exp((-1)/(R1*C)*t)) - v_in;
    return v_cap;
}

int main()
{
    // define variables for simulation
    float t = 0;
    float v_c = 0;
    float v_in = 0;
    float i = 0;

    // simulation loop
    while(t < 0.2)
    {
        // print current time and voltage across capacitor
        printf("t = %f sec, Vc = %f V\n", t, v_c);

        // calculate input voltage
        if (t < 0.1) v_in = V1;
        else v_in = 0;

        // calculate current through resistor R2
        i = (v_in - v_c) / R2;

        // update voltage across capacitor
        v_c += i * (t - (t-0.001));

        // update time
        t += 0.001;
    }
    
    return 0;
}