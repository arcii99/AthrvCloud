//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <pcap.h>
#include <stdio.h>

// Define a handler function for captured packets
void handlePacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){

    // Print the timestamp and length of the captured packet
    printf("Timestamp: %d.%d\nLength: %d\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

    // Print the data of the captured packet (in hexadecimal format)
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
    }

    printf("\n");

}

int main(){

    char *device; // The device to capture packets on
    char errbuf[PCAP_ERRBUF_SIZE]; // Buffer to store error messages

    // Get the name of the first device suitable for packet capture
    device = pcap_lookupdev(errbuf);

    if (device == NULL) { // If no suitable device was found
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }

    printf("Capturing on device: %s\n", device);

    // Open the device for packet capture
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) { // If the device could not be opened
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, handlePacket, NULL);

    // Close the packet capture device
    pcap_close(handle);

    return 0;

}