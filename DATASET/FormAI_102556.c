//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: all-encompassing
#include <pcap.h>
#include <stdio.h>

void print_packet_info(const u_char *packet, int packet_size) {
    printf("Packet Size: %d bytes\n", packet_size);
    printf("Packet Contents:\n");
    for (int i = 0; i < packet_size; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet Captured!\n");
    print_packet_info(packet, header->caplen);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the default device for capturing
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Failed to open device: %s\n", errbuf);
        return 1;
    }

    // Compile filter expression
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "icmp", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Failed to compile filter\n");
        return 1;
    }

    // Set filter for capturing
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Failed to set filter\n");
        return 1;
    }

    // Start capturing packets
    printf("Starting packet capture...\n");
    pcap_loop(handle, 0, process_packet, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}