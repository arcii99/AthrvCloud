//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the SSID
#define MAX_SSID_LENGTH 32

// Define the number of Wi-Fi channels
#define NUM_CHANNELS 14

// Define the maximum number of access points that can be detected
#define MAX_ACCESS_POINTS 10

// Define a structure to store information about each access point
typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int channel;
    int signal_strength;
} access_point;

// Define a function to parse the output of iwlist scanning and extract information about access points
int parse_iwlist_output(char* output, access_point* access_points, int* num_access_points) {
    // Initialize variables
    char* line;
    char* token;
    char channel_str[4];
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int signal_strength = 0;

    // Loop through each line of the output
    line = strtok(output, "\n");
    while (line != NULL) {
        // Check if the line contains the SSID of an access point
        if (strstr(line, "ESSID:\"") != NULL) {
            // Extract the SSID from the line
            token = strtok(line, "\"");
            token = strtok(NULL, "\"");
            strcpy(access_points[i].ssid, token);

            // Check if the SSID is empty or "hidden"
            if (strlen(access_points[i].ssid) == 0 || strcmp(access_points[i].ssid, "<hidden>") == 0) {
                i--;
            }
            else {
                *num_access_points = *num_access_points + 1;
            }

            i++;
        }

        // Check if the line contains the channel of an access point
        if (strstr(line, "Channel:") != NULL) {
            // Extract the channel from the line
            token = strtok(line, ":");
            token = strtok(NULL, ":");
            strcpy(channel_str, token);

            // Convert the channel to an integer
            access_points[j].channel = atoi(channel_str);

            j++;
        }

        // Check if the line contains the signal strength of an access point
        if (strstr(line, "Signal level=") != NULL) {
            // Extract the signal strength from the line
            token = strtok(line, "=");
            token = strtok(NULL, "=");
            token = strtok(token, "/");
            signal_strength = atoi(token);

            // Convert the signal strength to dBm
            access_points[k].signal_strength = signal_strength - 100;

            k++;
        }

        line = strtok(NULL, "\n");
    }

    // Return the number of access points found
    return *num_access_points;
}

// Define a function to print information about each access point
void print_access_points(access_point* access_points, int num_access_points) {
    int i;

    // Print the header
    printf("%-30s %5s %5s\n", "SSID", "Ch.", "Signal");

    // Loop through each access point and print its information
    for (i = 0; i < num_access_points; i++) {
        printf("%-30s %5d %5d dBm\n", access_points[i].ssid, access_points[i].channel, access_points[i].signal_strength);
    }
}

// Define the main function
int main() {
    // Define variables
    char command[128];
    char output[4096];
    access_point access_points[MAX_ACCESS_POINTS];
    int num_access_points = 0;
    int i;
    int j;
    int k;

    // Loop through each Wi-Fi channel and scan for access points
    for (i = 1; i <= NUM_CHANNELS; i++) {
        // Build the command to scan for access points on the current channel
        sprintf(command, "sudo iwlist wlan0 channel %d scan | grep -E 'ESSID:|Channel:|Signal level='", i);

        // Run the command and capture the output
        FILE* fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error running command: %s", command);
            exit(1);
        }
        while (fgets(output, sizeof(output), fp) != NULL);

        // Close the command output file pointer
        pclose(fp);

        // Parse the output and extract information about access points
        num_access_points = parse_iwlist_output(output, access_points, &num_access_points);
    }

    // Print information about each access point
    print_access_points(access_points, num_access_points);

    return 0;
}