//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define WLAN_INTERFACE "wlan0" // Change interface name 
#define WLAN_FILE "/proc/net/wireless"

// Function to get Wi-Fi signal strength
int get_signal_strength() {
    char buffer[256];
    FILE *fp;
    int signal_strength = 0;
    fp = fopen(WLAN_FILE, "r");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", WLAN_FILE);
        return -1;
    }
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, WLAN_INTERFACE)) {
            int quality = 0;
            char *tmp = strtok(buffer + strlen(WLAN_INTERFACE) + 2, " ");
            if (tmp) quality = atoi(tmp);
            signal_strength = (int)(((double)quality / 70) * 100);
            break;
        }
    }
    fclose(fp);
    return signal_strength;
}

int main() {
    int signal_strength = get_signal_strength();
    printf("Wi-Fi Signal Strength: %d%s\n", signal_strength, "%");
    return 0;
}