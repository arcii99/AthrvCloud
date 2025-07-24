//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(unsigned char *userData, const struct pcap_pkthdr* pkthdr, const unsigned char* packet)
{
     // Get the size of the packet
    int packetSize = pkthdr->len;

    // Print the packet size and timestamp
    printf("Packet size: %d bytes\n", packetSize);
    printf("Timestamp: %s\n", ctime((const time_t*)&pkthdr->ts.tv_sec));

    // Loop through the packet contents and print them
    for(int i=0; i<packetSize; i++) {
        printf("%.2x ", packet[i]);
        if( (i+1) % 16 == 0 ) {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Find the first active device that can sniff traffic
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        fprintf(stderr, "Error finding device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Get the network address and mask for the device
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting network address and mask for device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Open the device for sniffing with a 1 second timeout
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply the filter "tcp", printing only TCP packets
    if(pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error applying filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Start capturing packets indefinitely
    pcap_loop(handle, -1, packetHandler, NULL);

    // Close the device handle and free memory
    pcap_close(handle);
    pcap_freecode(&fp);

    return EXIT_SUCCESS;
}