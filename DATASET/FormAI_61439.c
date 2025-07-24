//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
/*  

    C subnet calculator 
    In honor of Ken Thompson
    Creator of Unix

*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(){
    printf("Ken Thompson's subnet calculator\n-------------------------------\n");

    char ip_address[16], subnet[16];
    printf("Enter IP address: ");
    scanf("%s", &ip_address);
    printf("Enter subnet mask: ");
    scanf("%s", &subnet);

    struct in_addr addr_ip, addr_subnet, addr_network, addr_broadcast;
    inet_aton(ip_address, &addr_ip);
    inet_aton(subnet, &addr_subnet);

    addr_network.s_addr = addr_ip.s_addr & addr_subnet.s_addr;
    addr_broadcast.s_addr = addr_ip.s_addr | (~addr_subnet.s_addr);

    printf("\nIP address: %s\n", inet_ntoa(addr_ip));
    printf("Subnet mask: %s\n", inet_ntoa(addr_subnet));
    printf("Network address: %s\n", inet_ntoa(addr_network));
    printf("Broadcast address: %s\n", inet_ntoa(addr_broadcast));

    // count the number of 1's in binary notation of the subnet mask
    int count_one = 0;
    for (int i=0; i<32; i++){
        if ((addr_subnet.s_addr >> i) & 1)
            count_one++;
    }

    int max_hosts = (1 << (32 - count_one)) - 2;
    printf("Maximum hosts per subnet: %d\n", max_hosts);

    return 0;
}