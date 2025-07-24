//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65536

const char* DEVICE_NAME = "eth0";

void processPacket(u_char*, const struct pcap_pkthdr*, const u_char*);

int main() {
    char errBuffer[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(DEVICE_NAME, MAX_PACKET_SIZE, 1, 0, errBuffer);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errBuffer);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("This program only supports ethernet interfaces.\n");
        return 2;
    }

    if (pcap_loop(handle, -1, processPacket, NULL) < 0) {
        printf("Error while capturing packets: %s\n", pcap_geterr(handle));
        return 3;
    }

    pcap_close(handle);
    return 0;
}

void processPacket(u_char* args, const struct pcap_pkthdr* header, const u_char* buffer) {
    printf("Yay! We just captured a packet!\n");
    // Add your own packet processing logic here
    return;
}