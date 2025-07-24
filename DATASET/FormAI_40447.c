//FormAI DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int Fs = 44100; // Sampling frequency
    int Fc = 1000; // Carrier frequency
    int Fm = 150; // Modulating frequency
    int N = 44100; // Sample length
    double amplitude = 1.0; // Modulation amplitude
    double mod[N], carrier[N], output[N];
    
    for(int i=0; i<N; i++){
        mod[i] = amplitude * sin(2 * PI * Fm * i / Fs);
        carrier[i] = sin(2 * PI * Fc * i / Fs);
        output[i] = mod[i] * carrier[i];
    }
    
    // Output to text file for analysis
    FILE *fp;
    fp = fopen("DSP_Output.txt", "w");
    for(int i=0; i<N; i++){
        fprintf(fp, "%.6f\n", output[i]);
    }
    fclose(fp);
    
    printf("Signal processing complete. Output written to DSP_Output.txt\n");
    
    return 0;
}