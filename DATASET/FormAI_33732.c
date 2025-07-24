//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pktHeader, const u_char *packetData)
{
    // Packet counter
    static int count = 1;

    printf("Packet number %d:\n", count);
    printf("Packet size: %d bytes\n", pktHeader->len);

    // Loop through packet payload and print each byte
    for (int i = 0; i < pktHeader->len; i++)
    {
        printf("%.2x ", packetData[i]);
        // Add a new line every 16 bytes
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    printf("\n\n");

    // Increment packet counter
    count++;
}

int main()
{
    // Define error buffer
    char errbuff[PCAP_ERRBUF_SIZE];

    // Get capture device
    pcap_t *handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuff);

    // Ensure handle was opened successfully
    if (handle == NULL)
    {
        printf("Unable to open device: %s\n", errbuff);
        return 1;
    }

    // Capture packets indefinitely
    printf("Capturing packets...\n");
    pcap_loop(handle, -1, packetHandler, NULL);

    // Close the handle
    pcap_close(handle);

    return 0;
}