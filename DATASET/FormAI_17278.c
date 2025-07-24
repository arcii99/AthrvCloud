//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <pcap/pcap.h>
#include <stdio.h>

void print_packet_info(u_char *user, const struct pcap_pkthdr *packet_header, const u_char *packet_data) {
    static int packet_number = 1;
    printf("Packet number %d:\n", packet_number);
    printf("    Length: %d bytes\n", packet_header->len);
    printf("    Capture time: %s", ctime((const time_t *)&packet_header->ts.tv_sec));
    ++packet_number;
}

int main(int argc, char **argv) {
    char *device = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 1;
    int timeout_limit = 10000; /* In milliseconds */
    bpf_u_int32 net_mask;
    bpf_u_int32 net_ip;
    struct bpf_program compilation_filter;
    char *filter_string = "ip";
    int result;

    /* Find a device */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }
    printf("Sniffing on device %s ...\n", device);

    /* Find the network address and mask */
    if (pcap_lookupnet(device, &net_ip, &net_mask, error_buffer) == -1) {
        printf("Error finding network address and mask for device %s: %s\n", device, error_buffer);
        return 1;
    }

    /* Open the device for sniffing */
    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    if (handle == NULL) {
        printf("Error opening device for sniffing: %s\n", error_buffer);
        return 1;
    }

    /* Compile the filter */
    result = pcap_compile(handle, &compilation_filter, filter_string, 0, net_mask);
    if (result == -1) {
        printf("Error compiling filter \"%s\": %s\n", filter_string, pcap_geterr(handle));
        return 1;
    }

    /* Set the filter */
    result = pcap_setfilter(handle, &compilation_filter);
    if (result == -1) {
        printf("Error setting filter \"%s\": %s\n", filter_string, pcap_geterr(handle));
        return 1;
    }

    /* Sniff packets */
    pcap_loop(handle, packet_count_limit, print_packet_info, NULL);

    /* Cleanup */
    pcap_freecode(&compilation_filter);
    pcap_close(handle);

    return 0;
}