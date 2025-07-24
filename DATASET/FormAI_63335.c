//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(unsigned char *userData,
                   const struct pcap_pkthdr* pkthdr,
                   const unsigned char* packet)
{
    // process packet here
}

int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;     
    char filter_exp[] = "port 80";    
    bpf_u_int32 net;

    // find a suitable network interface
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Error finding network interface: %s\n", errbuf);
        return 1;
    }

    // open the device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
        return 1;
    }

    // compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // begin capturing packets
    printf("Packet capture initialized on interface: %s\n", dev);
    pcap_loop(handle, -1, packetHandler, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}