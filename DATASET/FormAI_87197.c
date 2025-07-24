//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

//Define a function to generate the random signal strength in the range of 0-100
int generateSignalStrength(){
    int signalStrength = (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
    return signalStrength;
}

int main(){

    printf("========================= Wi-Fi Signal Strength Analyzer =========================\n");

    int number_of_devices;
    printf("Enter the number of devices you want to analyze: ");
    scanf("%d", &number_of_devices);

    int signalStrengths[number_of_devices];
    char deviceNames[20][number_of_devices];

    //Take input from the user - device name and corresponding signal strength
    for(int i=0; i<number_of_devices; i++){
        printf("Enter the name of device %d: ", i+1);
        scanf("%s", deviceNames[i]);

        printf("Enter the signal strength for %s: ", deviceNames[i]);
        scanf("%d", &signalStrengths[i]);
    }

    printf("\n");

    //Simulate real-time fluctuations in the signal strength
    printf("========================= Real-time signal strength fluctuation =========================\n");
    while(1){
        for(int i=0; i<number_of_devices; i++){
            signalStrengths[i] = generateSignalStrength();
        }

        //Display the current signal strength
        for(int i=0; i<number_of_devices; i++){
            printf("%s\t", deviceNames[i]);
        }
        printf("\n");

        for(int i=0; i<number_of_devices; i++){
            printf("%d\t", signalStrengths[i]);
        }
        printf("\n");

        printf("\n\n");

        //Check if the signal strength is poor for any device
        for(int i=0; i<number_of_devices; i++){
            if(signalStrengths[i] < 50){
                printf("%s: Poor signal strength. Please move closer to the Wi-Fi router.\n", deviceNames[i]);
            }
        }

        //Wait for 2 seconds before updating the signal strength
        sleep(2);
    }

    return 0;
}