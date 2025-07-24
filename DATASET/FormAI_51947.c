//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: imaginative
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE]; // Holds error messages;

    printf("[+] Starting packet capture on device: %s\n", dev);

    pcap_t *handle = pcap_open_live(dev, 65535, 1, 0, errbuf); // Live packet capture handle
    if (!handle) {
        printf("[-] Error opening device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Filter for HTTP requests
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("[-] Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("[-] Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    printf("[+] Filter set to: %s\n", filter_exp);


    // Catch packets for 30 seconds
    pcap_loop(handle, 30, packet_handler, NULL);

    // Close the handle to release resources
    pcap_close(handle);
    printf("[+] Packet capture complete.\n");
    return 0;
}

/**
 * Function to handle each captured packet
 */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("[+] Got a packet!\n");
    printf("[+] Packet length: %d\n", header->len);
    
    // Parse packet data here
}