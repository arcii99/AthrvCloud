//FormAI DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

float sine_wave(float freq, float time){
    return sin(2*PI*freq*time);
}

int main(){
    int num_samples = SAMPLE_RATE*5; //5 second audio stream
    float *audio_stream = (float *) malloc(sizeof(float)*num_samples);

    float frequency = 440.0; //A4 note
    float amplitude = 0.5;

    for(int i=0; i<num_samples; i++){
        float time = (float)i/(float)SAMPLE_RATE;
        audio_stream[i] = amplitude*sine_wave(frequency, time);
    }

    FILE *file = fopen("audio.raw", "wb"); //writing in binary mode
    fwrite(audio_stream, sizeof(float), num_samples, file);

    fclose(file);
    free(audio_stream);

    return 0;
}