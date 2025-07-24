//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>

int main()
{
    int fd;
    struct ifreq ifr;
    char iface[] = "wlan0";
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    /*I am not sorry*/
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, iface, IFNAMSIZ-1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);
    struct in_addr ipaddr = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;
    uint32_t ip = ntohl(ipaddr.s_addr);
    for (uint32_t i = (ip & 0xffffff00); i <= (ip | 0x000000ff); i++) {
        char addr[16];
        snprintf(addr, sizeof(addr), "%d.%d.%d.%d", (i>>24)&0xff, (i>>16)&0xff, (i>>8)&0xff, i&0xff);
        fd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in sin;
        sin.sin_family = AF_INET;
        sin.sin_port = htons(80);
        inet_pton(AF_INET, addr, &sin.sin_addr);
        if (connect(fd, (struct sockaddr *)&sin, sizeof(sin)) == 0) {
            printf("Host found: %s\n", addr);
        }
        close(fd);
    }
    return 0;
}