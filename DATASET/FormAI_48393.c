//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Sherlock Holmes
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet Captured\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    char dev[] = "eth0";
    
    // Find the properties for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }
    
    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }
    
    // Compile and apply the filter
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // Loop through the packets and call the packet handler function
    pcap_loop(handle, -1, packet_handler, NULL);
    
    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    
    printf("Program complete.\n");
    return 0;
}