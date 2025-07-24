//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* A genius-style C packet capturer using the pcap library */
/* This program captures and displays Ethernet packets */

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv) {

    char *dev; /* The device to sniff on */
    char errbuf[PCAP_ERRBUF_SIZE]; /* Error message buffer */
    pcap_t *handle; /* Session handle */
    bpf_u_int32 net; /* IP address of the device */
    bpf_u_int32 mask; /* Netmask of the device */

    /* Find a capture device if none is specified */
    if(argc < 2) {
        dev = pcap_lookupdev(errbuf);
        if(dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            return(1);
        }
    }
    else {
        dev = argv[1];
    }

    /* Get IP address and netmask associated with capture device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open capture device */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(1);
    }

    /* Launch packet capture loop */
    pcap_loop(handle, -1, packetHandler, NULL);

    /* Close the handle */
    pcap_close(handle);

    return 0;
}

/* Callback function invoked by libpcap for every incoming packet */
void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int numPackets = 0;

    /* Display packet information */
    printf("Packet #%d:\n", ++numPackets);
    printf("   Timestamp:      %s", ctime((const time_t *)&pkthdr->ts.tv_sec));
    printf("   Length:         %d bytes\n", pkthdr->len);
    printf("   Capture length: %d bytes\n", pkthdr->caplen);

    /* Display the Ethernet header */
    printf("\nEthernet Header:\n");
    printf("   |-Destination Address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
    printf("   |-Source Address      : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", packet[6], packet[7], packet[8], packet[9], packet[10],packet[11]);
    printf("   |-Protocol            : %u \n",(unsigned short)packet[12]);

    /* Move past the Ethernet header */
    packet += 14;
    int size = pkthdr->len - 14;

    /* Display the packet payload */
    printf("\nPayload:\n");
    for(int i=0; i<size; i++) {
        if(i != 0 && i%16 == 0) {
            printf("         ");
            for(int j=i-16; j<i; j++) {
                if(packet[j] >= 32 && packet[j] <= 128)
                    printf("%c",(unsigned char)packet[j]);
                else printf(".");
            }
            printf("\n");
        }

        if(i%16 == 0) printf("   ");
            printf(" %02X",(unsigned int)packet[i]);

        if(i == size-1) {
            for(int j=0; j<15-i%16; j++)
                printf("   ");

            printf("         ");

            for(int j=i-i%16; j<=i; j++) {
                if(packet[j] >= 32 && packet[j] <= 128)
                    printf("%c",(unsigned char)packet[j]);
                else printf(".");
            }
            printf("\n");
        }
    }

    printf("\n");
}