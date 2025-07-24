//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock;
    struct ifreq ifr;
    
    sock = socket(AF_INET, SOCK_DGRAM, 0); // create socket for datagram protocol
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    printf("Wireless Network Scanner\n");
    
    // loop through all possible network interfaces to get their information
    for (char c = 'a'; c <= 'z'; c++) {
        char iface[10] = "wlan";
        iface[4] = c; // set the interface number
        
        memset(&ifr, 0, sizeof(ifr)); // clear ifr struct
        
        // copy interface name to ifr struct
        strncpy(ifr.ifr_name, iface, sizeof(ifr.ifr_name)-1);
        
        // get interface flags
        if (ioctl(sock, SIOCGIFFLAGS, &ifr) < 0) {
            continue; // skip to next iteration if interface is invalid
        }
        
        // check if interface is UP and RUNNING
        if ((ifr.ifr_flags & IFF_UP) && (ifr.ifr_flags & IFF_RUNNING)) {
            // get interface IP address
            if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
                perror("Error getting IP address");
                return 1; // return error
            }
            
            struct sockaddr_in *ipaddr = (struct sockaddr_in *)&ifr.ifr_addr;
            char *ip = inet_ntoa(ipaddr->sin_addr); // convert IP address to string format
            
            printf("Interface %s is UP and RUNNING with IP address %s\n", iface, ip);
        }
    }
    
    close(sock); // close socket
    
    return 0; // exit program
}