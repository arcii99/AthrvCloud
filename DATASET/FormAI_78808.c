//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: curious
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;
    printf("Packet #%d:\n", count);
    count++;

    int i = 0, j = 0;
    for(i=0; i<header->len; i++)
    {
        printf("%.2X", packet[i]);
        if((i + 1) % 16 == 0)
        {
            printf("   ");
            for(j=i-15; j<=i; j++)
            {
                if(packet[j] >= 32 && packet[j] <= 128)
                    printf("%c", packet[j]);
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    printf("\n\n");
}

int main()
{
    int packetCount = 0;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the network interface
    pcap_t *handle = pcap_open_live("eth0", 65536, 1, 0, errbuf);

    // listen for packets indefinitely
    pcap_loop(handle, -1, packetHandler, NULL);

    return 0;
}