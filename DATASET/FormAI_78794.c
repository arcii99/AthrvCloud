//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIGNAL_STRENGTH 100
#define MAX_SSID_LENGTH 32

struct wifi_network {
    char ssid[MAX_SSID_LENGTH + 1];
    int signal_strength;
};

int main(void) {
    char input[100];
    struct wifi_network networks[10];
    int num_networks = 0;
    int i;

    printf("Wi-Fi Signal Strength Analyzer\n\n");

    // Input network information
    while (num_networks < 10) {
        printf("Enter SSID (up to %d characters) or type END to finish: ", MAX_SSID_LENGTH);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\r\n")] = '\0'; // Remove trailing newline
        if (strcasecmp(input, "END") == 0) {
            break;
        }
        strcpy(networks[num_networks].ssid, input);
        printf("Enter signal strength (0 to %d): ", MAX_SIGNAL_STRENGTH);
        fgets(input, sizeof(input), stdin);
        networks[num_networks].signal_strength = atoi(input);
        num_networks++;
    }

    // Print network information
    printf("\nSSID                    Signal Strength\n");
    printf("-----------------------------------------\n");
    for (i = 0; i < num_networks; i++) {
        printf("%-24s %d\n", networks[i].ssid, networks[i].signal_strength);
    }

    // Calculate average signal strength
    int sum = 0;
    double avg = 0.0;
    for (i = 0; i < num_networks; i++) {
        sum += networks[i].signal_strength;
    }
    if (num_networks > 0) {
        avg = (double) sum / num_networks;
    }

    // Print average signal strength
    printf("\nAverage signal strength: %.1f\n", avg);

    return 0;
}