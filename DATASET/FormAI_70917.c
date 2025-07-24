//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/if_ether.h>
#include<net/if.h>
#include<arpa/inet.h>
#include<errno.h>
#include<unistd.h>
#include<sys/ioctl.h>

#define PACKET_LENGTH 65536

void printPacket(unsigned char *, int);
void getWirelessInterface(char *);
void getIPAddress(char *);
void scanWirelessNetworks(char *, int);
void printSSID(unsigned char *, int);
void printSignalQuality(unsigned char);

int sockDesc;
struct sockaddr_in sin;

int main() {
    int timeout = 10; // in seconds
    char interfaceName[IFNAMSIZ];
    getWirelessInterface(interfaceName);
    getIPAddress(interfaceName);
    scanWirelessNetworks(interfaceName, timeout);
    close(sockDesc);
    return 0;
}

void getWirelessInterface(char *interfaceName) {
    struct ifreq ifr;
    sprintf(ifr.ifr_name, "wlan0");
    sockDesc = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    ioctl(sockDesc, SIOCGIFINDEX, &ifr);
    sprintf(interfaceName, "%s", ifr.ifr_name);
    printf("Wireless interface name: %s\n", interfaceName);
}

void getIPAddress(char *interfaceName) {
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, interfaceName);
    if(ioctl(sockDesc, SIOCGIFADDR, &ifr) == -1) {
        perror("Error getting IP address");
        exit(0);
    }
    printf("IP address: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}

void scanWirelessNetworks(char *interfaceName, int timeout) {
    unsigned char packetBuffer[PACKET_LENGTH];
    int bytesRead;
    fd_set fileDescriptorSet;
    struct timeval timeval;
    timeval.tv_sec = timeout;
    timeval.tv_usec = 0;
    FD_ZERO(&fileDescriptorSet);
    FD_SET(sockDesc, &fileDescriptorSet);
    while(select(sockDesc + 1, &fileDescriptorSet, NULL, NULL, &timeval)) {
        bytesRead = recvfrom(sockDesc, packetBuffer, PACKET_LENGTH, 0, NULL, NULL);
        printPacket(packetBuffer, bytesRead);
    }
}

void printPacket(unsigned char *packetBuffer, int bytesRead) {
    struct ether_header *ethernetHeader;
    struct iphdr *ipHeader;
    unsigned char *payload;
    int ethernetHeaderLength = sizeof(struct ether_header);
    int ipHeaderLength;
    ethernetHeader = (struct ether_header *)packetBuffer;
    if(ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP) {
        ipHeader = (struct iphdr *)(packetBuffer + ethernetHeaderLength);
        ipHeaderLength = ipHeader->ihl * 4;
        payload = packetBuffer + ethernetHeaderLength + ipHeaderLength;
        if(ipHeader->protocol == IPPROTO_UDP && ntohs(ipHeader->tot_len) == bytesRead - ethernetHeaderLength) {
            if(payload[0] == 0x80) {
                printf("---------------------\n");
                printSSID(payload, bytesRead - ethernetHeaderLength - ipHeaderLength);
                printSignalQuality(payload[32]);
                printf("---------------------\n");
            }
        }
    }
}

void printSSID(unsigned char *ssid, int length) {
    int i;
    printf("SSID: ");
    for(i=5; i<length; i++)
        printf("%c", ssid[i]);
    printf("\n");
}

void printSignalQuality(unsigned char signalQuality) {
    printf("Signal Quality: -%d dB\n", (256 - signalQuality));
}