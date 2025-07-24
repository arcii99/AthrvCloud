//FormAI DATASET v1.0 Category: Audio processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

/* Function to generate a sine wave with given frequency and duration */
void generateSineWave(float freq, float duration, float sampleRate, float amplitude, short *buffer) {
    int i, numSamples = duration * sampleRate;
    float timeStep = 1.0 / sampleRate, theta;
    
    for (i = 0; i < numSamples; i++) {
        theta = 2 * PI * freq * i * timeStep;
        buffer[i] = (amplitude * sin(theta));
    }
}

/* Function to apply low-pass filter to given audio buffer */
void applyLowPassFilter(short *buffer, int numSamples, float sampleRate, float cutoffFreq) {
    int i;
    float RC = 1.0 / (2 * PI * cutoffFreq);
    float dt = 1.0 / sampleRate;
    float alpha = dt / (RC + dt);
    float prevSample = buffer[0], currSample;
    
    for (i = 1; i < numSamples; i++) {
        currSample = alpha * buffer[i] + (1 - alpha) * prevSample;
        buffer[i] = (short) currSample;
        prevSample = currSample;
    }
}

int main() {
    /* Generate a 440Hz sine wave of 1 second with 44100 sample rate and max amplitude of 32767 */
    short buffer[44100];
    generateSineWave(440.0, 1.0, 44100.0, 32767.0, buffer);
    
    /* Apply low-pass filter with cutoff frequency of 200Hz */
    applyLowPassFilter(buffer, 44100, 44100.0, 200.0);
    
    /* Write the filtered audio to a file */
    FILE *fp = fopen("filtered_audio.raw", "wb");
    fwrite(buffer, sizeof(short), sizeof(buffer), fp);
    fclose(fp);
    
    return 0;
}