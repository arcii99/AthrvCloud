//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: energetic
#include <stdio.h>
#include <pcap.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured!\n");
    // implement code to analyze packet here
}

int main(int argc, char *argv[]) {
    char *device = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout_limit = 10000;  // set timeout to 10 seconds
    
    // lookup and select a network device for packet sniffing
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Unable to find a suitable network device: %s\n", error_buffer);
        return 1;
    }
    printf("Network device selected: %s\n", device);
    
    // open the selected network device for packet sniffing
    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open network device for packet sniffing: %s\n", error_buffer);
        return 2;
    }
    printf("Network device opened successfully!\n");
    
    // start packet sniffing loop
    int num_packets_to_capture = 10;
    pcap_loop(handle, num_packets_to_capture, handle_packet, NULL);
    
    // cleanup
    pcap_close(handle);
    return 0;
}