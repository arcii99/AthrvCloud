//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0
#define SCAN_TIME 1000

int main() {
    char ssid[50], cmd[200];
    int signal_strength = 0;
    printf("Enter the SSID of the WiFi network: ");
    scanf("%s", ssid);
    while (signal_strength == 0) {
        printf("\n\nScanning for WiFi Signal Strength...\n\n");
        sprintf(cmd, "iwconfig wlan0 | grep %s | awk '{print $4}' | cut -d'/' -f1", ssid);
        FILE* fp = popen(cmd, "r");
        if (fp == NULL) {
            perror("Failed to execute command!\n");
            return 1;
        }
        char result[10];
        fgets(result, 10, fp);
        signal_strength = atoi(result);
        pclose(fp);
        printf("Signal Strength: %d/100\n", signal_strength);
        if (signal_strength < 20) {
            printf("Signal too weak, please move closer to the router and try again.\n");
            signal_strength = 0;
            sleep(SCAN_TIME);
        }
    }
    printf("Signal strength is strong enough. Proceeding with further operations...\n");
    // Rest of the program logic goes here
    return 0;
}