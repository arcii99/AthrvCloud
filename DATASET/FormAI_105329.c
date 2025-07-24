//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData);

int main(int argc, char *argv[]) {
    char *device;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int snapshotLength = 1024;
    int numPackets = -1;

    if (argc > 1) {
        device=argv[1];
    } else {
        device=pcap_lookupdev(errorBuffer);
        if (device == NULL) {
            fprintf(stderr, "could not find default device: %s\n", errorBuffer);
            return 2;
        }
    }
    printf("capturing on device: %s\n\n", device);

    handle = pcap_open_live(device, snapshotLength, 1, 0, errorBuffer);
    if (handle == NULL) {
        fprintf(stderr, "could not open device %s: %s\n", device, errorBuffer);
        return 2;
    }

    if (pcap_setdirection(handle, PCAP_D_IN) < 0) {
        fprintf(stderr, "could not set capture direction: %s\n", pcap_geterr(handle));
        return 2;
    }

    if (pcap_loop(handle, numPackets, packet_handler, NULL) < 0) {
        fprintf(stderr, "error: %s\n", pcap_geterr(handle));
        return 2;
    }

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
    static int packetCount = 1;

    printf("Packet #%d\n", packetCount);
    printf("Timestamp: %s\n", ctime((const time_t*)&pkthdr->ts.tv_sec));
    printf("Length: %d bytes\n", pkthdr->len);
    printf("Destination MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", packetData[0], packetData[1], packetData[2], packetData[3], packetData[4], packetData[5]);
    printf("Source MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", packetData[6], packetData[7], packetData[8], packetData[9], packetData[10], packetData[11]);
    printf("Type: %x%x\n\n", packetData[12], packetData[13]);

    packetCount++;
}