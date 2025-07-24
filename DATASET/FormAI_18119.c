//FormAI DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int n, sampling_rate, frequency;
    float duration;

    printf("Enter the sampling rate (in Hz): ");
    scanf("%d", &sampling_rate);
  
    printf("Enter the frequency (in Hz): ");
    scanf("%d", &frequency);

    printf("Enter the duration (in seconds): ");
    scanf("%f", &duration);

    n = sampling_rate * duration;
    float sound[n];

    for (int i=0; i<n; i++) {
        sound[i] = sin(2*PI*frequency*(float)i/sampling_rate);
    }

    FILE *file;
    file = fopen("sound.raw", "w+");
    
    if (file == NULL) {
        printf("Error opening file");
        return -1;
    }
    
    int amplitude = 32767; // Max amplitude for 16-bit sound
    int sample;
    
    for (int i=0; i<n; i++) {
        sample = (int)(amplitude * sound[i]);
        fwrite(&sample, sizeof(short), 1, file);
    }
    
    fclose(file);
    printf("Sound file generated");
  
    return 0;
}