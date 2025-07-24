//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: immersive
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    int i = 0;
    printf("Packet %d:\n", ++(*((int*)userData)));
    printf("     Length: %d\n", pkthdr->len);
    printf("     Data:");
    for(i=0; i<pkthdr->caplen; i++)
    {
        if(i%16 == 0)
        {
            printf("\n     ");
        }
        printf(" %02x", packet[i]);
    }
    printf("\n");
    return;
}

int main(int argc, char **argv)
{
    char *device, *filterExpression;
    pcap_t *handle;
    struct bpf_program filter;
    bpf_u_int32 subnetMask, ip;
    int count = 0;

    if(argc < 2)
    {
        printf("Usage: %s <interface> [filter]\n", argv[0]);
        exit(1);
    }

    device = argv[1];
    filterExpression = (argc == 3) ? argv[2] : "";

    if(pcap_lookupnet(device, &ip, &subnetMask, NULL) == -1)
    {
        printf("Error: Couldn't get netmask for device %s\n", device);
        ip = 0;
        subnetMask = 0;
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if(handle == NULL)
    {
        printf("Error: Couldn't open device %s\n", device);
        exit(2);
    }

    if(pcap_compile(handle, &filter, filterExpression, 0, ip) == -1)
    {
        printf("Error: Couldn't parse filter %s: %s\n", filterExpression, pcap_geterr(handle));
        exit(3);
    }

    if(pcap_setfilter(handle, &filter) == -1)
    {
        printf("Error: Couldn't install filter %s: %s\n", filterExpression, pcap_geterr(handle));
        exit(4);
    }

    pcap_loop(handle, -1, packetHandler, (u_char*)&count);

    pcap_freecode(&filter);
    pcap_close(handle);

    printf("Done\n");
    return 0;
}