//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>
#include <net/if.h>

#define MAX_BUFFER_LENGTH 65536

int main(void) {
    struct ifaddrs *ifaddr, *ifa;
    char buffer[MAX_BUFFER_LENGTH];
    int sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        perror("Error: Couldn't create socket");
        return EXIT_FAILURE;
    }
    if (getifaddrs(&ifaddr) == -1) {
        perror("Error: Couldn't get interface address");
        return EXIT_FAILURE;
    }
    printf("Wireless network scanners running...\n");
    while (1) {
        memset(buffer, 0, MAX_BUFFER_LENGTH);
        int length = recv(sockfd, buffer, MAX_BUFFER_LENGTH, MSG_DONTWAIT);
        if (length > 0) {
            struct ethhdr *ethhdr_ptr = (struct ethhdr*) buffer;
            if (ethhdr_ptr->h_proto == htons(ETH_P_IP)) {
                struct iphdr *iphdr_ptr = (struct iphdr*) (buffer + sizeof(struct ethhdr));
                for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
                    if (ifa->ifa_addr == NULL)
                        continue;
                    if (iphdr_ptr->daddr == ((struct sockaddr_in *)ifa->ifa_addr)->sin_addr.s_addr) {
                        char ip[INET_ADDRSTRLEN];
                        inet_ntop(AF_INET, &iphdr_ptr->daddr, ip, INET_ADDRSTRLEN);
                        printf("Wireless network scanner detected! IP address: %s on interface: %s\n", ip, ifa->ifa_name);
                        break;
                    }
                }
            }
        }
    }
    freeifaddrs(ifaddr);
    close(sockfd);
    return EXIT_SUCCESS;
}