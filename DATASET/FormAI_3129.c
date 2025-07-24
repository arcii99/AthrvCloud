//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAXBYTES2CAPTURE 2048 //Maximum number of bytes to capture
#define ETHER_ADDR_LEN	6

struct sniff_ethernet {
    u_char ether_dhost[ETHER_ADDR_LEN]; //Destination host address
    u_char ether_shost[ETHER_ADDR_LEN]; //Source host address
    u_short ether_type; //IP? ARP? RARP? etc
};

void pcap_callback(u_char *arg, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 1; //Packet counter
    printf("\nPacket number %d:\n", count);
    printf("  Length: %d bytes\n", pkthdr->len);
    count++;
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    char *devname;
    pcap_t *devicehandle;
    const u_char *packet;
    struct pcap_pkthdr packetheader;

    /* Find a device to sniff on */
    devname = pcap_lookupdev(errbuf);
    if(devname == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    /* Open the adapter */
    devicehandle = pcap_open_live(devname,MAXBYTES2CAPTURE,1,1000,errbuf);
    if(devicehandle == NULL) {
        printf("Error: could not open device %s\n", devname);
        exit(1);
    }

    /* Begin capture loop */
    printf("\nListening on %s...\n", devname);
    pcap_loop(devicehandle, -1, pcap_callback, NULL);

    /* Close the handle*/
    pcap_close(devicehandle);
    printf("\nCapture complete.\n");

    return 0;
}