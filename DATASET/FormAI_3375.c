//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// constant values for the Wi-Fi signal strength
#define EXCELLENT 75
#define GOOD 50
#define FAIR 25
#define POOR 10

int main() {
    char cmd[100];
    char output[1024];
    int signal_strength;

    // run a system command to scan for Wi-Fi signals
    sprintf(cmd, "iwconfig wlan0 | grep Signal | awk '{print $4}' | sed 's/dBm//'");
    FILE* fp = popen(cmd, "r");

    // read the output of the command
    fgets(output, sizeof(output), fp);

    // close the file pointer
    pclose(fp);

    // extract the signal strength value
    signal_strength = atoi(output);

    // display the signal strength value
    printf("Wi-Fi signal strength: %d dBm\n", signal_strength);

    // classify the signal strength into levels
    if (signal_strength >= EXCELLENT) {
        printf("Signal strength is excellent!\n");
    } else if (signal_strength >= GOOD) {
        printf("Signal strength is good.\n");
    } else if (signal_strength >= FAIR) {
        printf("Signal strength is fair.\n");
    } else if (signal_strength >= POOR) {
        printf("Signal strength is poor.\n");
    } else {
        printf("No Wi-Fi signal detected.\n");
    }

    return 0;
}