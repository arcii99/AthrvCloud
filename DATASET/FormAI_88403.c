//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// defining the function prototypes
int generateSignalStrength();
char* generateEncryption();
void analyzeSignalStrength(int signalStrength, char* encryption);

int main() {
    srand(time(NULL)); // to generate random numbers

    printf("Welcome to the Cyberpunk Wi-Fi Signal Strength Analyzer!\n");

    // getting input from the user
    char ssid[20];
    printf("Enter the SSID of the Wi-Fi network: ");
    fgets(ssid, 20, stdin);

    // generating random signal strength and encryption type
    int signalStrength = generateSignalStrength();
    char* encryption = generateEncryption();

    printf("Analyzing signal strength and encryption of SSID %s...\n\n", ssid);

    // analyzing the signal strength and encryption
    analyzeSignalStrength(signalStrength, encryption);

    return 0;
}

// function to generate random signal strength between -100 dBm and -30 dBm
int generateSignalStrength() {
    int signalStrength = rand() % (-29 - (-100) + 1) + (-100);
    return signalStrength;
}

// function to generate random encryption type
char* generateEncryption() {
    char* encryptionTypes[3] = {"WEP", "WPA", "WPA2"};
    int index = rand() % 3;
    char* encryption = encryptionTypes[index];
    return encryption;
}

// function to analyze the signal strength and encryption
void analyzeSignalStrength(int signalStrength, char* encryption) {
    printf("Signal Strength: %d dBm\n", signalStrength);

    if (signalStrength > -30) {
        printf("Signal strength is excellent!\n");
    } else if (signalStrength > -67) {
        printf("Signal strength is good.\n");
    } else if (signalStrength > -70) {
        printf("Signal strength is fair.\n");
    } else {
        printf("Signal strength is poor.\n");
    }

    printf("Encryption: %s\n", encryption);

    if (strcmp(encryption, "WEP") == 0) {
        printf("Warning! WEP encryption is highly vulnerable to attacks. Please switch to WPA or WPA2.\n");
    } else if (strcmp(encryption, "WPA") == 0) {
        printf("Good job! WPA encryption is relatively secure.\n");
    } else {
        printf("Excellent! WPA2 encryption is currently the most secure option.\n");
    }
}