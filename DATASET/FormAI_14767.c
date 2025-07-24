//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 1

int main(){
    // Variables to hold signal strength and time
    int signal_strength;
    time_t current_time;
 
    // Seed the random number generator 
    srand((unsigned) time(NULL));
 
    // Generate and print random signal strengths 
    for(int i=0; i<10; i++){
        signal_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH; // Generate random signal strength within the specified range
        printf("Signal strength: %d%%\n", signal_strength);
    }

    // Capture the current time
    current_time = time(NULL);
    
    // Perform signal analysis
    if(signal_strength >= 70){
        printf("Signal strength is excellent!\n");
    } else if(signal_strength >= 50){
        printf("Signal strength is good.\n");
    } else if(signal_strength >= 30){
        printf("Signal strength is fair.\n");
    } else {
        printf("Signal strength is poor.\n");
    }
    
    // Calculate elapsed time
    time_t elapsed_time = time(NULL) - current_time;
    printf("Elapsed time: %ld seconds\n", elapsed_time);

    return 0;
}