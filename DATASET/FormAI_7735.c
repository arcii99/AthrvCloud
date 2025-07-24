//FormAI DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>

// Function to process audio recursively
void process_audio(float audio[], int len, float factor) {
    if (len <= 0) {
        return;
    }
    
    // Apply processing to current sample
    audio[len-1] *= factor;
    
    // Call the function recursively with the remaining samples
    process_audio(audio, len-1, factor);
}

int main() {
    float audio[] = {0.1, 0.25, 0.5, 0.75, 1.0, 0.75, 0.5, 0.25};
    int len = sizeof(audio)/sizeof(audio[0]);
    float factor = 0.5;
    
    // Print the original audio samples
    printf("Original audio samples:\n");
    for (int i=0; i<len; i++) {
        printf("%.2f ", audio[i]);
    }
    printf("\n");
    
    // Process the audio recursively with the given factor
    process_audio(audio, len, factor);
    
    // Print the processed audio samples
    printf("Processed audio samples:\n");
    for (int i=0; i<len; i++) {
        printf("%.2f ", audio[i]);
    }
    printf("\n");
    
    return 0;
}