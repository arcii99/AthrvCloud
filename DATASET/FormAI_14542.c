//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32

int main() {
    char cmd[256];
    sprintf(cmd, "iwlist wlan0 scan | grep SSID > scan_result.txt");
    system(cmd);

    FILE* scan_result = fopen("scan_result.txt", "r");
    char line[256];

    int num_networks = 0;
    char networks[MAX_NETWORKS][MAX_SSID_LENGTH];
    while (fgets(line, sizeof(line), scan_result)) {
        char* ssid_start = strstr(line, "ESSID:");
        if (ssid_start != NULL) {
            ssid_start += strlen("ESSID:");
            char* ssid_end = strchr(ssid_start, '\"');
            if (ssid_end != NULL) {
                int ssid_length = ssid_end - ssid_start;
                if (ssid_length > 0 && ssid_length < MAX_SSID_LENGTH) {
                    strncpy(networks[num_networks], ssid_start, ssid_length);
                    networks[num_networks][ssid_length] = '\0';
                    num_networks++;
                }
            }
        }
    }

    fclose(scan_result);
    remove("scan_result.txt");

    printf("Found %d wireless networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s\n", i+1, networks[i]);
    }

    return 0;
}