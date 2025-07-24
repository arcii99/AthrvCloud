//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Woo-hoo! We captured a packet!\n");
    // Add more code to analyze the contents of the packet if desired
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get a device to capture on
    pcap_if_t *devices;
    if (pcap_findalldevs(&devices, errbuf) == -1) {
        printf("Uh-oh, couldn't find any devices to capture on...\n");
        return 1;
    }

    // Print the list of devices to choose from
    printf("Choose a device to capture on:\n");
    for (pcap_if_t *d = devices; d != NULL; d = d->next) {
        printf("%s\n", d->name);
    }

    // Get the chosen device
    char device[PCAP_ERRBUF_SIZE];
    scanf("%s", device);

    // Open the device for capturing
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Oops, couldn't open the device for capturing: %s\n", errbuf);
        return 1;
    }

    // Use the pcap_loop function to capture packets continuously
    printf("Let's start capturing packets!\n");
    pcap_loop(handle, -1, handle_packet, NULL);

    // Close the device when finished
    pcap_close(handle);

    return 0;
}