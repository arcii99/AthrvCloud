//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0
#define WIFI_POINTS 10

// Random number generator function
int generate_random(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    int wifi_strength[WIFI_POINTS]; // Array to store wifi signal strength
    srand(time(0)); // Seed the random number generator with the current time

    // Randomly generate wifi signal strengths for each point
    for(int i=0; i<WIFI_POINTS; i++){
        wifi_strength[i] = generate_random(MIN_SIGNAL, MAX_SIGNAL);
    }

    // Find average signal strength
    int sum = 0, average;
    for(int i=0; i<WIFI_POINTS; i++){
        sum += wifi_strength[i];
    }
    average = sum / WIFI_POINTS;

    // Print the wifi signal strengths and the average signal strength
    printf("Wifi Signal Strength:\n");
    for(int i=0; i<WIFI_POINTS; i++){
        printf("%d ", wifi_strength[i]);
    }
    printf("\n\nAverage Signal Strength: %d\n", average);

    return 0;
}