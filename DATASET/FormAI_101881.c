//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define PI 3.14159265358979323846

double input_signal[N];

void generate_signal(double freq, double amplitude){
    for(int i = 0; i < N; i++){
        input_signal[i] = amplitude * sin(2.0 * PI * freq * ((double)i / (double)N));
    }
}

void fir_filter(double *coefficients, int num_taps, double *input, double *output, int num_samples){
    double buffer[num_taps];
    for(int i = 0; i < num_taps; i++){
        buffer[i] = 0.0;
    }

    for(int i = 0; i < num_samples; i++){
        buffer[0] = input[i];

        double sum = 0.0;
        for(int j = 0; j < num_taps; j++){
            sum += buffer[j] * coefficients[j];
            if(j != (num_taps - 1)){
                buffer[j + 1] = buffer[j];
            }
        }

        output[i] = sum;
    }
}

int main(){
    double sampling_rate = 44100.0;
    double signal_frequency = 500.0;
    double signal_amplitude = 0.5;

    generate_signal(signal_frequency, signal_amplitude);

    double filter_coefficients[21] = {0.002156541506752023, 0.010873151996932144, 0.028203625313176323, 0.04877629970367845, 
                                      0.06254319643554669, 0.06254319643554669, 0.04877629970367845, 0.028203625313176323, 
                                      0.010873151996932144, 0.002156541506752023, 0.0, -0.0021552450382550388, -0.003992073447557816, 
                                      -0.004086163450328515, -0.0012116032046314953, 0.005390742953503323, 0.013651813854791956, 
                                      0.01997863241682561, 0.021883844537321984, 0.01839968636618523, 0.010032931607557645};

    int num_taps = 21;
    double filtered_signal[N];

    fir_filter(filter_coefficients, num_taps, input_signal, filtered_signal, N);

    printf("Original signal: %f\n", input_signal[0]);
    printf("Filtered signal: %f\n", filtered_signal[0]);

    return 0;
}