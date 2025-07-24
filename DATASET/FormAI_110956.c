//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate(char* ip_address, char* subnet_mask) {
    char* token;
    int ip[4], sm[4], nw[4], bc[4];

    token = strtok(ip_address, ".");
    for(int i=0;i<4;i++) {
        ip[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    token = strtok(subnet_mask, ".");
    for(int i=0;i<4;i++) {
        sm[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    for(int i=0;i<4;i++) {
        nw[i] = ip[i] & sm[i];
        bc[i] = nw[i] | (~sm[i] & 255);
    }

    printf("Network Address: %d.%d.%d.%d\n", nw[0], nw[1], nw[2], nw[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", bc[0], bc[1], bc[2], bc[3]);
}

int main() {
    char ip_address[16], subnet_mask[16];
    printf("Enter IP Address: ");
    scanf("%s", ip_address);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);
    calculate(ip_address, subnet_mask);
    return 0;
}