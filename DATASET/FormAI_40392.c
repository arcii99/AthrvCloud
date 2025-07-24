//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random signal strength value
int generateRandomSignal(){
    int signal = (rand() % 100) + 1;
    return signal;
}

//Function to check signal strength level
void checkSignalStrength(int signal){
    if(signal >= 90){
        printf("Signal Strength is Excellent!\n");
    }
    else if(signal >= 70){
        printf("Signal Strength is Good.\n");
    }
    else if(signal >= 50){
        printf("Signal Strength is Fair.\n");
    }
    else{
        printf("Signal Strength is Poor.\n");
    }
}

//Main Function
int main(){
    int signalStrength[10];
    int i, j;

    //Initializing seed for generating random numbers
    srand(time(NULL));

    //Generating 10 random signal strength values
    for(i = 0; i < 10; i++){
        signalStrength[i] = generateRandomSignal();
    }

    //Printing the signal strength levels
    printf("Wi-Fi Signal Strength Analyzer - Results\n");
    printf("=========================================\n");
    for(j = 0; j < 10; j++){
        printf("Test #%d: ", j+1);
        checkSignalStrength(signalStrength[j]);
    }

    return 0;
}