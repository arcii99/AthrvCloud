//FormAI DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

#define N 64 //Number of samples
#define PI 3.1415926535

int main(){
    float input_signal[N];
    float output_signal[N];
    float impulse_response[N];
    float omega, inv_omega;
    int n, k;

    //Generate input signal
    for(n = 0; n < N; n++){
        input_signal[n] = (rand()/(float)RAND_MAX) * 2 - 1;
    }

    //Generate impulse response
    for(k = 0; k < N; k++){
        omega = (2*PI*k)/N;
        impulse_response[k] = 0.5 + 0.5*cos(omega);
    }

    //Perform convolution
    for(n = 0; n < N; n++){
        output_signal[n] = 0;
        for(k = 0; k < N; k++){
            inv_omega = (2*PI*(n-k))/N;
            output_signal[n] += input_signal[k] * impulse_response[k] * cos(inv_omega);
        }
    }

    //Print output signal
    for(n = 0; n < N; n++){
        printf("%f\n", output_signal[n]);
    }

    return 0;
}