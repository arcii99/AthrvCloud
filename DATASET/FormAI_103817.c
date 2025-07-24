//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100

//function to simulate wifi signal strength
int get_signal_strength(){
    int signal_strength = rand() % (MAX_SIGNAL_STRENGTH + 1);
    return signal_strength;
}

int main() {
    srand(time(NULL)); //initialize random number generator with current time
    
    printf("Welcome to the Wifi Signal Strength Analyzer!\n\n");
    
    printf("Enter the number of seconds you want to monitor the signal strength:\n");
    int monitoring_time;
    scanf("%d", &monitoring_time);
    
    int signal_strength_history[monitoring_time]; //store signal strength values for each second
    
    printf("\nMonitoring signal strength for %d seconds...\n\n", monitoring_time);
    
    for(int sec=1; sec<=monitoring_time; sec++){
        int current_strength = get_signal_strength();
        signal_strength_history[sec-1] = current_strength;
        printf("Second %d: Signal strength = %d\n", sec, current_strength);
    }
    
    //calculate average signal strength
    float sum_strengths = 0;
    for(int i=0; i<monitoring_time; i++){
        sum_strengths += signal_strength_history[i];
    }
    float avg_signal_strength = sum_strengths / monitoring_time;
    
    printf("\nAverage signal strength over %d seconds = %.2f\n", monitoring_time, avg_signal_strength);
    
    return 0;
}