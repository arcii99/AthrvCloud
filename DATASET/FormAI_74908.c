//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ada Lovelace
#include <stdio.h>
#include <pcap.h>

void my_packet_handler(
    u_char *args,
    const struct pcap_pkthdr *pkt_header,
    const u_char *packet
)
{
    // print packet length
    printf("Packet captured with length: %d\n", pkt_header->len);
    // use packet data here
}

int main(int argc, char *argv[])
{
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 10;
    int timeout_limit = 10000; // in milliseconds
    bpf_u_int32 net, mask;

    // use default network interface if none is specified
    if (argc == 1) {
        device = pcap_lookupdev(error_buffer);
        if (device == NULL) {
            printf("Error finding default network device: %s\n", error_buffer);
            return 1;
        }
    }
    // use specified network interface
    else {
        device = argv[1];
    }

    // fetch network and subnet mask information
    if (pcap_lookupnet(device, &net, &mask, error_buffer) == -1) {
        printf("Error getting network and mask information for %s: %s\n", device, error_buffer);
        net = 0;
        mask = 0;
    }

    // open network interface for capturing packets
    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    if (handle == NULL) {
        printf("Error opening interface %s for packet capturing: %s\n", device, error_buffer);
        return 1;
    }

    // loop over packets and print them
    pcap_loop(handle, packet_count_limit, my_packet_handler, NULL);

    // close network interface
    pcap_close(handle);

    return 0;
}