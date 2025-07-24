//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main(){
    srand(time(NULL));
    int players = 4;
    int signals[players];
    int max_signal = 100;
    int min_signal = 1;

    // Initialize signals for each player
    for(int i=0; i<players; i++){
        signals[i] = random_num(min_signal, max_signal);
    }

    // Display signals of each player
    for(int i=0; i<players; i++){
        printf("Player %d signal strength: %d\n", i+1, signals[i]);
    }

    // Find player with the highest signal strength
    int max_signal_index = 0;
    for(int i=0; i<players; i++){
        if(signals[i] > signals[max_signal_index]){
            max_signal_index = i;
        }
    }

    // Display winner and their signal strength
    printf("\nPlayer %d wins with a signal strength of %d\n", max_signal_index+1, signals[max_signal_index]);
    
    return 0;
}