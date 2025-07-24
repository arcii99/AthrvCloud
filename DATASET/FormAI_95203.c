//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <pcap.h>

// Define the callback function to process packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    pcap_t *handle;        // Session handle
    char *dev;             // The device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];  // Error string
    struct bpf_program fp; // The compiled filter expression
    char filter_exp[] = "port 80";  // Filter expression
    bpf_u_int32 mask;      // Our netmask
    bpf_u_int32 net;       // Our IP

    // Find a device to sniff on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return(1);
    }
    printf("Device: %s\n", dev);

    // Get the network number and mask associated with the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        return(1);
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the session
    pcap_close(handle);
    return(0);
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured!\n");

    // Print out the packet length
    printf("Packet length: %d\n", header->len);

    // Print out the raw packet data
    for (int i=0; i<header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n");
}