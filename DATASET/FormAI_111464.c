//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Structure for storing network information
struct network {
    char essid[32];
    char bssid[18];
    float signal_strength;
};

int main() {
    system("iwlist wlan0 scan > scan.txt"); // Scan for networks and store output in a file
    FILE *fp = fopen("scan.txt", "r");
    if (fp == NULL) { // Check if file exists
        perror("Error opening file");
        return -1;
    }

    char line[1024];
    int count = 0;
    struct network *nets = malloc(sizeof(struct network)); // Allocate memory for network structures

    while (fgets(line, sizeof(line), fp)) { // Read each line of the file
        if (strstr(line, "ESSID:") != NULL) { // Extract network name
            char *name = strchr(line, '\"') + 1;
            char *ptr = strchr(name, '\"');
            *ptr = '\0'; // Remove extra characters
            strncpy(nets[count].essid, name, sizeof(nets[count].essid)); // Store network name
        }
        else if (strstr(line, "Address:") != NULL) { // Extract BSSID
            char *addr = strchr(line, ':') + 2;
            addr[strlen(addr)-1] = '\0'; // Remove newline character
            strncpy(nets[count].bssid, addr, sizeof(nets[count].bssid)); // Store BSSID
        }
        else if (strstr(line, "Signal level=") != NULL) { // Extract signal strength
            char *sig = strchr(line, '=') + 2;
            char *ptr = strchr(sig, ' ');
            *ptr = '\0'; // Remove extra characters
            float signal = atof(sig); // Convert to float
            nets[count].signal_strength = signal; // Store signal strength
            count++;
            nets = realloc(nets, (count+1)*sizeof(struct network)); // Reallocate memory for next network
        }
    }

    fclose(fp); // Close file

    // Print all networks with their information
    for (int i=0; i<count; i++) {
        printf("ESSID: %s\n", nets[i].essid);
        printf("BSSID: %s\n", nets[i].bssid);
        printf("Signal Strength: %.2f dBm\n", nets[i].signal_strength);
        printf("--------------------------\n");
    }

    free(nets); // Free up allocated memory
    return 0;
}