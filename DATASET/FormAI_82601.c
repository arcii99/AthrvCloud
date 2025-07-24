//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {

    printf("Wow! I can't believe it worked! This Digital Signal Processing program is amazing!\n");
    printf("Let's generate a sine wave.\n");
    
    // Define variables
    int sample_rate = 44100; // 44100 samples per second
    int duration = 5; // duration of the signal in seconds
    int amplitude = 10000; // amplitude of the signal
    double frequency = 400; // frequency of the signal
    int num_samples = duration * sample_rate; // total number of samples
    
    // Create an array to hold the samples
    int *samples = malloc(num_samples * sizeof(int));
    
    // Use a for loop to generate the samples
    for (int i = 0; i < num_samples; i++) {
        double angle = 2*PI*frequency*i/sample_rate;
        samples[i] = amplitude*sin(angle);
    }
    
    printf("We have generated a sine wave with %d samples!\n", num_samples);
    
    // Let's print out some of the samples
    printf("The first 10 samples are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", samples[i]);
    }
    
    // We're done with the samples array, so let's free the memory
    free(samples);
    
    printf("That was so cool! We generated a sine wave using Digital Signal Processing! I'm amazed!\n");
    
    return 0;
}