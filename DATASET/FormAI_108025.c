//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    char ip[20], mask[20];
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", mask);

    int oct1, oct2, oct3, oct4;
    sscanf(ip, "%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4);

    int m1, m2, m3, m4;
    sscanf(mask, "%d.%d.%d.%d", &m1, &m2, &m3, &m4);

    int net1, net2, net3, net4;
    net1 = oct1 & m1;
    net2 = oct2 & m2;
    net3 = oct3 & m3;
    net4 = oct4 & m4;

    printf("\nNetwork Address is: %d.%d.%d.%d\n", net1, net2, net3, net4);

    int hostRange = 256 - m4;
    printf("Number of hosts per subnet: %d\n", hostRange - 2);

    return 0;
}