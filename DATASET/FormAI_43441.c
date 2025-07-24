//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: calm
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet);

int main(int argc, char* argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp and port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Open live capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    // Get network address and mask
    pcap_lookupnet("eth0", &net, &mask, errbuf);

    // Compile the filter expression
    pcap_compile(handle, &fp, filter_exp, 0, net);

    // Apply the compiled filter
    pcap_setfilter(handle, &fp);

    // Start packet capture loop
    printf("Starting packet capture...\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Done.\n");

    return 0;
}

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet)
{
    static int count = 1;

    // Print timestamp and length of packet
    printf("%d: %ld.%06ld (%ld bytes)\n", count, header->ts.tv_sec, header->ts.tv_usec, header->len);

    // Print packet data
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n\n");

    count++;
}