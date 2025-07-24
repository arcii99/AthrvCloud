//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
#include<stdio.h>
#include<math.h>

//Shape-Shifting Digital Signal Processing Program

void sine_wave(float *output, float frequency, float duration, int sampling_rate){
    int samples = duration * sampling_rate; //calculate number of samples
    float delta_t = 1.0 / sampling_rate; //time between each sample
    for(int i=0; i<samples; i++){
        output[i] = sin(2*M_PI*frequency*i*delta_t); //sinusoidal function
    }
}

void square_wave(float *output, float frequency, float duration, int sampling_rate){
    int samples = duration * sampling_rate; //calculate number of samples
    float period = 1.0/frequency; //period of square wave
    float delta_t = 1.0 / sampling_rate; //time between each sample
    for(int i=0; i<samples; i++){
        if(fmod(i*delta_t,period) < period/2){
            output[i] = 1; //positive output for first half of period
        } else {
            output[i] = -1; //negative output for second half of period
        }
    }
}

void triangle_wave(float *output, float frequency, float duration, int sampling_rate){
    int samples = duration * sampling_rate; //calculate number of samples
    float period = 1.0/frequency; //period of triangle wave
    float delta_t = 1.0 / sampling_rate; //time between each sample
    for(int i=0; i<samples; i++){
        float t = fmod(i*delta_t,period); //time since start of period
        if(t < period/2){
            output[i] = (4*t/period) - 1; //positive slope for first half of period
        } else {
            output[i] = (-4.0/period)*t + 3.0; //negative slope for second half of period
        }
    }
}

int main(){
    int sampling_rate = 44100; //CD-quality audio sampling rate
    float duration = 1.0; //1 second duration for each waveform
    float frequency = 440.0; //standard tuning A4 note frequency
    float sine_waveform[sampling_rate];
    float square_waveform[sampling_rate];
    float triangle_waveform[sampling_rate];

    sine_wave(sine_waveform,frequency,duration,sampling_rate);
    square_wave(square_waveform,frequency,duration,sampling_rate);
    triangle_wave(triangle_waveform,frequency,duration,sampling_rate);

    //print out first 10 samples of each waveform
    printf("Sine Wave:\n");
    for(int i=0; i<10; i++){
        printf("%f\n",sine_waveform[i]);
    }
    printf("Square Wave:\n");
    for(int i=0; i<10; i++){
        printf("%f\n",square_waveform[i]);
    }
    printf("Triangle Wave:\n");
    for(int i=0; i<10; i++){
        printf("%f\n",triangle_waveform[i]);
    }

    return 0;
}