//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: dynamic
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char* user_args, const struct pcap_pkthdr* cap_header, const u_char* packet) {
    // Here goes the code to handle the captured packets
    printf("Packet captured!\n");
    // Example: print packet length
    printf("Packet length: %d\n", cap_header->len);
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;
    const char *device;
    int ret;

    // Find a network device to capture on
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Error finding network device: %s\n", errbuf);
        return 1;
    }

    // Get network device information
    ret = pcap_lookupnet(device, &net, &mask, errbuf);
    if (ret != 0) {
        fprintf(stderr, "Error getting network device information: %s\n", errbuf);
        return 1;
    }

    // Open network device for capture
    handle = pcap_open_live(device, 65535, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening network device for capture: %s\n", errbuf);
        return 1;
    }

    // Compile filter expression
    ret = pcap_compile(handle, &fp, "tcp port 80", 0, net);
    if (ret != 0) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Set filter for packet capture
    ret = pcap_setfilter(handle, &fp);
    if (ret != 0) {
        fprintf(stderr, "Error setting packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    printf("Packet capture started on device '%s'...\n", device);

    // Capture packets until interrupted
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}