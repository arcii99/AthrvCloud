//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <pcap.h>

void get_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char const *argv[]) {
    char *device_name = NULL;
    char err_buf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout_limit = 10000; // in milliseconds
    
    // Get the device name
    device_name = pcap_lookupdev(err_buf);
    if (device_name == NULL) {
        printf("Error finding device: %s\n", err_buf);
        return 1;
    }
    printf("Device name: %s\n", device_name);
    
    // Open the device for listening
    handle = pcap_open_live(device_name, BUFSIZ, 1, timeout_limit, err_buf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", err_buf);
        return 1;
    }
    
    // Loop through incoming packets
    pcap_loop(handle, 0, get_packet, NULL);
    
    // Close the device when done
    pcap_close(handle);
    
    return 0;
}

void get_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet length
    printf("Packet length: %d\n", header->len);
    
    // Print packet data
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n");
}