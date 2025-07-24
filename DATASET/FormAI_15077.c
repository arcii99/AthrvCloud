//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData);

int main()
{
    pcap_t *pcapHandle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the pcap file for reading
    pcapHandle = pcap_open_offline("example.pcap", errbuf);

    if (pcapHandle == NULL)
    {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Loop through the packets in the file
    if (pcap_loop(pcapHandle, 0, packetHandler, NULL) < 0)
    {
        printf("Error: pcap_loop failed\n");
        return 2;
    }

    // Clean up
    pcap_close(pcapHandle);

    return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData)
{
    int i, j;
    printf("Packet length: %d\n", pkthdr->len);
    printf("Number of bytes: %d\n", pkthdr->caplen);
    printf("Packet timestamp: %s\n", ctime((const time_t*)&pkthdr->ts.tv_sec));

    // Print the packet in hex
    for (i=0; i < pkthdr->caplen; i++)
    {
        printf("%02X ", packetData[i]);
        if ((i+1) % 16 == 0)
            printf("\n");
    }
    printf("\n");

    return;
}