//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

#define MAX_INTERFACES 64
#define MAX_BUFFER_SIZE 1024

struct interface {
    int index;
    char name[IFNAMSIZ];
    char ip[INET_ADDRSTRLEN];
    char mac[18];
};

struct interface interfaces[MAX_INTERFACES];
int num_interfaces;

void get_interfaces() {
    struct ifreq ifr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int i = 0;

    for (i = 0; i < MAX_INTERFACES; i++) {
        interfaces[i].index = -1;
    }

    strcpy(ifr.ifr_name, "");
    int count = 0;
    for (i = 0; i < MAX_INTERFACES; i++) {
        if (ioctl(sockfd, SIOCGIFNAME, &ifr) < 0) break;

        if (strcmp(ifr.ifr_name, "lo")) {
            interfaces[count].index = i;
            strncpy(interfaces[count].name, ifr.ifr_name, IFNAMSIZ - 1);
            
            ioctl(sockfd, SIOCGIFADDR, &ifr);
            struct sockaddr_in *ipaddr = (struct sockaddr_in*)&ifr.ifr_addr;
            strncpy(interfaces[count].ip, inet_ntoa(ipaddr->sin_addr), INET_ADDRSTRLEN);

            ioctl(sockfd, SIOCGIFHWADDR, &ifr);
            char buffer[MAX_BUFFER_SIZE];
            snprintf(buffer, MAX_BUFFER_SIZE, "%02x:%02x:%02x:%02x:%02x:%02x",
                     (unsigned char) ifr.ifr_hwaddr.sa_data[0], 
                     (unsigned char) ifr.ifr_hwaddr.sa_data[1],
                     (unsigned char) ifr.ifr_hwaddr.sa_data[2], 
                     (unsigned char) ifr.ifr_hwaddr.sa_data[3],
                     (unsigned char) ifr.ifr_hwaddr.sa_data[4], 
                     (unsigned char) ifr.ifr_hwaddr.sa_data[5]);
                     
            strncpy(interfaces[count].mac, buffer, 18);
            count++;
        }

        ifr.ifr_name[0]++;
    }

    num_interfaces = count;
}

void print_interfaces() {
    int i;
    for (i = 0; i < num_interfaces; i++) {
        printf("%d. Name: %s, IP: %s, MAC: %s\n",
               interfaces[i].index, interfaces[i].name, interfaces[i].ip, interfaces[i].mac);
    }
}

int main() {
    get_interfaces();
    print_interfaces();
    return 0;
}