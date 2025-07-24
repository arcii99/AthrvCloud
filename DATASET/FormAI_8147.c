//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    printf("***** Wi-Fi Signal Strength Analyzer *****\n\n");

    srand(time(0)); // for generating random signal strengths

    int signalStrength;
    char signalQuality;

    printf("Scanning current Wi-Fi signal strength...\n");
    signalStrength = rand()%101; // generating random signal strength between 0-100
    printf("\nSignal Strength: %d%%\n", signalStrength);

    if(signalStrength >= 80){
        signalQuality = 'E'; // Excellent Quality
    }
    else if(signalStrength >= 60){
        signalQuality = 'G'; // Good Quality
    }
    else if(signalStrength >= 40){
        signalQuality = 'A'; // Average Quality
    }
    else if(signalStrength >= 20){
        signalQuality = 'F'; // Fair Quality
    }
    else{
        signalQuality = 'P'; // Poor Quality
    }

    printf("Signal Quality: %c\n", signalQuality);

    printf("\n\n***** Thank you for using Wi-Fi Signal Strength Analyzer *****\n");

    return 0;
}