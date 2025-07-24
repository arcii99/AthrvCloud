//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the constants
#define MINIMUM_STRENGTH 0
#define MAXIMUM_STRENGTH 100
#define MINIMUM_FREQUENCY 1
#define MAXIMUM_FREQUENCY 14

// Struct to store wifi signal strength
struct Wifisignal {
    int signalStrength;
    int frequency;
};

// Function to generate random signal strength
int generateRandomSignalStrength() {
    int signalStrength = (rand() % (MAXIMUM_STRENGTH - MINIMUM_STRENGTH + 1)) + MINIMUM_STRENGTH;
    return signalStrength;
}

// Function to generate random frequency
int generateRandomFrequency() {
    int frequency = (rand() % (MAXIMUM_FREQUENCY - MINIMUM_FREQUENCY + 1)) + MINIMUM_FREQUENCY;
    return frequency;
}

// Function to display signal strength and frequency
void displaySignalStrength(struct Wifisignal wifi) {
    printf("Signal Strength: %d\n", wifi.signalStrength);
    printf("Frequency: %d GHz\n", wifi.frequency);
}

// Function to analyze the wifi signal strength and frequency
void analyzeWifiSignal(struct Wifisignal wifi) {
    if(wifi.signalStrength < 20) {
        printf("Signal strength is very weak\n");
    }
    else if(wifi.signalStrength < 40) {
        printf("Signal strength is weak\n");
    }
    else if(wifi.signalStrength < 60) {
        printf("Signal strength is moderate\n");
    }
    else if(wifi.signalStrength < 80) {
        printf("Signal strength is strong\n");
    }
    else {
        printf("Signal strength is very strong\n");
    }
    
    if(wifi.frequency < 5) {
        printf("Frequency is in the 2.4 GHz band\n");
    }
    else {
        printf("Frequency is in the 5 GHz band\n");
    }
}

// Main function
int main() {
    printf("Welcome to Wi-Fi Signal Strength Analyzer\n\n");
    printf("Generating random Wi-Fi signal strength and frequency...\n");
    
    struct Wifisignal wifi;
    wifi.signalStrength = generateRandomSignalStrength();
    wifi.frequency = generateRandomFrequency();
    
    printf("\nGenerated Wi-Fi signal strength and frequency:\n");
    displaySignalStrength(wifi);
    
    printf("\nAnalyzing Wi-Fi signal strength and frequency...\n");
    analyzeWifiSignal(wifi);
    
    printf("\nThank you for using Wi-Fi Signal Strength Analyzer!\n");
    return 0;
}