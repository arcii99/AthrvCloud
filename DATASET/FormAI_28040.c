//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

#define DEVICE "wlan0"

void scan_wireless_networks();
void print_wireless_networks();

int main()
{
    scan_wireless_networks();
    print_wireless_networks();
    return 0;
}

void scan_wireless_networks()
{
    struct iwreq wrq;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd == -1)
    {
        perror("socket");
        exit(1);
    }

    strcpy(wrq.ifr_name, DEVICE);

    if(ioctl(sockfd, SIOCGIWSCAN, &wrq) == -1)
    {
        perror("ioctl");
        exit(1);
    }

    close(sockfd);
}

void print_wireless_networks()
{
    FILE *fp;
    char output[1024], buffer[256];
    int i, j;

    fp = popen("iwlist wlan0 scan", "r");

    if(fp == NULL)
    {
        perror("popen");
        exit(1);
    }

    while(fgets(output, sizeof(output), fp))
    {
        if(strstr(output, "ESSID:\"") != NULL)
        {
            memset(buffer, '\0', sizeof(buffer));
            i = strstr(output, "ESSID:\"") - output + 7;
            j = 0;

            while(output[i] != '\"' && j < sizeof(buffer) - 1)
            {
                buffer[j++] = output[i++];
            }

            printf("%s\n", buffer);
        }
    }

    pclose(fp);
}