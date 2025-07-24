//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ultraprecise
#include <stdio.h>

int main() {
    int signal_strength;
    
    printf("Enter Wi-Fi signal strength (in dBm): ");
    scanf("%d", &signal_strength);
    
    if(signal_strength >= -30) {
        printf("Excellent signal strength!\n");
    } else if(signal_strength >= -67) {
        printf("Good signal strength.\n");
    } else if(signal_strength >= -70) {
        printf("Fair signal strength.\n");
    } else if(signal_strength >= -80) {
        printf("Poor signal strength.\n");
    } else {
        printf("No signal detected.\n");
    }
    
    return 0;
}