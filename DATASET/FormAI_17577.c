//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <ifaddrs.h>

#define MAX_INTERFACES 64
#define MAX_IP_LENGTH 16

int get_local_ip_addresses(char **ip_addrs) {
    struct ifaddrs * ifAddrStruct = NULL;
    void * tmpAddrPtr = NULL;
    int num_interfaces = 0;
   
    getifaddrs(&ifAddrStruct);
    
    while (ifAddrStruct != NULL) {
        if (num_interfaces == MAX_INTERFACES) break;
        if (ifAddrStruct->ifa_addr->sa_family == AF_INET) {
            tmpAddrPtr = &((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
            char* ip = (char*)malloc(sizeof(char) * MAX_IP_LENGTH);
            inet_ntop(AF_INET, tmpAddrPtr, ip, MAX_IP_LENGTH);
            ip_addrs[num_interfaces] = ip;
            num_interfaces++;
        }
        ifAddrStruct = ifAddrStruct->ifa_next;
    }
    return num_interfaces;
}

bool is_ip_in_subnet(char *ip, char *subnet, char *mask) {
    struct in_addr ip_addr, subnet_addr, mask_addr;
    inet_aton(ip, &ip_addr);
    inet_aton(subnet, &subnet_addr);
    inet_aton(mask, &mask_addr);
    return (ip_addr.s_addr & mask_addr.s_addr) == (subnet_addr.s_addr & mask_addr.s_addr);
}

void scan_wireless_networks() {
    char *ip_addrs[MAX_INTERFACES];
    int num_interfaces = get_local_ip_addresses(ip_addrs);
    
    for (int i = 0; i < num_interfaces; i++) {
        char subnet[MAX_IP_LENGTH];
        char mask[MAX_IP_LENGTH];
        char *ip = ip_addrs[i];
        int num_dots = 0;
        int dot_indexes[3];
        for (int j = 0; j < strlen(ip); j++) {
            if (ip[j] == '.') {
                dot_indexes[num_dots] = j;
                num_dots++;
            }
        }
        sprintf(subnet, "%.*s.0", dot_indexes[2], ip);
        sprintf(mask, "255.255.255.0");
        
        for (int k = 1; k < 256; k++) {
            char test_ip[MAX_IP_LENGTH];
            sprintf(test_ip, "%s.%d", subnet, k);
            if (strcmp(ip, test_ip) == 0) continue;
            if (is_ip_in_subnet(test_ip, subnet, mask)) {
                struct sockaddr_in sa;
                int sockfd = socket(AF_INET, SOCK_STREAM, 0);
                sa.sin_family = AF_INET;
                sa.sin_port = htons(80);
                inet_pton(AF_INET, test_ip, &sa.sin_addr);
                if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == 0) {
                    printf("Wireless network found at: %s\n", test_ip);
                }
                close(sockfd);
            }
        }
    }
}

int main() {
    scan_wireless_networks();
    return 0;
}