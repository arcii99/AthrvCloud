//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: relaxed
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Packet Captured\n");
}

int main() 
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *descr;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 mask = 0;
    bpf_u_int32 net = 0;

    // Get the default network interface
    char* dev = pcap_lookupdev(errbuf);
    if(dev == NULL) 
    {
        printf("pcap_lookupdev() failed: %s\n", errbuf);
        return 1;
    }

    // Get the network address and mask of the default network interface
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) 
    {
        printf("pcap_lookupnet() failed: %s\n", errbuf);
        return 1;
    }

    // Open the network interface
    descr = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);
    if(descr == NULL) 
    {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(descr, &fp, filter_exp, 0, net) == -1) 
    {
        printf("pcap_compile() failed: %s\n", pcap_geterr(descr));
        return 1;
    }

    // Set the filter for the network interface
    if (pcap_setfilter(descr, &fp) == -1) 
    {
        printf("pcap_setfilter() failed: %s\n", pcap_geterr(descr));
        return 1;
    }

    // Capture packets
    if(pcap_loop(descr, -1, packetHandler, NULL) < 0)
    {
        printf("pcap_loop() failed: %s\n", pcap_geterr(descr));
        return 1;
    }

    // Close the network interface
    pcap_close(descr);

    return 0;
}