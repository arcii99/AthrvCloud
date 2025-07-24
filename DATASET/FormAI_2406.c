//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_CIDR 32
#define MIN_CIDR 0
#define MAX_IP 255
#define MIN_IP 0

struct IPAddress {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};

struct SubnetMask {
    int cidr;
    struct IPAddress maskIP;
};

void printIPAddress(struct IPAddress ip) {
    printf("%d.%d.%d.%d", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

bool isIPAddressValid(struct IPAddress ip) {
    return (ip.octet1 >= MIN_IP && ip.octet1 <= MAX_IP) &&
           (ip.octet2 >= MIN_IP && ip.octet2 <= MAX_IP) &&
           (ip.octet3 >= MIN_IP && ip.octet3 <= MAX_IP) &&
           (ip.octet4 >= MIN_IP && ip.octet4 <= MAX_IP);
}

bool isSubnetMaskValid(int cidr, struct IPAddress maskIP) {
    if (cidr < MIN_CIDR || cidr > MAX_CIDR) {
        return false;
    }
    int mask = ((int)pow(2, cidr) - 1) << (MAX_CIDR - cidr);
    return ((maskIP.octet1 == ((mask & 0xFF000000) >> 24)) &&
            (maskIP.octet2 == ((mask & 0x00FF0000) >> 16)) &&
            (maskIP.octet3 == ((mask & 0x0000FF00) >> 8)) &&
            (maskIP.octet4 == (mask & 0x000000FF)));
}

int countOnesInBinary(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void printSubnetMaskInfo(struct SubnetMask subnetMask) {
    printf("Subnet Mask: ");
    printIPAddress(subnetMask.maskIP);
    printf("/%d\n", subnetMask.cidr);
    int numOfOnesInBinary = countOnesInBinary((int)pow(2, MAX_CIDR - subnetMask.cidr) - 1);
    printf("Number of Subnets: %d", (int)pow(2, subnetMask.cidr));
    printf("\nNumber of Hosts per Subnet: %d", (int)pow(2, numOfOnesInBinary) - 2);
}

struct SubnetMask calculateSubnetMask(int numSubnets, int numHosts) {
    int numOfSubnetsBits = (int)ceil(log2(numSubnets));
    int numOfHostsBits = (int)ceil(log2(numHosts + 2));
    int cidr = MAX_CIDR - numOfSubnetsBits - numOfHostsBits;
    int mask = ((int)pow(2, cidr) - 1) << (MAX_CIDR - cidr);
    struct SubnetMask subnetMask;
    subnetMask.cidr = cidr;
    subnetMask.maskIP.octet1 = (mask & 0xFF000000) >> 24;
    subnetMask.maskIP.octet2 = (mask & 0x00FF0000) >> 16;
    subnetMask.maskIP.octet3 = (mask & 0x0000FF00) >> 8;
    subnetMask.maskIP.octet4 = mask & 0x000000FF;
    return subnetMask;
}

int main() {
    struct IPAddress ip;
    printf("Enter IP Address (e.g. 192.168.1.1): ");
    scanf("%d.%d.%d.%d", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);
    if (!isIPAddressValid(ip)) {
        printf("Invalid IP Address!");
        return 0;
    }
    struct SubnetMask subnetMask;
    printf("Enter Subnet Mask (in CIDR notation e.g. 24): ");
    scanf("%d", &subnetMask.cidr);
    printf("Enter Number of Subnets Required: ");
    int numSubnets;
    scanf("%d", &numSubnets);
    printf("Enter Number of Hosts Required per Subnet: ");
    int numHosts;
    scanf("%d", &numHosts);
    subnetMask = calculateSubnetMask(numSubnets, numHosts);
    if (!isSubnetMaskValid(subnetMask.cidr, subnetMask.maskIP)) {
        printf("Invalid Subnet Mask!");
        return 0;
    }
    printSubnetMaskInfo(subnetMask);
    return 0;
}