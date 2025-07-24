//FormAI DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// function to double the amplitude of the input audio signal
void doubleAmplitude(float* audio_signal, int length) {
    // loop through the input array and multiply each sample value by 2
    for (int i = 0; i < length; i++) {
        audio_signal[i] = audio_signal[i] * 2;
    }
}

int main() {
    // some example audio signal with length of 10
    float audio_signal[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Original audio signal:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", audio_signal[i]);
    }

    // Double the amplitude of audio signal
    doubleAmplitude(audio_signal, 10);

    printf("\n\nAudio signal after doubling the amplitude:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", audio_signal[i]);
    }

    return 0;
}