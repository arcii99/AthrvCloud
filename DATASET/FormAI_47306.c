//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // Do something with the captured packet here
    
    return;
}

int main(int argc, char *argv[])
{
    pcap_t *handle;             // The pointer to the pcap session
    char *dev;                  // The device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];   // Error string for pcap functions
    struct bpf_program fp;      // The compiled filter
    char filter_exp[] = "port 80";   // The filter expression
    bpf_u_int32 mask;           // Our subnet mask
    bpf_u_int32 net;            // Our IP address
    int num_packets = 10;       // Number of packets to capture

    // Check for command line arguments
    if (argc > 1) {
        dev = argv[1];
    }
    else {
        // If none specified, use the default device
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            return(2);
        }
    }

    // Find the properties for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the session for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Loop to capture packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Close the session
    pcap_close(handle);

    return(0);
}