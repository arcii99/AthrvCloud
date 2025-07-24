//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

pcap_t* handle;  // pcap handle

void packet_handler(u_char* user, const struct pcap_pkthdr* header, const u_char* data) 
{
    // print packet information
    printf("Packet captured.\n");

    // hex dump of packet data
    printf("Packet data:\n");
    for(int i = 0; i < header->len; i++) 
    {
        if(i%16 == 0)
            printf("\n");
        printf("%02x ", data[i]);
    }
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    // open capture device for live capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) 
    {
        // error handling
        printf("Couldn't open device: %s\n", errbuf);
        return(1);
    }

    // set filter options
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) 
    {
        // error handling
        printf("Couldn't get netmask for device: %s\n", errbuf);
        net = 0;
        mask = 0;
    }
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) 
    {
        // error handling
        printf("Couldn't compile filter: %s\n", pcap_geterr(handle));
        return(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) 
    {
        // error handling
        printf("Couldn't set filter: %s\n", pcap_geterr(handle));
        return(1);
    }

    // start capturing packets
    printf("Starting packet capture...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    // cleanup
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}