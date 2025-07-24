//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char ssid[20];
    int signal_strength;
    
    printf("*** Wi-Fi Signal Analyzer ***\n\n");
    printf("Enter the SSID of the network: ");
    scanf("%s", ssid);
    printf("Enter the signal strength (-100dBm to 0dBm): ");
    scanf("%d", &signal_strength);
    
    if (signal_strength >= -50) {
        printf("Wow, your Wi-Fi signal is excellent! You must be very close to the router or access point.\n");
    }
    else if (signal_strength >= -75) {
        printf("Your Wi-Fi signal is good, but you could move closer to the router to get better reception.\n");
    }
    else if (signal_strength >= -85) {
        printf("Your Wi-Fi signal is fair. You might have some trouble streaming videos or downloading large files.\n");
    }
    else if (signal_strength >= -100) {
        printf("Your Wi-Fi signal is poor. You might not be able to connect to the network or experience slow internet speeds.\n");
    }
    else {
        printf("Invalid signal strength. Please enter a value between -100dBm and 0dBm.\n");
        exit(1);
    }
    
    printf("\nThank you for using the Wi-Fi Signal Analyzer! Happy browsing!\n");
    return 0;
}