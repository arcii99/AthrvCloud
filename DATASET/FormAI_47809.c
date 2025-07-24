//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int signalStrength = rand() % 100;
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Your current Wi-Fi signal strength is %d%%\n", signalStrength);
    if(signalStrength > 75){
        printf("Wow! Your Wi-Fi signal strength is strong enough to stretch to the moon!\n");
    }
    else if(signalStrength <=75 && signalStrength > 50){
        printf("Looks like your Wi-Fi signal strength is good enough to teleport you to another dimension!\n");
    }
    else if(signalStrength <=50 && signalStrength > 25){
        printf("Hmm, your Wi-Fi signal strength is not strong enough to time travel, but you can still browse the web.\n");
    }
    else{
        printf("Oh no! Your Wi-Fi signal strength is too weak to support even text messaging!\n");
    }
    return 0;
}