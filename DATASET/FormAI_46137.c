//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main(int argc, char const *argv[])
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "udp";
    bpf_u_int32 net, mask;

    // Get default network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }

    // Get network and mask information
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open network device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    // Apply filter expression
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    // Start packet capture loop
    pcap_loop(handle, -1, process_packet, NULL);

    // Close network device
    pcap_close(handle);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    static int count = 0;

    // Print packet header information
    printf("Packet #%d:\n", ++count);
    printf("Timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));
    printf("Packet length: %d\n", header->len);

    // Print packet data in hexadecimal and ASCII
    for (int i = 0; i < header->len; i++)
    {
        printf("%02x ", buffer[i]);
        if ((i + 1) % 16 == 0)
        {
            printf("   ");
            for (int j = i - 15; j <= i; j++)
            {
                if (buffer[j] >= 32 && buffer[j] <= 126)
                {
                    printf("%c", buffer[j]);
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}