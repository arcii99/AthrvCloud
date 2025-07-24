//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: ultraprecise
#include <stdio.h>
#include <pcap.h>
#include <arpa/inet.h> 

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    int i=0;
    printf("Packet %d:\n", ++i);    /* Packet counter */
    printf("Packet size: %d bytes\n", header->len); /* Size */
    
    /* Print the packet */
    for (i=0; i<header->len; i++)
    {
        printf("%.2x ", pkt_data[i]);
        if ((i+1)%16==0) printf("\n");
    }
    printf("\n\n");
}

int main(int argc, char **argv)
{
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *descr;
    struct bpf_program fp;     
    bpf_u_int32 maskp;         
    bpf_u_int32 netp;          
    int pcap_status;
    
    /* Define the device to listen for traffic on */
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL)
    {
        printf("%s\n",errbuf);
        return 1;
    }
    
    /* Fetch the network address and mask */
    pcap_status = pcap_lookupnet(dev, &netp, &maskp, errbuf);
    if(pcap_status == -1)
    {    
        printf("%s\n",errbuf);
        return 1;
    }
    
    /* Open the device in promiscuous mode */
    descr = pcap_open_live(dev, BUFSIZ, 1,-1, errbuf);
    if(descr == NULL)
    {
        printf("pcap_open_live(): %s\n",errbuf);
        return 1;
    }
    
    /* Compile the filter */
    if(pcap_compile(descr, &fp, "udp", 0, netp) == -1)
    {
        printf("Error compiling the filter.\n");
        return 1;
    }
    
    /* Set the filter */
    if(pcap_setfilter(descr, &fp) == -1)
    {
        printf("Error setting the filter.\n");
        return 1;
    } 
    
    /* Start the capture */
    pcap_loop(descr, 0, packet_handler, NULL);   
    
    return 0;
}