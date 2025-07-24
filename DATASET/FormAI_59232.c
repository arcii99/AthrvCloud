//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>

void packetsHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int *counter = (int *)args;
    printf("\nPacket #%d:\n", ++(*counter));
    printf("Packet length: %d\n", header->len);
    printf("Timestamp: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("Source MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);
    printf("Destination MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
    printf("Source IP address: %s\n", inet_ntoa(*(struct in_addr *)(packet + 26)));
    printf("Destination IP address: %s\n", inet_ntoa(*(struct in_addr *)(packet + 30)));
    printf("Protocol: %d\n", packet[23]);
}


int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Get default network device name
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }
    printf("Using device: %s\n", dev);

    // Get network device properties
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open network device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    // Compile and set the filter expression
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter: %s\n", pcap_geterr(handle));
        return 2;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        return 2;
    }

    int packetCount = 0;

    // Capture packets
    pcap_loop(handle, -1, packetsHandler, (u_char *)&packetCount);

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("\nCapture complete!\n");

    return 0;
}