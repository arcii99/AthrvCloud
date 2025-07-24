//FormAI DATASET v1.0 Category: Audio processing ; Style: random
#include <stdio.h>

// function to add two audio signals
void add_audio(int *audio1, int *audio2, int length) {
    int i;
    for (i = 0; i < length; i++) {
        audio1[i] += audio2[i];
    }
}

// function to multiply two audio signals
void multiply_audio(int *audio1, int *audio2, int length) {
    int i;
    for (i = 0; i < length; i++) {
        audio1[i] *= audio2[i];
    }
}

// function to reverse an audio signal
void reverse_audio(int *audio, int length) {
    int i, temp;
    for (i = 0; i < length/2; i++) {
        temp = audio[i];
        audio[i] = audio[length-1-i];
        audio[length-1-i] = temp;
    }
}

int main() {
    int audio1[] = {3, 5, 7, 9, 11};
    int audio2[] = {2, 4, 6, 8, 10};
    int length = 5;
    int i;

    printf("Audio 1: ");
    for (i = 0; i < length; i++) {
        printf("%d ", audio1[i]);
    }
    printf("\nAudio 2: ");
    for (i = 0; i < length; i++) {
        printf("%d ", audio2[i]);
    }

    printf("\nAdding audio 1 and audio 2...\n");
    add_audio(audio1, audio2, length);
    printf("Result: ");
    for (i = 0; i < length; i++) {
        printf("%d ", audio1[i]);
    }

    printf("\nMultiplying audio 1 and audio 2...\n");
    multiply_audio(audio1, audio2, length);
    printf("Result: ");
    for (i = 0; i < length; i++) {
        printf("%d ", audio1[i]);
    }

    printf("\nReversing audio 1...\n");
    reverse_audio(audio1, length);
    printf("Result: ");
    for (i = 0; i < length; i++) {
        printf("%d ", audio1[i]);
    }

    return 0;
}