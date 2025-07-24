//FormAI DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
void readAudioFile(char* filename, double* buffer, int length);
void writeAudioFile(char* filename, double* buffer, int length);
void applyLowPassFilter(double* buffer, int length, double cutoffFreq);

int main(int argc, char* argv[]) {
    // check command line arguments
    if (argc < 4) {
        printf("Usage: %s input_audio.wav output_audio.wav cutoff_frequency\n", argv[0]);
        exit(1);
    }

    // extract command line arguments
    char* inputFilename = argv[1];
    char* outputFilename = argv[2];
    double cutoffFreq = atof(argv[3]);

    // read input audio file
    int length = 44100;  // we assume a sampling rate of 44100 Hz
    double buffer[length];
    readAudioFile(inputFilename, buffer, length);

    // apply low pass filter
    applyLowPassFilter(buffer, length, cutoffFreq);

    // write output audio file
    writeAudioFile(outputFilename, buffer, length);

    return 0;
}

void readAudioFile(char* filename, double* buffer, int length) {
    // TODO: implementation of reading audio file from disk
    // for now, we generate a sine wave signal with frequency 440 Hz
    int samplingRate = 44100;
    double amplitude = 0.5;
    double frequency = 440.0;
    for (int i = 0; i < length; i++) {
        double sample = amplitude * sin(2.0 * M_PI * frequency * i / samplingRate);
        buffer[i] = sample;
    }
}

void writeAudioFile(char* filename, double* buffer, int length) {
    // TODO: implementation of writing audio file to disk
    // for now, we print the first 10 samples of the buffer to stdout
    printf("Writing audio file %s with the first 10 samples:\n", filename);
    for (int i = 0; i < 10; i++) {
        printf("%f ", buffer[i]);
    }
    printf("...\n");
}

void applyLowPassFilter(double* buffer, int length, double cutoffFreq) {
    // TODO: implementation of applying low pass filter to buffer
    // for now, we simply set the samples above the cutoff frequency
    // to zero and print the new first 10 samples to stdout
    printf("Applying low pass filter with cutoff frequency %f Hz, the first 10 samples are now:\n", cutoffFreq);
    for (int i = 0; i < length; i++) {
        if (i * 44100.0 / length > cutoffFreq) {
            buffer[i] = 0.0;
        }
        if (i < 10) {
            printf("%f ", buffer[i]);
        }
    }
    printf("...\n");
}