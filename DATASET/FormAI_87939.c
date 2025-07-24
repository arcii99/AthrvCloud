//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <arpa/inet.h>

int main() {
    char ip_address[20];
    int cidr_prefix;
    printf("Enter IP address in CIDR notation:\n");
    scanf("%s/%d",ip_address, &cidr_prefix);

    struct in_addr addr;
    inet_aton(ip_address, &addr);

    int mask = htonl(-1 << (32 - cidr_prefix));
    int network = ntohl(addr.s_addr) & mask;
    int broadcast = network | ~mask;

    printf("\n\tCyberpunk Subnet Calculator\n");
    printf("\t------------------------\n\n");
    printf("IP Address: %s\n",ip_address);
    printf("CIDR Prefix: /%d\n",cidr_prefix);
    printf("Subnet Mask: %d.%d.%d.%d\n",(mask>>24)&0xff,(mask>>16)&0xff,(mask>>8)&0xff,mask&0xff);
    printf("Network Address: %d.%d.%d.%d\n",(network>>24)&0xff,(network>>16)&0xff,(network>>8)&0xff,network&0xff);
    printf("Broadcast Address: %d.%d.%d.%d\n",(broadcast>>24)&0xff,(broadcast>>16)&0xff,(broadcast>>8)&0xff,broadcast&0xff);
    printf("Number of Hosts in Subnet: %d\n", (broadcast - network) - 1);
    
    printf("\n\tStay secure in the Cybernet!\n");
    return 0;
}