//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100 // length of input signal
#define M 5 // filter order
#define FS 44100 // sampling frequency
#define FREQ 1000 // frequency of input signal

float inputSignal[N];
float outputSignal[N];
float filterCoeff[M] = {0.1, 0.2, 0.3, 0.2, 0.1}; // filter coefficients

void generateInputSignal();
void applyFilter();

int main() {
    generateInputSignal();
    applyFilter();

    return 0;
}

void generateInputSignal() {
    for(int i = 0; i < N; i++) {
        inputSignal[i] = sin(2*M_PI*FREQ*i/FS);
    }
}

void applyFilter() {
    for(int i = 0; i < N; i++) {
        float output = 0;
        for(int j = 0; j < M; j++) {
            int index = i - j;
            if(index >= 0) {
                output += inputSignal[index] * filterCoeff[j];
            }
        }
        outputSignal[i] = output;
    }

    printf("Input Signal: \n");
    for(int i = 0; i < N; i++) {
        printf("%.4f ", inputSignal[i]);
    }

    printf("\n\n");

    printf("Output Signal: \n");
    for(int i = 0; i < N; i++) {
        printf("%.4f ", outputSignal[i]);
    }

    printf("\n");
}