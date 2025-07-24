//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <linux/wireless.h>

int main()
{
    int sock;
    struct iwreq req;
    char ifname[IFNAMSIZ];
    char essid[IW_ESSID_MAX_SIZE];
    int freq, mode, channel, txpower;
    
    /* Open socket */
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    /* Set interface name */
    strcpy(ifname, "wlan0");
    
    /* Get ESSID */
    memset(&req, 0, sizeof(struct iwreq));
    strncpy(req.ifr_name, ifname, IFNAMSIZ);
    req.u.essid.pointer = essid;
    req.u.essid.length = IW_ESSID_MAX_SIZE;
    if (ioctl(sock, SIOCGIWESSID, &req) < 0)
    {
        perror("ioctl[SIOCGIWESSID]");
        exit(EXIT_FAILURE);
    }
    printf("ESSID: %s\n", essid);
    
    /* Get frequency */
    memset(&req, 0, sizeof(struct iwreq));
    strncpy(req.ifr_name, ifname, IFNAMSIZ);
    if (ioctl(sock, SIOCGIWFREQ, &req) < 0)
    {
        perror("ioctl[SIOCGIWFREQ]");
        exit(EXIT_FAILURE);
    }
    freq = req.u.freq.m;
    printf("Frequency: %d\n", freq);
    
    /* Get mode */
    memset(&req, 0, sizeof(struct iwreq));
    strncpy(req.ifr_name, ifname, IFNAMSIZ);
    if (ioctl(sock, SIOCGIWMODE, &req) < 0)
    {
        perror("ioctl[SIOCGIWMODE]");
        exit(EXIT_FAILURE);
    }
    mode = req.u.mode;
    printf("Mode: %d\n", mode);
    
    /* Get channel */
    memset(&req, 0, sizeof(struct iwreq));
    strncpy(req.ifr_name, ifname, IFNAMSIZ);
    if (ioctl(sock, SIOCGIWFREQ, &req) < 0)
    {
        perror("ioctl[SIOCGIWFREQ]");
        exit(EXIT_FAILURE);
    }
    channel = req.u.freq.i;
    printf("Channel: %d\n", channel);
    
    /* Get transmit power */
    memset(&req, 0, sizeof(struct iwreq));
    strncpy(req.ifr_name, ifname, IFNAMSIZ);
    if (ioctl(sock, SIOCGIWTXPOW, &req) < 0)
    {
        perror("ioctl[SIOCGIWTXPOW]");
        exit(EXIT_FAILURE);
    }
    txpower = req.u.txpower.value;
    printf("Transmit power: %d dBm\n", txpower);
    
    /* Close socket */
    close(sock);
    
    return 0;
}