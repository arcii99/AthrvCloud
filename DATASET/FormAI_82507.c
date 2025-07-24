//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

// Global variables
#define MAX_SSID_LENGTH 128
#define MAX_BSSID_LENGTH 20

// Function to print the results of the scan
void print_results(char ssid[MAX_SSID_LENGTH], char bssid[MAX_BSSID_LENGTH], int signal_strength) {

    printf("Found network with SSID: %s\n", ssid);
    printf("BSSID: %s\n", bssid);
    printf("Signal strength: %d dBm\n", signal_strength);
}

int main() {

    printf("Welcome to the C Wireless Network Scanner!\n");

    char cmd[128] = "sudo iwlist wlan0 scan";
    char buf[256];
    char *token;
    const char *delimiter = "\n";

    // Start the scan
    FILE *fp = popen(cmd, "r");

    if (fp == NULL) {
        printf("Error: Failed to run scan command.\n");
        return -1;
    }

    // Read the output of the scan command
    while (fgets(buf, sizeof(buf), fp) != NULL) {

        // Find the SSID of the network
        if (strstr(buf, "ESSID:") != NULL) {

            char ssid[MAX_SSID_LENGTH];  // Allocate memory for SSID
            int i = 0;

            // Treat the token after 'ESSID:' as the SSID until the next quote mark
            token = strtok(buf, "\"");
            while (token != NULL) {
                if (i == 1) {
                    strcpy(ssid, token);
                    break;
                }
                token = strtok(NULL, "\"");
                i++;
            }

            // Find the BSSID and signal strength of the network
            while (fgets(buf, sizeof(buf), fp) != NULL) {

                char bssid[MAX_BSSID_LENGTH];  // Allocate memory for BSSID

                // Find the BSSID of the network
                if (strstr(buf, "Address:") != NULL) {
                    token = strtok(buf, " ");
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");

                    // Only copy the first 17 characters of the BSSID
                    strncpy(bssid, token, MAX_BSSID_LENGTH);
                }

                // Find the signal strength of the network
                if (strstr(buf, "Signal level=") != NULL) {
                    token = strtok(buf, "=");
                    token = strtok(NULL, " ");
                    int signal_strength = atoi(token);

                    // Print the results of the scan
                    print_results(ssid, bssid, signal_strength);
                    break;
                }
            }
        }
    }

    // Close the file pointer
    pclose(fp);

    printf("Thanks for using the C Wireless Network Scanner! Check your results carefully, as they may contain some fowl play.\n");

    return 0;
}