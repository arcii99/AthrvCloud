//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[])
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    handle = pcap_open_live("enp0s3", 65536, 1 , 0, errbuf);
    if (handle == NULL) 
    {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return(1);
    }
    
    pcap_loop(handle , -1 , processPacket , NULL);
    
    return 0;
}

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    int i,len;
    printf("\n\n----------------------\nReceived Packet Size: %d\n", header->len);
    for(i=0; i < header->len; i++)
    {
        printf("%.2X ", packet[i]);
        if( (i+1)%16==0 )printf("\n");
    }
}