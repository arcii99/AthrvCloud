//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEV 100
#define MAX_CHANNELS 10
#define WIFI_BANDWIDTH 20

struct device {
    int dID;
    char dName[20];
    int dChannel;
    int dSignal;
};

int main() {
    struct device devices[MAX_DEV];
    int num_devices = 0;

    int channels[MAX_CHANNELS];
    memset(channels, 0, sizeof(channels));

    srand(time(NULL));

    // Generate random devices and assign them to random channels
    for (int i = 0; i < MAX_DEV; i++) {
        devices[i].dID = i+1;
        sprintf(devices[i].dName, "Device%d", i+1);
        devices[i].dChannel = rand() % MAX_CHANNELS;
        devices[i].dSignal = rand() % 100 - 50; // Signal strength can be between -50 dBm to 50 dBm

        channels[devices[i].dChannel]++;
        num_devices++;
    }

    // Print out the devices and their channels
    printf("Wireless Network Scanner\n\n");
    printf("Number of Devices: %d\n\n", num_devices);
    printf("ID\tName\tChannel\tSignal\n");
    printf("------------------------------\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%d\t%s\t%d\t%d dBm\n", devices[i].dID, devices[i].dName, devices[i].dChannel, devices[i].dSignal);
    }
    printf("\n");

    // Print out the channel utilization
    printf("Channel\tUtilization\n");
    printf("-------------------\n");
    for (int i = 0; i < MAX_CHANNELS; i++) {
        float utilization = (float)channels[i] / num_devices * WIFI_BANDWIDTH;
        printf("%d\t%.2f MHz\n", i, utilization);
    }
    printf("\n");

    return 0;
}