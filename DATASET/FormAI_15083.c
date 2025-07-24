//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pcap.h>
#include<netinet/in.h>
#include<netinet/if_ether.h>
#include<arpa/inet.h>

#define MAXBYTES2CAPTURE 2048

void ProcessPacket(u_char *, const struct pcap_pkthdr *, const u_char *);

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    int i;
    bpf_u_int32 netmask;
    bpf_u_int32 ipaddress;
    pcap_t* descr;
    const unsigned char *packet;
    struct pcap_pkthdr hdr;
    struct ether_header *eptr;
    struct bpf_program fp;
    char *dev, *net, *mask;

    dev=pcap_lookupdev(errbuf);
    if(dev == NULL)
    {
        printf("%s\n",errbuf);
        exit(1);
    }
    printf("Device Found: %s\n",dev);

    if(pcap_lookupnet(dev,&net,&mask,errbuf)==-1)
    {
        printf("%s\n",errbuf);
        exit(1);
    }
    ipaddress=inet_addr(net);
    netmask=inet_addr(mask);
    descr = pcap_open_live(dev,MAXBYTES2CAPTURE,1,1000,errbuf);
    if(descr == NULL)
    {
        printf("pcap_open_live(): %s\n",errbuf);
        exit(1);
    }

    if(pcap_compile(descr,&fp,"arp",0,ipaddress)==-1)
    {
        printf("Error calling pcap_compile\n");
        exit(1);
    }

    if(pcap_setfilter(descr,&fp)==-1)
    {
        printf("Error setting filter\n");
        exit(1);
    }

    pcap_loop(descr,10,(void *)ProcessPacket,NULL);
    return 0;
}

void ProcessPacket(u_char *args, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    static int count = 1;
    struct ether_header *eptr; 

    printf("Packet %d:\n", count);

    eptr = (struct ether_header *) packet;

    printf("Ethernet Type: %hu\n", ntohs(eptr->ether_type));

    switch(ntohs(eptr->ether_type))
    {
        case ETHERTYPE_IP:
            printf("IP packet\n");
            break;
        case ETHERTYPE_ARP:
            printf("ARP packet\n");
            break;
        case ETHERTYPE_REVARP:
            printf("RARP packet\n");
            break;
        default:
            printf("Unknown packet type\n");
            break;
    }

    count++;
}