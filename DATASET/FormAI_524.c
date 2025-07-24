//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check the Wi-Fi signal strength and display the result
void check_signal_strength(int signal_strength) {
    if(signal_strength >= -50) {
        printf("Signal strength is excellent!\n");
    } else if(signal_strength >= -60) {
        printf("Signal strength is good.\n");
    } else if(signal_strength >= -70) {
        printf("Signal strength is fair.\n");
    } else if(signal_strength >= -80) {
        printf("Signal strength is poor.\n");
    } else {
        printf("Signal strength is very poor - check connection.\n");
    }
}

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Please enter the signal strength in dBm: ");

    int signal_strength;
    scanf("%d", &signal_strength);

    // check if the signal strength is a valid integer
    if(signal_strength >= -100 && signal_strength <= 0) {
        check_signal_strength(signal_strength);
    } else {
        printf("Invalid signal strength - please enter a value between -100 and 0 dBm.\n");
    }

    return 0;
}