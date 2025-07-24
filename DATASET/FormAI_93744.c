//FormAI DATASET v1.0 Category: Audio processing ; Style: energetic
// Let's create an audio processing program that adds an energetic effect to the sound
// We will use the PortAudio library to capture and play the sound in real-time
#include <stdio.h>
#include <math.h>
#include "portaudio.h"

#define SAMPLE_RATE 44100

// Declare some global variables
PaStream *stream;
float gain = 0.5;
float freq = 220;
float phase = 0;

// Define a callback function that will be called by PortAudio
static int pa_callback(const void *inputBuffer, void *outputBuffer,
                       unsigned long framesPerBuffer,
                       const PaStreamCallbackTimeInfo *timeInfo,
                       PaStreamCallbackFlags statusFlags, void *userData) {
    float *in = (float*)inputBuffer;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) timeInfo; /* Prevent unused variable warnings. */
    (void) statusFlags;
    (void) userData;

    for (i = 0; i < framesPerBuffer; i++) {
        *out++ = *in++ * gain * sin(phase * 2 * M_PI / SAMPLE_RATE);
        *out++ = *in++ * gain * sin(phase * 2 * M_PI / SAMPLE_RATE);
        phase += freq / SAMPLE_RATE;
    }

    return paContinue;
}

int main(int argc, char *argv[]) {
    PaError err;

    // Initialize the PortAudio library
    err = Pa_Initialize();
    if (err != paNoError) goto error;

    // Open an audio stream
    err = Pa_OpenDefaultStream(&stream, 2,  // stereo input and output
                               2,           // channels
                               paFloat32,   // 32 bit floating point input and output
                               SAMPLE_RATE, // sample rate
                               256,         // frames per buffer
                               pa_callback, // callback function
                               NULL );      // user data
    if (err != paNoError) goto error;

    // Start the audio stream
    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    // Wait for the user to press Enter
    printf("Press Enter to stop.\n");
    getchar();

    // Stop and close the audio stream
    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;
    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;

    // Terminate the PortAudio library
    err = Pa_Terminate();
    if (err != paNoError) goto error;

    return 0;

error:
    printf("An error occurred while using the PortAudio stream:\n");
    printf("%s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return 1;
}