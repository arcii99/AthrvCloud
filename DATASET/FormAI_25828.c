//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: invasive
#include <pcap.h>
#include <stdio.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device: %s\n", errbuf);
        return 1;
    }
    printf("Packet capturing has started.\n");

    pcap_loop(handle, 0, process_packet, NULL);

    pcap_close(handle);
    printf("\nFinished capturing packets.\n");

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 0;
    printf("\nPacket #%d\n\n", ++count);
    printf("Packet size: %d bytes\n", header->len);
    printf("Capture time: %s", ctime((const time_t*)&header->ts.tv_sec));
    printf("Source MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
    printf("Destination MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);

    // You can continue to parse the packet information to extract other details such as IP addresses, protocols, payload, etc.
}