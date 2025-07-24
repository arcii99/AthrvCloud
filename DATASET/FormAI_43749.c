//FormAI DATASET v1.0 Category: Audio processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 4410

typedef unsigned char byte;

void generateSineWave(float freq, float duration, float amplitude, byte* buffer);
void applyEcho(byte* buffer, int delay, float scale);

int main() {
    byte buffer[BUFFER_SIZE];
    
    float freq = 440.0f;
    float duration = 2.0f;
    float amplitude = 50.0f;
    
    generateSineWave(freq, duration, amplitude, buffer);
    
    // Apply echo with a delay of 0.5 seconds and a scale of 0.5
    applyEcho(buffer, 22050, 0.5);
    
    // Write buffer to file
    FILE *fp;
    fp = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(byte), BUFFER_SIZE, fp);
    fclose(fp);
    
    return 0;
}


void generateSineWave(float freq, float duration, float amplitude, byte* buffer) {
    int numSamples = duration * SAMPLE_RATE;
    float sampleRateDivFreq = SAMPLE_RATE / freq;

    for(int i = 0; i < numSamples; i++) {
        // Calculate sine value at current time
        float currentTime = (float)i / SAMPLE_RATE;
        float sampleValue = amplitude * sinf( 2.0f * M_PI * freq * currentTime);

        // Convert floating-point sample value to 8-bit integer
        byte sample = (byte)round(127.0f + sampleValue);
        
        // Write value to buffer
        buffer[i] = sample;
    }
}


void applyEcho(byte* buffer, int delay, float scale) {
    for(int i = delay; i < BUFFER_SIZE; i++) {
        byte originalValue = buffer[i];
        byte delayedValue = buffer[i - delay] * scale;
        buffer[i] = originalValue + delayedValue;
    }
}