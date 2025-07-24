//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum network devices
#define MAX_DEVICES 100

int main()
{
    // Create a list of network devices
    char devices[MAX_DEVICES][20] = {
        "Knight's Router",
        "Castle's WiFi",
        "Dragon's Network",
        "Wizard's WiFi",
        "King's Internet"
    };

    int num_devices = sizeof(devices) / sizeof(devices[0]);

    printf("Scanning for wireless networks...\n");

    // Scan for available wireless networks
    for(int i = 0; i < num_devices; i++)
    {
        printf("Searching for '%s'...\n", devices[i]);
        int r = rand() % 100;

        // Check if network device is detected
        if(r > 50)
        {
            printf("'%s' is detected! Connected.\n", devices[i]);
        }
        else
        {
            printf("'%s' is not found.\n", devices[i]);
        }
    }

    printf("Scanning complete.\n");

    return 0;
}