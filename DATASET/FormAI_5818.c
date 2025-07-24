//FormAI DATASET v1.0 Category: Digital signal processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 48000
#define PI 3.14159265359

int main(){
    float input_signal[] = {0.5, 0, -0.7, 0.4, 0.9, -0.6, -0.5, 0, 0.3, 0.8};
    float output_signal[10];
    float filter_coefficients[] = {0.2, 0.5, 0.3};
    float delay_buffer[2] = {0};

    //Implementing FIR filter
    for(int i=0; i<10; i++){
        delay_buffer[1] = delay_buffer[0];
        delay_buffer[0] = input_signal[i];
        output_signal[i] = (filter_coefficients[0]*delay_buffer[0]) + (filter_coefficients[1]*delay_buffer[1]) + (filter_coefficients[2]*input_signal[i]);
    }

    //Implementing FFT to obtain frequency response of the filter
    float magnitude_response[10] = {0};
    for(int i=0; i<10; i++){
        float real_part = 0, imag_part = 0;
        for(int j=0; j<3; j++){
            float angle = 2*PI*i*j/3;
            real_part += filter_coefficients[j] * cos(angle);
            imag_part -= filter_coefficients[j] * sin(angle);
        }
        magnitude_response[i] = sqrt(pow(real_part, 2) + pow(imag_part, 2));
    }

    //Printing the input and output signals
    printf("Input Signal: ");
    for(int i=0; i<10; i++){
        printf("%f ", input_signal[i]);
    }
    printf("\nOutput Signal: ");
    for(int i=0; i<10; i++){
        printf("%f ", output_signal[i]);
    }
    printf("\n");

    //Printing the frequency response of the filter
    printf("Frequency Response of the Filter: ");
    for(int i=0; i<10; i++){
        printf("%f ", magnitude_response[i]);
    }
    printf("\n");

    return 0;
}