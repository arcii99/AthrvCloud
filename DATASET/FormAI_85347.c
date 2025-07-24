//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pcap.h>

// This function will be called for every captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured with Length [%d]\n", header->len);

    // Use header and packet data here as required
}

int main(int argc, char *argv[])
{
    char *dev = NULL;            // Capture device to use
    char errbuf[PCAP_ERRBUF_SIZE];      // Error buffer
    pcap_t *handle;             // Capture handle

    // Step 1: Find capture device
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL)
    {
        printf("Error finding default capture device: %s\n", errbuf);
        return 1;
    }

    // Step 2: Open capture device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        printf("Error opening %s: %s\n", dev, errbuf);
        return 1;
    }

    // Step 3: Compile filter expression (if any)
    struct bpf_program fp;          // Compiled filter program
    char filter_exp[] = "port 80";  // Filter expression
    bpf_u_int32 net;
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Step 4: Apply filter
    if(pcap_setfilter(handle, &fp) == -1)
    {
        printf("Error applying filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Step 5: Start capture loop
    printf("Starting capture on device %s\n", dev);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Step 6: Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}