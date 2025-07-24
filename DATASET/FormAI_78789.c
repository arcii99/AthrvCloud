//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: decentralized
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet Captured\n");

    // Do some processing here...
}

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;          
    char filter_exp[] = "tcp";     
    bpf_u_int32 net;               
    bpf_u_int32 mask;              
    struct pcap_pkthdr header;     
    const u_char *packet;          

    // Open the capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        return(1);
    }

    // Get network and mask information
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting network and mask information: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        return(1);
    }

    // Set the filter on the capture device
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return(1);
    }

    // Loop through the packets
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            packet_handler(NULL, &header, packet);
        }
    }

    // Close the capture device
    pcap_close(handle);

    return(0);
}