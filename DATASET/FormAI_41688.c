//FormAI DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 1000
#define PI 3.141592653589793

int main()
{
    double frequency = 440.0;
    double amplitude = 0.5;
    double phase = 0.0;
    
    double sample_rate = 44100.0;
    double sample_period = 1.0 / sample_rate;
    double duration = 2.0;
    
    double samples[NUM_SAMPLES];
    
    for (int i = 0; i < NUM_SAMPLES; i++) {
        double time = i * sample_period;
        samples[i] = amplitude * sin(2.0 * PI * frequency * time + phase);
    }
    
    FILE *fp;
    fp = fopen("output.pcm", "wb");
    fwrite(samples, sizeof(double), NUM_SAMPLES, fp);
    fclose(fp);
    
    printf("Audio generated and saved to output.pcm\n");
    
    return 0;
}