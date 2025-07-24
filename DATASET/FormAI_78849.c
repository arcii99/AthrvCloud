//FormAI DATASET v1.0 Category: Audio processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Struct to hold audio data
typedef struct {
    uint8_t* data;
    int32_t length;
} audio_data;

// Function to shift audio pitch up by half a step
void shift_pitch_up_half_step(audio_data* audio) {
    int16_t* ptr = (int16_t*)audio->data;
    int16_t* end = (int16_t*)(audio->data + audio->length);
    
    while (ptr < end) {
        *ptr = *ptr * 1.059463094359; // Multiply by 2^(1/12) to shift up by half step
        ptr++;
    }
}

// Function to shift audio pitch down by half a step
void shift_pitch_down_half_step(audio_data* audio) {
    int16_t* ptr = (int16_t*)audio->data;
    int16_t* end = (int16_t*)(audio->data + audio->length);
    
    while (ptr < end) {
        *ptr = *ptr * 0.94387431268; // Multiply by 2^(-1/12) to shift down by half step
        ptr++;
    }
}

// Function to reverse audio
void reverse_audio(audio_data* audio) {
    int8_t* ptr = (int8_t*)audio->data;
    int8_t* end = ptr + audio->length - 2;
    
    // Swap values from beginning and end until middle is reached
    while (ptr < end) {
        int8_t temp = *ptr;
        *ptr = *end;
        *end = temp;
        ptr++;
        end--;
    }
}

// Main program
int main() {
    // Create audio data struct
    audio_data audio;
    audio.length = 44100;
    audio.data = (uint8_t*)malloc(sizeof(int16_t) * audio.length);
    
    // Generate sine wave data
    int16_t* ptr = (int16_t*)audio.data;
    int16_t* end = (int16_t*)(audio.data + audio.length);
    float phase = 0.0;
    float phase_step = 2 * 3.1415926535 / audio.length;
    while (ptr < end) {
        *ptr = (int16_t)(32767 * sin(phase));
        phase += phase_step;
        ptr++;
    }
    
    // Print original audio data
    printf("Original audio data:\n");
    ptr = (int16_t*)audio.data;
    end = (int16_t*)(audio.data + audio.length);
    while (ptr < end) {
        printf("%d\n", *ptr);
        ptr++;
    }
    
    // Shift pitch up by half step and print shifted data
    shift_pitch_up_half_step(&audio);
    printf("\nShifted pitch up by half step:\n");
    ptr = (int16_t*)audio.data;
    end = (int16_t*)(audio.data + audio.length);
    while (ptr < end) {
        printf("%d\n", *ptr);
        ptr++;
    }
    
    // Shift pitch down by half step and print shifted data
    shift_pitch_down_half_step(&audio);
    printf("\nShifted pitch down by half step:\n");
    ptr = (int16_t*)audio.data;
    end = (int16_t*)(audio.data + audio.length);
    while (ptr < end) {
        printf("%d\n", *ptr);
        ptr++;
    }
    
    // Reverse audio and print reversed data
    reverse_audio(&audio);
    printf("\nReversed audio data:\n");
    ptr = (int16_t*)audio.data;
    end = (int16_t*)(audio.data + audio.length);
    while (ptr < end) {
        printf("%d\n", *ptr);
        ptr++;
    }
    
    // Free memory
    free(audio.data);
    
    return 0;
}