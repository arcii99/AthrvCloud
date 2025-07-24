//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: peaceful
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packetData) {
    printf("[Intrusion Detected] Packet captured!\n");
    // Print packet information
    printf("Packet Length: %d\n", pkthdr->len);
    printf("Number of Header Bytes: %d\n", pkthdr->caplen);
    
    // Print packet payload (up to 20 bytes)
    int payloadLength = 20;
    if (pkthdr->caplen < payloadLength) payloadLength = pkthdr->caplen;
    printf("Payload: ");
    for (int i = 0; i < payloadLength; i++) {
        printf("%02x ", packetData[i]);
    }
    printf("\n\n");
}

int main() {
    char errorBuffer[PCAP_ERRBUF_SIZE];
    // Select network device
    char *device = pcap_lookupdev(errorBuffer);
    if (device == NULL) {
        printf("[Error] Could not find default device: %s\n", errorBuffer);
        return -1;
    }
    printf("Network Device: %s\n", device);
    
    // Open network device for packet capture
    pcap_t *handle = pcap_open_live(device, 65536, 1, 0, errorBuffer);
    if (handle == NULL) {
        printf("[Error] Could not open network device for packet capture: %s\n", errorBuffer);
        return -1;
    }
    printf("Network device opened for packet capture.\n");
    
    // Set packet filter (only capture ICMP packets with destination IP 192.168.1.1)
    struct bpf_program filter;
    char filterExpression[] = "icmp and dst host 192.168.1.1";
    if (pcap_compile(handle, &filter, filterExpression, 0, 0) == -1) {
        printf("[Error] Could not parse filter expression: %s\n", pcap_geterr(handle));
        return -1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("[Error] Could not apply filter: %s\n", pcap_geterr(handle));
        return -1;
    }
    
    // Start packet capture loop
    printf("Packet capture started.\n");
    pcap_loop(handle, -1, packetHandler, NULL);
    
    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}