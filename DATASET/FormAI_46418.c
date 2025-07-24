//FormAI DATASET v1.0 Category: Audio processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

float gain = 1.0f;
float frequency = 440.0f;
float phase = 0.0f;

void processAudio(float* buffer, int numSamples){
    int i;
    for(i=0;i<numSamples;i++){
        float sample = gain*sin(phase);
        buffer[i] = sample;
        phase += 2.0f*M_PI*frequency/SAMPLE_RATE;
        if(phase >= 2.0f*M_PI){
            phase -= 2.0f*M_PI;
        }
    }   
}

int main(){
    float buffer[BUFFER_SIZE];
    int numSamples = BUFFER_SIZE;
    int i;
    float time = 0.0f;

    for(i=0;i<numSamples;i++){
        float sample = gain*sin(phase);
        buffer[i] = sample;
        time += 1.0f/SAMPLE_RATE;
        phase += 2.0f*M_PI*frequency/SAMPLE_RATE;
        if(phase >= 2.0f*M_PI){
            phase -= 2.0f*M_PI;
        }
    }

    FILE* fp = fopen("example.pcm","wb");
    fwrite(buffer,sizeof(float),numSamples,fp);
    fclose(fp);

    return 0;
}