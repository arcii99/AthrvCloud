//FormAI DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FS 44100
#define PI 3.14159265

// Define multivariable audio processing function
void audioProcessing(float* input, float* output, float gain, float pan)
{
    float left, right;
    float angle = pan * PI/4;
    float cosVal = cos(angle);
    float sinVal = sin(angle);

    // Process audio for each sample
    for(int i=0; i<FS; i++)
    {
        // Split input into left and right channels based on pan
        left = input[i] * gain * cosVal;
        right = input[i] * gain * sinVal;

        // Add delay effect to right channel
        if(i > 1000)
        {
            right += output[i-1000]/2;
        }

        // Apply low-pass filter to left channel
        if(i > 2)
        {
            left = (left + output[i-1] + output[i-2])/3;
        }

        // Apply high-pass filter to right channel
        if(i > 5)
        {
            right = (right - output[i-5])/2;
        }

        // Mix left and right channels for output
        output[i] = (left + right)/2;
    }
}

int main()
{
    // Generate input signal
    float input[FS];
    for(int i=0; i<FS; i++)
    {
        input[i] = sin(2*PI*440*i/FS);
    }

    // Create output array
    float output[FS];

    // Process audio with different parameters
    audioProcessing(input, output, 0.7, 0.0);
    audioProcessing(input, output, 0.9, -1.0);
    audioProcessing(input, output, 1.0, 1.0);

    // Save output to file
    FILE* outFile;
    outFile = fopen("output.wav", "wb");
    fwrite(&output, sizeof(float), FS, outFile);
    fclose(outFile);

    printf("Output saved to file!\n");

    return 0;
}