//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 50
#define MAX_SSID_LEN 50

struct network {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
};

int main(void) {
    // Initialize variables and structures
    struct network networks[MAX_NETWORKS];
    int num_networks = 0;
    char line[100];

    // Open the system file containing Wi-Fi network information
    FILE *fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Check if the line contains an SSID and signal strength
            if (strstr(token, "SSID:") != NULL) {
                strncpy(networks[num_networks].ssid, token + 6, MAX_SSID_LEN);
                networks[num_networks].ssid[strlen(networks[num_networks].ssid) - 1] = '\0';
            } else if (strstr(token, "signal:") != NULL) {
                networks[num_networks++].signal_strength = atoi(token + 8);
            }
            token = strtok(NULL, " ");
        }
    }

    // Sort networks by signal strength (descending)
    for (int i = 0; i < num_networks; i++) {
        int max_idx = i;
        for (int j = i + 1; j < num_networks; j++) {
            if (networks[j].signal_strength > networks[max_idx].signal_strength) {
                max_idx = j;
            }
        }
        struct network temp = networks[i];
        networks[i] = networks[max_idx];
        networks[max_idx] = temp;
    }

    // Print out the Wi-Fi networks and signal strengths
    printf("%-20s%16s\n", "SSID", "Signal Strength");
    for (int i = 0; i < num_networks; i++) {
        printf("%-20s%16d\n", networks[i].ssid, networks[i].signal_strength);
    }

    // Close the file and exit
    fclose(fp);
    return 0;
}