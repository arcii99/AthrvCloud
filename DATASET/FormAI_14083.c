//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LIMIT 20
#define SCAN_INTERVAL 5000 //ms

struct Device {
    char name[DEVICE_NAME_LIMIT];
    char ip_addr[17];
    bool isActive;
};

int main() {
    struct Device devices[MAX_DEVICES];

    // initialize all devices to be inactive
    for (int i = 0; i < MAX_DEVICES; i++) {
        devices[i].isActive = false;
    }

    // continuously scan for devices on the network
    while (1) {
        FILE *fp;
        char buffer[1024];

        // ping all devices on the network
        for (int i = 0; i < MAX_DEVICES; i++) {
            char ping_command[50] = {'\0'};
            strcat(ping_command, "ping -c 2 -W 1 ");
            strcat(ping_command, devices[i].ip_addr);
            strcat(ping_command, " > /dev/null 2>&1"); //suppress output
            int response = system(ping_command);

            if (response == 0) {
                devices[i].isActive = true;
            } else {
                devices[i].isActive = false;
            }
        }

        // read device names from a text file
        fp = fopen("device_names.txt", "r");
        if (fp != NULL) {
            int i = 0;
            while (fgets(buffer, sizeof(buffer), fp)) {
                strtok(buffer, "\n"); // remove newline character
                strcpy(devices[i].name, buffer);
                i++;
            }
            fclose(fp);
        }

        // print active devices
        printf("Active devices:\n");
        for (int i = 0; i < MAX_DEVICES; i++) {
            if (devices[i].isActive) {
                printf("%s (%s)\n", devices[i].name, devices[i].ip_addr);
            }
        }

        // wait until next scan
        usleep(SCAN_INTERVAL * 1000);
    }

    return 0;
}