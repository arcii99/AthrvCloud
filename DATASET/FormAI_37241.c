//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: shocked
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData);

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);

    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    printf("Packet monitoring has begun. Keep your eyes open, folks!\n");

    pcap_loop(handle, -1, packetHandler, NULL);

    pcap_close(handle);

    return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData)
{
    printf("Received a packet, hold on to your hats!\n");

    // Monitor the packet here...

    printf("Wow, that was a crazy packet! Keep the good times rolling!\n");
}