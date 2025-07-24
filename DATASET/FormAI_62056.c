//FormAI DATASET v1.0 Category: Audio processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

int main()
{
    /* Declare variables */
    int samples[BUFFER_SIZE];
    FILE *inputFile;
    FILE *outputFile;
    float gain = 1.5;
    int16_t maxAmplitude = INT16_MAX;
    int i, sampleCount;
    
    /* Open input file */
    inputFile = fopen("input.wav", "rb");
    
    /* Read header to skip it */
    char header[44];
    fread(header, sizeof(char), 44, inputFile);
    
    /* Read samples */
    sampleCount = fread(samples, sizeof(int), BUFFER_SIZE, inputFile);
    
    /* Loop through samples */
    for(i=0; i<sampleCount; i++)
    {
        /* Apply gain */
        samples[i] = (int)(samples[i] * gain);
        
        /* Clamp sample to maximum amplitude */
        if(samples[i] > maxAmplitude)
            samples[i] = maxAmplitude;
        else if(samples[i] < -maxAmplitude)
            samples[i] = -maxAmplitude;
    }
    
    /* Open output file */
    outputFile = fopen("output.wav", "wb");
    
    /* Write header */
    fwrite(header, sizeof(char), 44, outputFile);
    
    /* Write samples */
    fwrite(samples, sizeof(int), sampleCount, outputFile);
    
    /* Close files */
    fclose(inputFile);
    fclose(outputFile);
    
    /* End program */
    return 0;
}