//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void pktHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv)
{
    char *device = "eth0"; // Change this to the correct interface for your system
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr = pcap_open_live(device, BUFSIZ, 0, -1, errbuf);

    if(descr == NULL){
        printf("pcap_open_live() failed due to: %s\n", errbuf);
        return 1;
    }

    printf("Successfully opened device %s\n", device);

    if(pcap_datalink(descr) != DLT_EN10MB){
        printf("This program only works on Ethernet networks.\n");
        return 1;
    }

    if(pcap_loop(descr, 0, pktHandler, NULL) < 0){
        printf("pcap_loop() failed due to: %s\n", pcap_geterr(descr));
        return 1;
    }

    return 0;
}

void pktHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 0;
    printf("Packet %d:\n", ++count);

    printf("Packet length: %d\n", pkthdr->len);
    printf("Number of bytes captured: %d\n", pkthdr->caplen);
    printf("Time of packet arrival: %s", ctime((const time_t*)&pkthdr->ts.tv_sec));

    const u_char *ptr = packet;
    for (int i=0; i<pkthdr->caplen; i++){
        printf("%.2x ", *ptr);
        ptr++;
        if (i%16 == 15){
            printf("\n");
        }
    }
    printf("\n");
}