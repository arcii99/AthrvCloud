//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_INTERFACE_LENGTH 16

void scan_wireless_networks(char *interface) {
    char command[MAX_INTERFACE_LENGTH + 40];
    sprintf(command, "sudo iwlist %s scan | grep ESSID", interface);
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command\n");
        exit(EXIT_FAILURE);
    }
    char output[256], *essid;
    int count = 0;
    while (fgets(output, sizeof(output), fp)) {
        if ((essid = strstr(output, "ESSID:\"")) == NULL) {
            continue;
        }
        essid += strlen("ESSID:\"");
        essid[strcspn(essid, "\"")] = '\0';
        printf("%s\n", essid);
        count++;
    }
    if (count == 0) {
        printf("No wireless networks found\n");
    }
    pclose(fp);
}

int main(int argc, char **argv) {
    char interface[MAX_INTERFACE_LENGTH] = "wlan0";
    if (argc > 1) {
        strncpy(interface, argv[1], MAX_INTERFACE_LENGTH - 1);
    }
    printf("Scanning wireless networks on interface %s\n", interface);
    scan_wireless_networks(interface);
    return EXIT_SUCCESS;
}