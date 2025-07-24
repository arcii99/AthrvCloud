//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_DEVICE  32

typedef struct {
    char id[18];
    char ssid[32];
    int  rssi;
} device_t;

typedef struct {
    device_t device[MAX_DEVICE];
    int count;
} network_t;

int scan_wireless_network(network_t* pNetwork) {
    int i, j, sock, total;
    struct sockaddr_in serv;
    char buf[1024], found[32];
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        return -1;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("255.255.255.255");
    serv.sin_port = htons(8889);
    for (i = 0; i < 10; i++) {
        sendto(sock, "HF-A11ASSISTHREAD", 17, 0, (struct sockaddr*)(&serv), sizeof(serv));
        usleep(100000);
    }
    memset(buf, 0, sizeof(buf));
    total = recvfrom(sock, buf, sizeof(buf) - 1, 0, NULL, NULL);
    if (total < 6)
        return -1;
    memset(pNetwork, 0, sizeof(network_t));
    pNetwork->count = 0;
    for (i = 6; i < total;) {
        memset(found, 0, sizeof(found));
        for (j = 0; buf[i] != ',' && i < total; i++, j++) {
            if (j < sizeof(found) - 1)
                found[j] = buf[i];
        }
        if (strlen(found) == 17) {
            device_t* pDevice = &pNetwork->device[pNetwork->count];
            memset(pDevice, 0, sizeof(device_t));
            memcpy(pDevice->id, found, strlen(found));
            i++;
            j = 0;
            memset(found, 0, sizeof(found));
            for (; buf[i] != ',' && i < total; i++, j++) {
                if (j < sizeof(found) - 1)
                    found[j] = buf[i];
            }
            memcpy(pDevice->ssid, found, strlen(found));
            i++;
            j = 0;
            memset(found, 0, sizeof(found));
            for (; buf[i] != ',' && i < total; i++, j++) {
                if (j < sizeof(found) - 1)
                    found[j] = buf[i];
            }
            pDevice->rssi = strtol(found, NULL, 10) * -1;
            pNetwork->count++;
        } else {
            i++;
        }
    }
    return pNetwork->count;
}

int main(void) {
    network_t network;
    int count;
    int i, j;
    count = scan_wireless_network(&network);
    printf("\n");
    if (count <= 0) {
        printf("No wireless network found.\n");
    } else {
        printf("Found %d wireless network.\n\n", count);
        printf("----------------------------------\n");
        printf("|    ID       |    SSID          |\n");
        printf("----------------------------------\n");
        for (i = 0; i < count; i++) {
            device_t* pDevice = &network.device[i];
            printf("| %s | ", pDevice->id);
            for (j = 0; j < strlen(pDevice->ssid); j++)
                printf("%c", pDevice->ssid[j] ^ 0x55);
            printf(" |\n");
        }
        printf("----------------------------------\n");
    }
    return 0;
}