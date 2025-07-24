//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <pcap.h>

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        printf("Could not create handle: %s\n", errbuf);
        return 1;
    }

    struct pcap_pkthdr header;
    const u_char *packet;
    int count = 0;
    while(count < 10)
    {
        packet = pcap_next(handle, &header);
        if(packet != NULL)
        {
            printf("Captured packet %d:\n", ++count);
            printf("Length: %d bytes\n", header.len);
            printf("Content:\n");
            for(int i = 0; i < header.len; i++)
            {
                printf("%02x ", packet[i]);
                if((i + 1) % 16 == 0) printf("\n");
            }
            printf("\n\n");
        }
    }

    pcap_close(handle);

    return 0;
}