//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    // Do some exciting stuff here!
    printf("Captured a packet of length %d\n", pkthdr->len);
}

int main(int argc, char** argv)
{
    char* device = "";
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    int timeoutLimit = 1000; // in milliseconds
    int packetCountLimit = -1; // unlimited

    // Find a suitable network device to capture packets from
    device = pcap_lookupdev(errorBuffer);
    if (device == NULL)
    {
        printf("Error finding network device: %s\n", errorBuffer);
        return 1;
    }

    // Open the network device for data capture
    handle = pcap_open_live(device, 65535, 1, timeoutLimit, errorBuffer);
    if (handle == NULL)
    {
        printf("Error opening network device: %s\n", errorBuffer);
        return 1;
    }

    // Start capturing packets and pass them to our exciting packet handler
    int packetCount = pcap_dispatch(handle, packetCountLimit, packetHandler, NULL);
    if (packetCount == -1)
    {
        printf("Error capturing packets: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Clean up and exit
    pcap_close(handle);
    printf("Captured %d packets successfully!\n", packetCount);
    return 0;
}