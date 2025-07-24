//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
#include<string.h>  

int cidrToMask(int cidr) {
    int mask = 0xffffffff << (32 - cidr);
    return mask;
}

void maskToIp(int mask, char *ip) {
    unsigned char *bytes = (unsigned char *)&mask;
    sprintf(ip, "%d.%d.%d.%d", bytes[0], bytes[1], bytes[2], bytes[3]);
}

void printNetworkDetails(unsigned int network, int cidr) {
    char netIp[16];
    char maskIp[16];
    maskToIp(cidrToMask(cidr), maskIp);
    unsigned int broadcast = network | (~cidrToMask(cidr));
    char bcastIp[16];
    unsigned char *bytes = (unsigned char *)&broadcast;
    sprintf(bcastIp, "%d.%d.%d.%d", bytes[0], bytes[1], bytes[2], bytes[3]);
    maskToIp(network, netIp);
    printf("Network Address: %s/%d Mask: %s\n", netIp, cidr, maskIp);
    printf("Broadcast Address: %s\n", bcastIp);
    printf("Total Number of Hosts: %d\n", (int)pow(2, 32 - cidr) - 2);
}

int main() {
    char ip[16];
    int cidr;
    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter CIDR: ");
    scanf("%d", &cidr);
    printf("IP Address: %s/%d\n", ip, cidr);
    unsigned int network = 0;
    char *octet = strtok(ip, ".");
    while (octet != NULL) {
        network = (network << 8) | atoi(octet);
        octet = strtok(NULL, ".");
    }
    network = network & cidrToMask(cidr);
    printNetworkDetails(network, cidr);
    return 0;
}