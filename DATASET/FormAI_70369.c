//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: secure
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {

    char errbuf[PCAP_ERRBUF_SIZE]; //Buffer to hold the error message
    char* device = argv[1]; //The network device to capture packets from

    //Open the device for sniffing
    pcap_t *handle = pcap_open_live(device, 1024, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return 1;
    }

    printf("Packet Capturer initialized. Starting to capture packets...\n");

    struct pcap_pkthdr header; //The header that pcap gives us
    const u_char *packet; //The actual packet

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }
        printf("Received %d bytes\n", header.len);
        printf("Packet capture complete.\n");
    }

    pcap_close(handle); //Close the handle
    return 0;
}