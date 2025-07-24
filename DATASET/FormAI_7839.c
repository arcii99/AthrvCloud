//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cyberpunk
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    // Your code to handle captured packets goes here
}

int main()
{
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *packetDescriptor = pcap_open_live("eth0", 65536, 1, 0, errorBuffer);

    if (packetDescriptor == NULL)
    {
        printf("Error: %s\n", errorBuffer);
        return 1;
    }

    int captureLimit = 100000;
    pcap_loop(packetDescriptor, captureLimit, packetHandler, NULL);

    printf("Packet capture complete.\n");
    pcap_close(packetDescriptor);

    return 0;
}