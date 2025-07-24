//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: random
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netdb.h> 
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
  
int main(int argc, char *argv[]) 
{ 
    int fd;
    struct ifreq ifr;
    char* interface = "wlan0"; // Change this to your wireless interface name
    int result = 0;
    struct ifaddrs *ifap_head, *ifapItr; 
    struct sockaddr_in *sa;
    char *address;


    // create socket for ioctl
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("Can't get control socket");
        exit(1);
    }

    // get IP address of the interface
    strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);
    if (ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
        perror("Can't get IP address");
        exit(1);
    }

    // display IP address of the interface
    sa = (struct sockaddr_in *)&ifr.ifr_addr;
    address = inet_ntoa(sa->sin_addr);
    printf("\n***********************************************************\n");
    printf("\nWireless Network Scanner\n");
    printf("Interface: %s", interface);
    printf("\nInterface IP address: %s\n", address);
    printf("\n***********************************************************\n");

    // get list of interfaces
    if (getifaddrs(&ifap_head) != 0) {
        printf("\nError in getifaddrs: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // loop through interfaces
    for (ifapItr = ifap_head; ifapItr != NULL; ifapItr = ifapItr->ifa_next) {
        // check if interface is valid and is wireless
        if ((ifapItr->ifa_addr == NULL) || (ifapItr->ifa_flags & IFF_LOOPBACK))
            continue;
        if (ifapItr->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *saaddr = (struct sockaddr_in *)ifapItr->ifa_addr;
            if(strstr(ifapItr->ifa_name, "wlan") != NULL) {

                in_addr_t ipAddr = ((struct sockaddr_in *)ifapItr->ifa_addr)->sin_addr.s_addr;
                in_addr_t mask = ((struct sockaddr_in *)ifapItr->ifa_netmask)->sin_addr.s_addr;
                in_addr_t network = ipAddr & mask;
                printf("\nInterface: %s", ifapItr->ifa_name);
                printf("\nIP address: %s", inet_ntoa(*(struct in_addr *)&ipAddr));
                printf("\nNetmask address: %s", inet_ntoa(*(struct in_addr *)&mask));
                printf("\nNetwork address: %s", inet_ntoa(*(struct in_addr *)&network));
                printf("\n-----------------------------------------------------------\n");
            }
        }
    }

    // free memory
    freeifaddrs(ifap_head);

    return 0; 
}