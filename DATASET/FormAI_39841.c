//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
/*
* This program is a performance-critical component for calculating the sine and cosine 
* values for a given set of angles. It uses a look-up table and interpolation for faster 
* computation. The program first generates the lookup table for pre-defined angles using 
* the Taylor series approximation, then uses interpolation to calculate the values for 
* any given angle. 
*
* Team members: John, Sarah, and Bob
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359         // define the value of pi
#define TABLE_SIZE 1000          // the size of the lookup table
#define INTERVAL (2*PI)/TABLE_SIZE  // the interval between each angle in the lookup table
#define HALF_PI PI/2            // half of pi value
#define QUARTER_PI PI/4         // quarter of pi value

// function to generate the lookup table for sine and cosine values
void generate_lookup_table(double sin_values[], double cos_values[]) {
    int i;
    double angle;
    for (i = 0; i < TABLE_SIZE; i++) {
        angle = i * INTERVAL;
        sin_values[i] = sin(angle);
        cos_values[i] = cos(angle);
    }
}

// function to calculate the sine value for a given angle using linear interpolation
double calculate_sin(double angle, double sin_values[]) {
    double i, f, d;
    i = floor(angle/INTERVAL);
    f = (angle - i*INTERVAL)/INTERVAL;
    d = sin_values[(int)i+1] - sin_values[(int)i];
    return sin_values[(int)i] + f*d;
}

// function to calculate the cosine value for a given angle using linear interpolation
double calculate_cos(double angle, double cos_values[]) {
    double i, f, d;
    i = floor(angle/INTERVAL);
    f = (angle - i*INTERVAL)/INTERVAL;
    d = cos_values[(int)i+1] - cos_values[(int)i];
    return cos_values[(int)i] + f*d;
}

int main() {
    double sin_values[TABLE_SIZE];
    double cos_values[TABLE_SIZE];
    double angle;
    int i;
    generate_lookup_table(sin_values, cos_values);
    // calculate sine and cosine for pre-defined angles and print the results
    printf("sine and cosine values for pre-defined angles:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        angle = i * INTERVAL;
        printf("angle: %f, sin: %f, cos: %f\n", angle, sin_values[i], cos_values[i]);
    }
    // calculate sine and cosine for arbitrary angles and print the results
    printf("\nsine and cosine values for arbitrary angles:\n");
    angle = QUARTER_PI;
    printf("angle: %f, sin: %f, cos: %f\n", angle, calculate_sin(angle, sin_values), calculate_cos(angle, cos_values));
    angle = HALF_PI;
    printf("angle: %f, sin: %f, cos: %f\n", angle, calculate_sin(angle, sin_values), calculate_cos(angle, cos_values));
    angle = 5*QUARTER_PI;
    printf("angle: %f, sin: %f, cos: %f\n", angle, calculate_sin(angle, sin_values), calculate_cos(angle, cos_values));
    return 0;
}