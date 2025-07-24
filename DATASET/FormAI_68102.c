//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ada Lovelace
// Ada Lovelace style Digital Signal Processing program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double real;
    double imag;
} complex;

void dft(complex* input, int size, complex* output) {
    for(int i = 0; i < size; i++) {
        output[i].real = 0;
        output[i].imag = 0;
        for(int j = 0; j < size; j++) {
            output[i].real += input[j].real * cos(2 * PI * i * j / size) + input[j].imag * sin(2 * PI * i * j / size);
            output[i].imag += input[j].imag * cos(2 * PI * i * j / size) - input[j].real * sin(2 * PI * i * j / size);
        }
    }
}

void inverse_dft(complex* input, int size, complex* output) {
    for(int i = 0; i < size; i++) {
        output[i].real = 0;
        output[i].imag = 0;
        for(int j = 0; j < size; j++) {
            output[i].real += input[j].real * cos(-2 * PI * i * j / size) + input[j].imag * sin(-2 * PI * i * j / size);
            output[i].imag += input[j].imag * cos(-2 * PI * i * j / size) - input[j].real * sin(-2 * PI * i * j / size);
        }
        output[i].real /= size;
        output[i].imag /= size;
    }
}

int main() {
    int size = 8;
    complex input[size], output[size], inverse[size];
    
    // Creating a sample complex signal
    input[0].real = 1; input[0].imag = 2;
    input[1].real = 3; input[1].imag = 4;
    input[2].real = 5; input[2].imag = 6;
    input[3].real = 7; input[3].imag = 8;
    input[4].real = 9; input[4].imag = 10;
    input[5].real = 11; input[5].imag = 12;
    input[6].real = 13; input[6].imag = 14;
    input[7].real = 15; input[7].imag = 16;

    // Printing the input signal
    printf("Input signal: \n");
    for(int i = 0; i < size; i++) {
        printf("%lf + %lfi\n", input[i].real, input[i].imag);
    }

    // Performing DFT
    dft(input, size, output);

    // Printing the DFT results
    printf("DFT output: \n");
    for(int i = 0; i < size; i++) {
        printf("%lf + %lfi\n", output[i].real, output[i].imag);
    }

    // Performing inverse DFT
    inverse_dft(output, size, inverse);

    // Printing the inverse DFT results
    printf("Inverse DFT output: \n");
    for(int i = 0; i < size; i++) {
        printf("%lf + %lfi\n", inverse[i].real, inverse[i].imag);
    }

    return 0;
}