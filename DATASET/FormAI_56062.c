//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Alan Touring
#include <stdio.h>
#include <pcap.h>

/* Callback function for handling incoming packets */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured with length of %d\n", header->len);
    // Further packet analysis can be implemented here
}

int main(int argc, char **argv)
{
    char *dev = argv[1]; // The network device to capture packets on
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for handling libpcap errors
    pcap_t *handle; // The handle to the captured session
    
    /* Open the network device for capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }
    
    /* Begin packet capture */
    if (pcap_loop(handle, -1, packet_handler, NULL) < 0) {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    /* Close the session */
    pcap_close(handle);
    return 0;
}