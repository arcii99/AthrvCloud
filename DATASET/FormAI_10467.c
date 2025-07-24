//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define IFACE_NAME "wlan0"

int main()
{
    int sock, level, optname, retval;
    struct ifreq ifr;
    char *iface = IFACE_NAME;
    
    /* create socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    /* check for errors */
    if (sock < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    /* set interface name */
    strncpy(ifr.ifr_name, iface, IFNAMSIZ);

    /* get signal strength */
    level = -1;
    optname = 0x8B02;
    ifr.ifr_data = (void *) &level;
    retval = ioctl(sock, optname, &ifr);

    /* check for errors */
    if (retval < 0) {
        printf("Error getting signal strength\n");
        return -1;
    }

    /* print signal strength */
    printf("Signal strength: %d dBm\n", level);

    /* close socket */
    close(sock);

    return 0;
}