//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: futuristic
#include<stdio.h>
#include<pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main()
{
    char errbuff[PCAP_ERRBUF_SIZE];
    pcap_t *handler = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuff);

    if(handler == NULL)
    {
        printf("Error occurred while opening the adapter: %s\n", errbuff);
        return 1;
    }

    printf("Packet capturing has started...\n");

    pcap_loop(handler, 0, packet_handler, NULL);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet Received: %ld\n", header->len);

    // Do something with the packet here

    printf("Packet Handled\n");
}