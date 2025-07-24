//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData);

int main(int argc, char *argv[]) {
    char *interface = NULL;
    char *pcapFile = NULL;
    pcap_t *pcapHandle = NULL;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    
    if(argc == 2) {
        interface = argv[1];
        pcapHandle = pcap_open_live(interface, BUFSIZ, 1, 0, errorBuffer);
    } else if(argc == 3) {
        pcapFile = argv[1];
        pcapHandle = pcap_open_offline(pcapFile, errorBuffer);
    } else {
        printf("Usage: %s [interface] or %s [pcap_file]\n", argv[0], argv[0]);
        return 1;
    }

    if(pcapHandle == NULL){
        printf("Open error: %s\n", errorBuffer);
        return 1;
    }

    pcap_loop(pcapHandle, -1, packetHandler, NULL);

    return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
    printf("Packet captured.\n");
    /* TODO: packet analysis code goes here */
}