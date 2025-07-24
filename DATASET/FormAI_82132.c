//FormAI DATASET v1.0 Category: Audio processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    // Define the audio input array
    float input[44100];

    // Initialize the input array with a sine wave of 300 Hz
    for (int i = 0; i < 44100; i++) {
        input[i] = sin(2 * PI * 300 * i / 44100);
    }

    // Define the audio output array
    float output[44100];

    // Filter the audio input with a simple low-pass filter
    for (int i = 0; i < 44100; i++) {
        if (i == 0) {
            output[i] = input[i];
        } else {
            output[i] = output[i - 1] + 0.0001 * (input[i] - output[i - 1]);
        }
    }

    // Write the filtered audio output to a WAV file
    FILE *f = fopen("output.wav", "wb");

    // Write the WAV file header
    char header[44] = {
        'R', 'I', 'F', 'F', // ChunkID
        0x24, 0x8A, 0x5E, 0x00, // ChunkSize
        'W', 'A', 'V', 'E', // Format
        'f', 'm', 't', ' ', // Subchunk1ID
        0x10, 0x00, 0x00, 0x00, // Subchunk1Size
        0x01, 0x00, // AudioFormat
        0x02, 0x00, // NumChannels
        0x44, 0xAC, 0x00, 0x00, // SampleRate
        0x88, 0x58, 0x01, 0x00, // ByteRate
        0x04, 0x00, // BlockAlign
        0x10, 0x00, // BitsPerSample
        'd', 'a', 't', 'a', // Subchunk2ID
        0xE0, 0x8A, 0x5E, 0x00 // Subchunk2Size
    };
    fwrite(header, 1, 44, f);

    // Write the audio data to the WAV file
    for (int i = 0; i < 44100; i++) {
        short sample = (short)(output[i] * 32767);
        fwrite(&sample, 2, 1, f);
        fwrite(&sample, 2, 1, f);
    }

    // Close the WAV file
    fclose(f);

    // Exit the program
    return 0;
}