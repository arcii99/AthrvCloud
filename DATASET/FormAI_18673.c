//FormAI DATASET v1.0 Category: Digital signal processing ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//This program generates a frequency modulated signal and then demodulates it back to its original signal

int main(){

    int n = 100; //number of samples
    float Fs = 1000; //sampling frequency
    float carrierFreq = 50; //carrier frequency of modulating signal
    float modFreq = 5; //modulating frequency of modulating signal
    float phase = 0; //phase of modulating signal
    float amplitude = 1; //amplitude of modulating signal
    float deviation = 20; //deviation of frequency modulation
    float time[n]; //time axis
    float carrierSignal[n]; //carrier signal
    float modulatingSignal[n]; //modulating signal
    float modulatedSignal[n]; //modulated signal
    float demodulatedSignal[n]; //demodulated signal
    float demodulationFreq = 10; //frequency of demodulating signal

    //generating time axis
    for(int i=0; i<n; i++){
        time[i] = (float)i/Fs;
    }

    //generating carrier signal
    for(int i=0; i<n; i++){
        carrierSignal[i] = sin(2*M_PI*carrierFreq*time[i]);
    }

    //generating modulating signal
    for(int i=0; i<n; i++){
        modulatingSignal[i] = amplitude*sin(2*M_PI*modFreq*time[i] + phase);
    }

    //generating modulated signal by frequency modulation
    for(int i=0; i<n; i++){
        modulatedSignal[i] = sin(2*M_PI*carrierFreq*time[i] + deviation/modFreq*cos(2*M_PI*modFreq*time[i]));
    }

    //demodulating the modulated signal by multiplying with the demodulating signal
    for(int i=0; i<n; i++){
        demodulatedSignal[i] = modulatedSignal[i]*sin(2*M_PI*demodulationFreq*time[i]);
    }

    //displaying original and demodulated signal
    printf("Time\tOriginal Signal\tDemodulated Signal\n");
    for(int i=0; i<n; i++){
        printf("%f\t%f\t%f\n", time[i], modulatingSignal[i], demodulatedSignal[i]);
    }

    return 0;
}