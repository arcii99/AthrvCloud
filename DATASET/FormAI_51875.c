//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Declare the constants needed for circuit simulation */
#define PI 3.14159265
#define R1 1000
#define R2 5000
#define C 0.00001
#define VIN 5

/* Function to calculate the voltage across capacitor */
float voltage_across_capacitor(float t){
    float v = (VIN*R2)/(sqrt(pow(R1+R2,2)+pow(R2*C*(2*PI*t),2)));
    return v;
}

/* Function to print the voltage at each iteration */
void print_voltage(float v){
    printf("Voltage: %f\n", v);
}

int main(){
    float t, v;

    /* Run simulation for 10 cycles */
    for(int i=0;i<10;i++){
        for(t=0;t<=2*PI;t+=0.01){
            v = voltage_across_capacitor(t);
            print_voltage(v);
        }
    }
    return 0;
}