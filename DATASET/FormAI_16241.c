//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: beginner-friendly
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    int size = header->len;
    printf("Packet captured! size: %d\n", size);
    
    // print packet contents in hex format
    printf("Packet contents: ");
    for(int i=0; i<size; i++)
    {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;

    // get default network interface
    char *dev = pcap_lookupdev(errbuf);
    if(dev == NULL) 
    {
        printf("pcap_lookupdev() failed: %s\n", errbuf);
        return 1;
    }

    // open capture device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    // compile filter expression
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        printf("pcap_compile() failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    // apply filter expression
    if(pcap_setfilter(handle, &fp) == -1)
    {
        printf("pcap_setfilter() failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    // start capturing packets
    pcap_loop(handle, -1, process_packet, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}