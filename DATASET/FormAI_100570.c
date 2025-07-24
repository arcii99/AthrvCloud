//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: optimized
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured with length of %d bytes\n", header->len);
}

int main() {
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_expression[] = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;

    // Step 1: Open device for sniffing
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live Failed: %s\n", error_buffer);
        return 1;
    }

    // Step 2: Compile filter expression
    if (pcap_compile(handle, &filter, filter_expression, 0, ip) == -1) {
        fprintf(stderr, "pcap_compile Failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Step 3: Set filter
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "pcap_setfilter Failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Step 4: Start capturing
    pcap_loop(handle, 0, packet_handler, NULL);

    // Step 5: Close handle
    pcap_close(handle);

    return 0;
}