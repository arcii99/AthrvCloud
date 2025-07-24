//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    time_t t;
    srand((unsigned) time(&t)); // initializing random seed

    int signal_strength;
    char* status;

    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("=============================\n\n");

    printf("Scanning for signal strength...\n");

    // generating random signal strength between -100 and 0
    signal_strength = rand() % 101 - 100;

    printf("Signal strength: %d dBm\n", signal_strength);

    if(signal_strength > -50){
        status = "Excellent";
    }
    else if(signal_strength > -60){
        status = "Good";
    }
    else if(signal_strength > -70){
        status = "Fair";
    }
    else if(signal_strength > -80){
        status = "Weak";
    }
    else{
        status = "Poor";
    }

    printf("Signal status: %s\n", status);

    return 0;
}