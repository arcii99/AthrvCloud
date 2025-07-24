//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define MAX_RESULTS 10

// function to calculate signal strength percentage
int calculate_signal_strength(int signal_strength) {
    double percentage = ((double)signal_strength / 100.0) * 100.0;
    return round(percentage);
}

int main() {
    int i, j, k, rssi, highest_strength, strength_percentage, num_results = 0;
    char ssid[32], mac_address[18];
    int strengths[MAX_RESULTS];
    char ssids[MAX_RESULTS][32];

    // run command to scan for WiFi networks and save output to a file
    system("sudo iwlist wlan0 scan | grep 'ESSID\\|Signal' > scan_results.txt");

    // open file and start reading line by line
    FILE *file;
    file = fopen("scan_results.txt", "r");
    if (file) {
        while (!feof(file)) {
            // read line from file
            char line_buffer[128];
            fgets(line_buffer, sizeof(line_buffer), file);

            // check if line contains Network name (SSID)
            if (strstr(line_buffer, "ESSID:") != NULL) {
                // extract SSID and strip quotes and new lines
                sscanf(line_buffer, "          ESSID:\"%[^\"]\"", ssid);
                strtok(ssid, "\"");
                strtok(ssid, "\n");

                // check if SSID already exists in array
                int exists = 0;
                for (i = 0; i < num_results; i++) {
                    if (strcmp(ssid, ssids[i]) == 0) {
                        exists = 1;
                        break;
                    }
                }

                // if SSID doesn't exist, save it and retrieve its signal strength
                if (!exists && num_results < MAX_RESULTS) {
                    strcpy(ssids[num_results], ssid);

                    // loop through file until signal strength is found
                    while (!feof(file)) {
                        fgets(line_buffer, sizeof(line_buffer), file);

                        if (strstr(line_buffer, "Signal level=") != NULL) {
                            // extract signal strength and convert to percentage
                            sscanf(line_buffer, "          Quality=%*d/70  Signal level=%d dBm", &rssi);
                            strength_percentage = calculate_signal_strength(rssi);

                            // add percentage to array of strengths and increment results count
                            strengths[num_results] = strength_percentage;
                            num_results++;

                            break;
                        }
                    }
                }
            }

            // break loop if results limit is reached
            if (num_results >= MAX_RESULTS) {
                break;
            }
        }

        fclose(file);
    }

    // find highest strength and display network name and strength percentage
    highest_strength = 0;
    for (j = 0; j < num_results; j++) {
        if (strengths[j] > highest_strength) {
            highest_strength = strengths[j];
        }
    }

    printf("Highest Strength Network:\n");
    for (k = 0; k < num_results; k++) {
        if (strengths[k] == highest_strength) {
            printf("%s - %d%%\n", ssids[k], strengths[k]);
        }
    }

    return 0;
}