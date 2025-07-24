//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 16

struct interfaceInfo {
    char name[IFNAMSIZ];
    struct sockaddr_in address;
    struct sockaddr_in broadcast;
    struct sockaddr_in subnetMask;
};

int main(int argc, char *argv[]) {
    int fd, interfaceCount, i, j;
    struct ifconf ifc;
    struct ifreq ifr[MAX_INTERFACES];
    struct interfaceInfo interfaces[MAX_INTERFACES];
    struct sockaddr_in *address;
    char buffer[4096], *ptr;
    
    // Create socket
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }
    
    // Get list of interfaces
    ifc.ifc_len = sizeof(buffer);
    ifc.ifc_buf = buffer;
    if (ioctl(fd, SIOCGIFCONF, &ifc) < 0)
    {
        perror("ioctl");
        exit(1);
    }
    
    // Iterate through list of interfaces
    interfaceCount = ifc.ifc_len / sizeof(struct ifreq);
    for (i = 0; i < interfaceCount; i++)
    {
        strncpy(ifr[i].ifr_name, ifc.ifc_req[i].ifr_name, IFNAMSIZ - 1);
        ifr[i].ifr_name[IFNAMSIZ - 1] = '\0';
        
        // Get interface flags
        if (ioctl(fd, SIOCGIFFLAGS, &ifr[i]) < 0)
        {
            perror("ioctl");
            exit(1);
        }
        
        // Filter out interfaces that are not up or loopback
        if ((ifr[i].ifr_flags & IFF_UP) && 
            !(ifr[i].ifr_flags & IFF_LOOPBACK))
        {
            // Get interface address
            if (ioctl(fd, SIOCGIFADDR, &ifr[i]) < 0)
            {
                perror("ioctl");
                exit(1);
            }
            
            address = (struct sockaddr_in*)&ifr[i].ifr_addr;
            strncpy(interfaces[j].name, ifr[i].ifr_name, IFNAMSIZ - 1);
            interfaces[j].name[IFNAMSIZ - 1] = '\0';
            memcpy(&interfaces[j].address, address, sizeof(struct sockaddr_in));
            
            // Get interface broadcast address
            if (ioctl(fd, SIOCGIFBRDADDR, &ifr[i]) < 0)
            {
                perror("ioctl");
                exit(1);
            }
            
            address = (struct sockaddr_in*)&ifr[i].ifr_broadaddr;
            memcpy(&interfaces[j].broadcast, address, sizeof(struct sockaddr_in));
            
            // Get interface subnet mask
            if (ioctl(fd, SIOCGIFNETMASK, &ifr[i]) < 0)
            {
                perror("ioctl");
                exit(1);
            }
            
            address = (struct sockaddr_in*)&ifr[i].ifr_netmask;
            memcpy(&interfaces[j].subnetMask, address, sizeof(struct sockaddr_in));
            
            j++;
        }
    }
    
    // Print list of interfaces
    printf("Wireless Network Scanner Results:\n");
    printf("-----------------------------------------------------\n");
    for (i = 0; i < j; i++)
    {
        printf("%d. %s\n", i+1, interfaces[i].name);
        printf("IP Address: %s\n", inet_ntoa(interfaces[i].address.sin_addr));
        printf("Broadcast Address: %s\n", inet_ntoa(interfaces[i].broadcast.sin_addr));
        printf("Subnet Mask: %s\n", inet_ntoa(interfaces[i].subnetMask.sin_addr));
        printf("\n");
    }
    
    close(fd);
    return 0;
}