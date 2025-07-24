//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char ip[15];
    int prefix;
    int mask = 0xffffffff << (32 - prefix);
    int a, b, c, d;
    sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
    int ipaddr = (a << 24) + (b << 16) + (c << 8) + d;
    int netaddr = ipaddr & mask;
    int broadaddr = netaddr | ~mask;
    printf("IP Address: %s\n", ip);
    printf("Network Address: %d.%d.%d.%d\n", (netaddr >> 24) & 0xff, (netaddr >> 16) & 0xff, (netaddr >> 8) & 0xff, netaddr & 0xff);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadaddr >> 24) & 0xff, (broadaddr >> 16) & 0xff, (broadaddr >> 8) & 0xff, broadaddr & 0xff);
    printf("First Host: %d.%d.%d.%d\n", ((netaddr + 1) >> 24) & 0xff, ((netaddr + 1) >> 16) & 0xff, ((netaddr + 1) >> 8) & 0xff, (netaddr + 1) & 0xff);
    printf("Last Host: %d.%d.%d.%d\n", ((broadaddr - 1) >> 24) & 0xff, ((broadaddr - 1) >> 16) & 0xff, ((broadaddr - 1) >> 8) & 0xff, broadaddr - 1 & 0xff);
    printf("Number of Hosts: %d\n", ((int)pow(2, 32 - prefix)) - 2);
    return 0;
}