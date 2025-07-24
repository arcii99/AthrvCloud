//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: excited
#include<stdio.h>
#include<pcap.h>

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    //Printing packet length
    printf("Packet size: %d bytes\n", header->len);
    
    //Printing Hexadecimal and ASCII packet data
    for(int i=0; i < header->len; i++)
    {
        printf("%.2x ", buffer[i]);
        if((i%16 == 0 && i!=0) || i==header->len-1)
            printf("\n");

    }
    printf("\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    //Getting network and mask
    pcap_lookupnet("wlo1", &net, &mask, errbuf);

    //Opening device for capturing packets
    handle = pcap_open_live("wlo1", BUFSIZ, 1, 1000, errbuf);

    //Compiling filter expression
    pcap_compile(handle, &fp, "tcp", 0, net);

    //Setting filter
    pcap_setfilter(handle, &fp);

    //capturing packets 
    pcap_loop(handle, -1, processPacket, NULL);

    return 0;
}