//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

// Defining the circuit parameters
float r = 1000.0;
float c = 1e-9; 
float dt = 1e-13; 

// Defining the input signal
float vin(float t){
    float freq = 1.0e6;
    return sin(2*PI*freq*t);
}

// Defining the circuit equation
float vout(float v_prev, float vin, float t){
    return v_prev + ((vin - v_prev)/(r*c))*dt;
}

int main(){
    // Initializing variables
    float t = 0.0, v = 0.0, v_prev = 0.0;

    // Running the simulation for 1000 time steps
    for(int i = 0; i < 1000; i++){
        t = i*dt;
        v = vout(v_prev, vin(t), t);
        v_prev = v;

        // Printing the output voltage
        printf("%f\n", v);
    }

    return 0;
}