//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<net/if.h>
#include<sys/ioctl.h>

#define MAX_INTERFACES 32
#define MAX_BUFFER 2048

void scanNetwork(char *interfaceName){
    int sockfd,n;
    char buffer[MAX_BUFFER] = {0};
    struct ifreq ifr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    strncpy(ifr.ifr_name, interfaceName, IFNAMSIZ-1);
    if(ioctl(sockfd, SIOCGIFFLAGS, &ifr) == -1){
        printf("Failed to retrieve interface flags\n");
        close(sockfd);
        return;
    }
    if(ifr.ifr_flags & IFF_UP){
        struct sockaddr_in *sin = (struct sockaddr_in *)&ifr.ifr_addr;
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &sin->sin_addr, ip, sizeof(ip));
        printf("Scanning network on interface %s with IP address %s\n", interfaceName, ip);
        int startAddress = inet_addr(ip) & 0xFFFFFF00;
        for(int i=1; i<255; i++){
            char targetAddress[INET_ADDRSTRLEN];
            struct sockaddr_in target;
            snprintf(targetAddress, sizeof(targetAddress), "%d.%d.%d.%d", (startAddress>>24)&0xFF, (startAddress>>16)&0xFF, (startAddress>>8)&0xFF, i);
            target.sin_family = AF_INET;
            target.sin_port = htons(80);
            if(inet_pton(AF_INET, targetAddress, &target.sin_addr)<=0){
                printf("Invalid IP address format %s\n", targetAddress);
                continue;
            }
            if(connect(sockfd, (struct sockaddr *)&target, sizeof(target)) < 0){
                printf("Cannot connect to %s\n", targetAddress);
                continue;
            }
            printf("Connected to %s\n", targetAddress);
            close(sockfd);
            return;
        }
    } else {
        printf("Interface %s is not UP\n", interfaceName);
    }
}

int main(){
    char interfaceName[IFNAMSIZ] = "wlan0";
    scanNetwork(interfaceName);
    return 0;
}