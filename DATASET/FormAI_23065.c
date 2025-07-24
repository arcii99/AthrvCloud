//FormAI DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define NUM_SAMPLES 10000
#define SAMPLE_RATE 48000
#define PI 3.14159265359

int16_t audio_buffer[NUM_SAMPLES];

void generate_sine_wave(float frequency, float amplitude){
    int i;
    float time_step = 1.0/SAMPLE_RATE;
    for(i = 0; i < NUM_SAMPLES; i++){
        float sample_time = i*time_step;
        audio_buffer[i] = (int16_t)(amplitude*sin(2*PI*frequency*sample_time));
    }
}

void distort_audio(float gain){
    int i;
    for(i = 0; i < NUM_SAMPLES; i++){
        audio_buffer[i] = (int16_t)(audio_buffer[i] * gain);
    }
}

void print_audio_buffer(){
    int i;
    for(i = 0; i < NUM_SAMPLES; i++){
        printf("%d ", audio_buffer[i]);
    }
    printf("\n");
}

int main(){
    generate_sine_wave(1000, 1000);
    printf("Original audio buffer:\n");
    print_audio_buffer();
    distort_audio(2.0);
    printf("Distorted audio buffer:\n");
    print_audio_buffer();
    return 0;
}