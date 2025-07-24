//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: medieval
// Ye Olde Network Packet Monitoring Program
// By thy most gracious programmer

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int packet_count = 1;
    printf("\nPacket #%d:\n", packet_count);
    printf("Ye Olde Timestamp: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("Packet Length: %d bytes\n", header->len);
    printf("Ye Olde Packet Contents:\n");
    for (int i = 0; i < header->len; i++)
    {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n");
    packet_count++;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s [interface]\n", argv[0]);
        return 1;
    }

    printf("Thy network packet monitor doth commence!\n");

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        printf("Couldn't open device %s: %s\n", argv[1], errbuf);
        return 1;
    }

    printf("Ye Olde Packet Filter:\n");
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    if (pcap_compile(handle, &fp, filter_exp, 0, 0) == -1)
    {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, -1, got_packet, NULL);

    pcap_close(handle);
    printf("Thy network packet monitor doth conclude!\n");

    return 0;
}