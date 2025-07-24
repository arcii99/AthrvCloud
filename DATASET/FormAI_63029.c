//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *device = NULL;          
    char error_buffer[PCAP_ERRBUF_SIZE];  
    pcap_t *handle;              
    
    device = pcap_lookupdev(error_buffer); 

    if (device == NULL) {
        printf("Failed to find default device: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    printf("Device: %s\n", device);

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);

    if (handle == NULL) {
        printf("Failed to open device %s: %s\n", device, error_buffer);
        return EXIT_FAILURE;
    }

    if (pcap_loop(handle, -1, packet_handler, NULL) != 0) {
        printf("pcap_loop failed: %s\n", pcap_geterr(handle));
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet Captured!\n");

    int i;

    for (i = 0; i < header->len; ++i) {
        printf("%02x ", packet[i]);

        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}