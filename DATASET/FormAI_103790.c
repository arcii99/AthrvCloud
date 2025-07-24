//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    float inputSignal[100], outputSignal[100];
    int i, j, k, N, M;

    printf("Enter the number of samples in input signal: ");
    scanf("%d", &N);

    printf("Enter the input signal: ");
    for (i = 0; i < N; i++) {
        scanf("%f", &inputSignal[i]);
    }

    printf("Enter the number of samples in FIR filter: ");
    scanf("%d", &M);

    float h[M];
    printf("Enter the filter coefficients: ");
    for (j = 0; j < M; j++) {
        scanf("%f", &h[j]);
    }

    // zero-padding input signal for linear convolution
    float paddedInputSignal[N+M-1];
    for (k = 0; k < N+M-1; k++) {
        if (k < N) {
            paddedInputSignal[k] = inputSignal[k];
        }
        else {
            paddedInputSignal[k] = 0;
        }
    }

    // performing linear convolution
    for (i = 0; i < N+M-1; i++) {
        outputSignal[i] = 0;
        for (j = 0; j < M; j++) {
            if (i-j >= 0 && i-j < N+M-1) {
                outputSignal[i] += paddedInputSignal[i-j] * h[j];
            }
        }
    }

    // printing output signal
    printf("\nOutput signal after filtering: ");
    for (i = 0; i < N+M-1; i++) {
        printf("%.2f ", outputSignal[i]);
    }
    printf("\n");

    // computing DFT of input signal and output signal
    float Xr[N], Xi[N], Yr[N], Yi[N];
    for (i = 0; i < N; i++) {
        Xr[i] = inputSignal[i];
        Xi[i] = 0;
        Yr[i] = outputSignal[i];
        Yi[i] = 0;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            float angle = 2 * PI * i * j / N;
            float cosine = cos(angle);
            float sine = sin(angle);
            float tempR = Xr[j] * cosine - Xi[j] * sine;
            float tempI = Xr[j] * sine + Xi[j] * cosine;
            Xr[j] = tempR;
            Xi[j] = tempI;

            tempR = Yr[j] * cosine - Yi[j] * sine;
            tempI = Yr[j] * sine + Yi[j] * cosine;
            Yr[j] = tempR;
            Yi[j] = tempI;
        }
    }

    // computing magnitude response of filter using DFT
    float Hr[N], Hi[N];
    for (i = 0; i < N; i++) {
        Hr[i] = h[i];
        Hi[i] = 0;
    }
    for (i = 0; i < N; i++) {
        float angle = -2 * PI * i / N;
        float cosine = cos(angle);
        float sine = sin(angle);
        float tempR = Hr[i] * cosine - Hi[i] * sine;
        float tempI = Hr[i] * sine + Hi[i] * cosine;
        Hr[i] = tempR;
        Hi[i] = tempI;
    }
    float magH[N];
    for (i = 0; i < N; i++) {
        magH[i] = sqrt(Hr[i]*Hr[i] + Hi[i]*Hi[i]);
    }

    // computing magnitude and phase response of input signal and output signal
    float magX[N], magY[N], phaseX[N], phaseY[N];
    for (i = 0; i < N; i++) {
        magX[i] = sqrt(Xr[i]*Xr[i] + Xi[i]*Xi[i]);
        magY[i] = sqrt(Yr[i]*Yr[i] + Yi[i]*Yi[i]);
        phaseX[i] = atan2(Xi[i], Xr[i]);
        phaseY[i] = atan2(Yi[i], Yr[i]);
    }

    // printing frequency response graphs
    printf("\nFrequency Response of Filter (magnitude and phase)\n");
    printf("Freq (Hz)\tMag(Hz)\tPhase(Degrees)\n");
    for (i = 0; i < N/2; i++) {
        float freq = (float)i / N;
        printf("%.2f\t\t%.2f\t\t%.2f\n", freq, magH[i], 180*atan2(Hi[i], Hr[i])/PI);
    }
    printf("\nFrequency Response of Input Signal (magnitude and phase)\n");
    printf("Freq (Hz)\tMag(Hz)\tPhase(Degrees)\n");
    for (i = 0; i < N/2; i++) {
        float freq = (float)i / N;
        printf("%.2f\t\t%.2f\t\t%.2f\n", freq, magX[i], phaseX[i]*180/PI);
    }
    printf("\nFrequency Response of Output Signal (magnitude and phase)\n");
    printf("Freq (Hz)\tMag(Hz)\tPhase(Degrees)\n");
    for (i = 0; i < N/2; i++) {
        float freq = (float)i / N;
        printf("%.2f\t\t%.2f\t\t%.2f\n", freq, magY[i], phaseY[i]*180/PI);
    }

    return 0;
}