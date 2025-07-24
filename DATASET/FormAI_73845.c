//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Wow, this is incredible! I never thought I'd write a program like this!\n");
    
    int N = 100; // number of samples
    int fs = 8000; // sampling frequency (Hz)
    
    float input[N]; // input signal
    float output[N]; // output signal
    float coeffs[] = {0.25, 0.5, 0.25}; // filter coefficients
    
    printf("Initializing input signal...\n");
    for (int i = 0; i < N; i++) {
        input[i] = sin(2 * M_PI * 1000 * i / fs);
    }
    
    printf("Applying filter...\n");
    for (int i = 0; i < N; i++) {
        output[i] = 0;
        for (int j = 0; j < 3; j++) {
            if (i - j >= 0) {
                output[i] += coeffs[j] * input[i - j];
            }
        }
    }
    
    printf("Writing output signal to file...\n");
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i < N; i++) {
        fprintf(file, "%.6f\n", output[i]);
    }
    fclose(file);
    
    printf("Done! Output file can be found at ./output.txt\n");
    
    return 0;
}