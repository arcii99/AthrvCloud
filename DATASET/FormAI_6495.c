//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, 
                    const u_char *packet)
{
    // Do something with the packet
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    int num_packets = 10;

    // Open network device for live capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return(1);
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, 
               pcap_geterr(handle));
        return(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't apply filter %s: %s\n", filter_exp, 
               pcap_geterr(handle));
        return(1);
    }

    // Start capturing packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Done\n");
    return(0);
}