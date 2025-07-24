//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    // Get the interface name from command line argument
    char *interface = argv[1];

    // Open the network interface for packet capture
    if ((handle = pcap_open_live(interface, 65535, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "Error opening network interface\n");
        return 1;
    }

    // Compile and apply packet filter
    if (pcap_lookupnet(interface, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error looking up interface details\n");
        return 1;
    }
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1) {
        fprintf(stderr, "Error compiling filter\n");
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error applying filter\n");
        return 1;
    }

    // Start capturing packets in a recursive fashion
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the network interface handle
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    static int count = 1;
    printf("Packet #%d\n", count++);
    // Print packet header information
    printf("Timestamp: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("Packet length: %d\n", header->len);
    printf("Capture length: %d\n", header->caplen);
    // Print packet data in hexadecimal and ASCII format
    for (int i = 0; i < header->caplen; i++) {
        printf("%02x ", pkt_data[i]);
        if ((i + 1) % 16 == 0) {
            printf(" ");
            for (int j = i - 15; j <= i; j++) {
                if (pkt_data[j] >= ' ' && pkt_data[j] <= '~') {
                    putchar(pkt_data[j]);
                } else {
                    putchar('.');
                }
            }
            putchar('\n');
        }
    }
    putchar('\n');
    // Continue capturing packets recursively
    pcap_loop((pcap_t *)param, -1, packet_handler, param);
}