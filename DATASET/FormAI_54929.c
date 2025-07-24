//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: invasive
#include <stdio.h>

int main() {
    int signal_strength = 0;
    printf("Enter the value of signal strength (in dBm): ");
    scanf("%d", &signal_strength);

    if (signal_strength >= -30) {
        printf("Signal strength is excellent!\n");
    } else if (signal_strength >= -67) {
        printf("Signal strength is good!\n");
    } else if (signal_strength >= -70) {
        printf("Signal strength is fair!\n");
    } else if (signal_strength >= -80) {
        printf("Signal strength is poor!\n");
    } else {
        printf("Signal strength is weak!\n");
    }

    printf("Would you like to perform a Wi-Fi spectrum analysis? (y/n) ");
    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("Starting Wi-Fi spectrum analysis...\n");
        // code for Wi-Fi spectrum analysis goes here
    } else {
        printf("Exiting...\n");
    }

    return 0;
}