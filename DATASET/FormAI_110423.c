//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>


#define MAX_IP_ADDR_LENGTH 16
#define MAX_NAME_LENGTH 256
#define MAX_MAC_ADDR_LENGTH 17

struct WirelessDeviceInfo {
    char name[MAX_NAME_LENGTH];
    char macAddr[MAX_MAC_ADDR_LENGTH];
    char ipAddr[MAX_IP_ADDR_LENGTH];
};

void printDeviceInfo(struct WirelessDeviceInfo *device) {
    printf("Name: %s\n", device->name);
    printf("MAC Address: %s\n", device->macAddr);
    printf("IP Address: %s\n\n", device->ipAddr);
}

int main(int argc, char const *argv[]) {
    int sock;
    struct ifreq ifr;
    char mac[6];
    char *interface = "wlan0";
    char buf[1024];
    struct WirelessDeviceInfo devices[20];
    int numDevices = 0;

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);

    if (ioctl(sock, SIOCGIFHWADDR, &ifr) < 0) {
        perror("ioctl");
        exit(1);
    }

    memcpy(mac, ifr.ifr_hwaddr.sa_data, 6);

    printf("Scanning for wireless devices on network...\n");
    printf("--------------------------------------------------\n");

    FILE *fp;
    char output[1024];
    char cmd[128];
    char ipAddr[MAX_IP_ADDR_LENGTH];
    memset(devices, 0, sizeof(struct WirelessDeviceInfo) * 20);

    for (int i=0; i<256; i++) {
        memset(cmd, 0, sizeof(cmd));
        sprintf(cmd, "ping -c 1 -w 1 192.168.1.%d 2>/dev/null", i);
        fp = popen(cmd, "r");
        if (fp == NULL) {
            printf("Failed to execute system command.\n");
            exit(1);
        }

        while (fgets(output, sizeof(output)-1, fp) != NULL) {
            if (strstr(output, "bytes from ") != NULL) {
                strncpy(ipAddr, strstr(output, "bytes from ")+11, MAX_IP_ADDR_LENGTH);
                if (strstr(output, "64 bytes from ") != NULL) {
                    ipAddr[strlen(ipAddr)-2] = '\0';
                } else {
                    ipAddr[strlen(ipAddr)-1] = '\0';
                }
                printf("Found device at IP Address %s\n", ipAddr);
                memset(buf, 0, sizeof(buf));
                sprintf(buf, "arp -n %s", ipAddr);
                fp = popen(buf, "r");
                if (fp != NULL) {
                    char output2[1024];
                    while (fgets(output2, sizeof(output2)-1, fp) != NULL) {
                        if (strstr(output2, "ether ") != NULL) {
                            char *token = strtok(output2, " \t\n");
                            int tokenNum = 0;
                            while (token != NULL) {
                                if (tokenNum == 2) {
                                    strncpy(devices[numDevices].macAddr, token, MAX_MAC_ADDR_LENGTH);
                                }
                                tokenNum++;
                                token = strtok(NULL, " \t\n");
                            }
                            numDevices++;
                        }
                    }
                }
            }
        }

        pclose(fp);
    }

    struct hostent *hs;
    memset(buf, 0, sizeof(buf));

    for (int i = 0; i < numDevices; i++) {
        sprintf(buf, "nmblookup -A %s 2>/dev/null | grep '<00>' | awk '{print $1}'", devices[i].ipAddr);
        fp = popen(buf, "r");
        if (fp != NULL) {
            char output3[1024];
            if (fgets(output3, sizeof(output3)-1, fp) != NULL) {
                output3[strlen(output3)-1] = '\0';
                printf("Found device with Name '%s'\n", output3);
                strncpy(devices[i].name, output3, MAX_NAME_LENGTH);
            }
        }
        pclose(fp);
    }


    printf("\nWireless devices found on network:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numDevices; i++) {
        printDeviceInfo(&devices[i]);
    }

    return 0;
}