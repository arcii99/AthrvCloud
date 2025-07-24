//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 512
#define MAX_NETWORKS 25

struct wifi_network {
    int signal_strength;
    char ssid[32];
};

int main() {
    struct wifi_network networks[MAX_NETWORKS];
    int num_networks = 0;

    char buffer[MAX_LINE_LENGTH];
    FILE* fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        printf("Error opening wireless file.\n");
        return 1;
    }

    // Ignore the first two lines of the file.
    fgets(buffer, MAX_LINE_LENGTH, fp);
    fgets(buffer, MAX_LINE_LENGTH, fp);

    // Read in each network's signal strength and SSID.
    while (num_networks < MAX_NETWORKS && fgets(buffer, MAX_LINE_LENGTH, fp)) {
        char* token = strtok(buffer, " \t");
        int count = 0;
        while (token) {
            if (count == 2) {
                // This token should be the signal strength.
                networks[num_networks].signal_strength = atoi(token);
            } else if (count == 3) {
                // This token should be the SSID.
                strcpy(networks[num_networks].ssid, token + 1);
                // Remove the trailing quotation mark.
                networks[num_networks].ssid[strlen(networks[num_networks].ssid) - 1] = '\0';
                // Convert SSID to lowercase.
                for (int i = 0; i < strlen(networks[num_networks].ssid); i++) {
                    networks[num_networks].ssid[i] = tolower(networks[num_networks].ssid[i]);
                }
                num_networks++;
            }
            token = strtok(NULL, " \t");
            count++;
        }
    }
    fclose(fp);

    // Sort networks by signal strength.
    for (int i = 0; i < num_networks; i++) {
        for (int j = i + 1; j < num_networks; j++) {
            if (networks[j].signal_strength > networks[i].signal_strength) {
                struct wifi_network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }

    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("==============================\n");
    printf("Found %d wireless networks.\n", num_networks);
    printf("\n");

    // Print out each network's signal strength and SSID.
    for (int i = 0; i < num_networks; i++) {
        printf("%2d. %3d%% %s\n", i + 1, networks[i].signal_strength, networks[i].ssid);
    }

    return 0;
}