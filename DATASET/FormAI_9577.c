//FormAI DATASET v1.0 Category: Digital signal processing ; Style: happy
#include <stdio.h>

void happyDSP() {
    printf("Let's start our DSP adventure with a smile!\n");
    printf("We will be processing a happy tune for us to enjoy!\n");
    printf("Here are the notes of our happy tune:\n");
    
    // defining the frequencies of the notes in Hz
    float freqs[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};
    int length = sizeof(freqs)/sizeof(freqs[0]); // getting the length of the array
    
    // printing out the notes
    for(int i=0; i<length; i++) {
        printf("%.2f Hz\n", freqs[i]);
    }
    
    printf("Let's process our tune by doubling its frequency!\n");
    for(int i=0; i<length; i++) {
        freqs[i] *= 2; // doubling the frequency
        printf("%.2f Hz\n", freqs[i]); // printing out the processed note
    }
    
    printf("Our happy tune is now twice as fast and still sounds great!\n");
    printf("Let's continue our DSP journey with even more exciting sounds!\n");
}

int main() {
    happyDSP(); // calling our happy DSP function
    return 0;
}