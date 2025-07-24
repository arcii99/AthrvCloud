//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IPLEN 16
#define MAXMASK 30

int validateIP(char *ip) {
    int count = 0;
    char *pch = strtok(ip, ".");
    while(pch != NULL) {
        if (strlen(pch) > 3)
            return 1;
        for (int i = 0; i < strlen(pch); i++)
            if (!isdigit(pch[i]))
                return 1;
        int num = atoi(pch);
        if (num < 0 || num > 255)
            return 1;
        count++;
        pch = strtok(NULL, ".");
    }
    if (count != 4)
        return 1;
    return 0;
}

int validateMask(char *mask) {
    if (strlen(mask) > 2 || !isdigit(mask[0]))
        return 1;
    int num = atoi(mask);
    if (num < 0 || num > MAXMASK)
        return 1;
    return 0;
}

void calculateSubnet(char *ip, char *mask) {
    int octet[4], submask[4], network[4], broadcast[4];
    sscanf(ip, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);
    memset(submask, 0, sizeof(submask));
    memset(network, 0, sizeof(network));
    memset(broadcast, 0, sizeof(broadcast));
    int masklen = atoi(mask);
    for (int i = 0; i < masklen; i++) {
        int j = i / 8;
        int k = i % 8;
        submask[j] |= 1 << (7 - k);
    }
    for (int i = 0; i < 4; i++) {
        network[i] = octet[i] & submask[i];
        broadcast[i] = network[i] | ~submask[i];
    }
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
}

int main() {
    char ip[IPLEN], mask[3];
    printf("Enter IP address: ");
    fgets(ip, IPLEN, stdin);
    ip[strcspn(ip, "\n")] = 0;
    if (validateIP(ip)) {
        printf("Invalid IP address!\n");
        return 1;
    }
    printf("Enter subnet mask: ");
    fgets(mask, 3, stdin);
    mask[strcspn(mask, "\n")] = 0;
    if (validateMask(mask)) {
        printf("Invalid subnet mask!\n");
        return 1;
    }
    calculateSubnet(ip, mask);
    return 0;
}