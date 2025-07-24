//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: imaginative
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    if (argc != 2) {
        printf("Usage: %s [device]\n", argv[0]);
        return 1;
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        return 2;
    }

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured at %ld.%ld:\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Packet length: %ld\n", header->len);
    printf("Packet data:\n");

    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n");
}