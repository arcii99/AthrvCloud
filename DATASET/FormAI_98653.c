//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: invasive
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>

/* Define global variables */
pcap_t *handle;         /* The handle for live pcap session */
char *dev;              /* The device to sniff on */
char errbuf[PCAP_ERRBUF_SIZE];  /* Error buffer */
struct bpf_program fp;  /* The compiled filter */
char filter_exp[] = "port 80"; /* The filter expression */
bpf_u_int32 mask;       /* The netmask of our sniffing device */
bpf_u_int32 net;        /* The IP address of our sniffing device */
struct pcap_pkthdr header;    /* The packet header */
const u_char *packet;         /* The actual packet */

/* Declare function prototypes */
void processPacket(u_char *args,const struct pcap_pkthdr* header,const u_char* buffer);

int main(int argc, char *argv[])
{
    /* Get the device to sniff on */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", dev);
    
    /* Get the network address and mask of the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open the session in promiscuous mode */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    /* Start the capture */
    pcap_loop(handle, 0, processPacket, NULL);

    pcap_close(handle);
    return(0);
}

void processPacket(u_char *args,const struct pcap_pkthdr* header,const u_char* buffer)
{
    static int count = 1;

    /* Print packet number */
    printf("Packet number %d:\n", count);
    count++;

    /* Print packet length */
    printf("Packet length: %d\n", header->len);

    /* Print the raw packet data */
    for (int i = 0; i < header->len; i++)
    {
        printf("%02X ", buffer[i]);
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}