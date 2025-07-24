//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
//This program is a Wi-Fi Signal Strength Analyzer that can detect Wi-Fi signals and their corresponding strengths in C programming language.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNALS 10 //Maximum number of Wi-Fi signals to be detected
#define MAX_NAME_LEN 20 //Maximum length of Wi-Fi network name

struct wifi_signal {
    char name[MAX_NAME_LEN]; //Wi-Fi network name
    int strength; //Signal strength in dBm
};

int main() {
    struct wifi_signal signals[MAX_SIGNALS]; //Array to store Wi-Fi signals
    int num_signals = 0; //Number of signals detected
    
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("------------------------------\n");
    
    //Start scanning for Wi-Fi signals
    printf("Scanning for Wi-Fi signals...\n");
    //Code for scanning Wi-Fi signals and storing their names and strengths goes here
    //Assuming that the signals and their strengths have been detected and stored in the `signals` array
    
    num_signals = 3; //For demo purposes
    
    //Print the list of detected signals and their strengths
    printf("\nDetected Wi-Fi signals:\n");
    printf("------------------------\n");
    printf("| Signal Name | Strength |\n");
    printf("------------------------\n");
    for(int i=0; i<num_signals; i++) {
        printf("| %-11s | %-8d|\n", signals[i].name, signals[i].strength);
    }
    printf("------------------------\n");
    
    //Find the strongest and weakest signals
    int strongest_index = 0, weakest_index = 0;
    for(int i=1; i<num_signals; i++) {
        if(signals[i].strength > signals[strongest_index].strength) {
            strongest_index = i;
        }
        if(signals[i].strength < signals[weakest_index].strength) {
            weakest_index = i;
        }
    }
    
    //Print the strongest and weakest signals
    printf("\nThe strongest signal is %s with a strength of %d dBm.\n", signals[strongest_index].name, signals[strongest_index].strength);
    printf("The weakest signal is %s with a strength of %d dBm.\n", signals[weakest_index].name, signals[weakest_index].strength);
    
    return 0;
}