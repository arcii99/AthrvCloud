//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: romantic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
 
/* Callback function to process packets */
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    int size = header->len;
     
    printf("\n\nNew Packet Captured\n");
     
    /* Process the packet */
    // TO DO: add your code for packet processing here
     
}
 
/* Main function to capture network packets */
int main(int argc, char **argv) {
    char *dev = argv[1]; // Device to sniff on
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp; // Compiled filter expression
    bpf_u_int32 mask; // Netmask
    bpf_u_int32 net; // IP address of the device
     
    /* Get the network device to sniff on */
    if (dev == NULL) {
        fprintf(stderr, "Error: No device specified\n");
        exit(EXIT_FAILURE);
    }
     
    /* Open the device for sniffing */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }
     
    /* Get the network address and mask for the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
     
    /* Compile and apply the filter expression */
    if (pcap_compile(handle, &fp, "port 80", 0, net) == -1) {
        fprintf(stderr, "Error: Couldn't parse filter %s: %s\n", "port 80", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: Couldn't install filter %s: %s\n", "port 80", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
     
    printf("Listening on device %s...\n", dev);
     
    /* Start capturing packets */
    pcap_loop(handle, -1, process_packet, NULL);
     
    /* Clean up */
    pcap_freecode(&fp);
    pcap_close(handle);
     
    return 0;
}