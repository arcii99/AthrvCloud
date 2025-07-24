//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: portable
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Get the name of the network device
    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }

    // Open the device in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    // Compile and apply the filter
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    bpf_u_int32 mask, net;

    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Error getting netmask: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packetHandler, NULL);

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet Captured!\n");

    // Extract the source and destination MAC addresses
    printf("Source MAC Address: ");
    for (int i = 0; i < 6; i++) {
        printf("%02x", packet[i]);
        if (i < 5) printf(":");
    }
    printf("\n");

    printf("Destination MAC Address: ");
    for (int i = 6; i < 12; i++) {
        printf("%02x", packet[i]);
        if (i < 11) printf(":");
    }
    printf("\n");

    // Extract the source and destination IP addresses
    printf("Source IP Address: ");
    for (int i = 26; i < 30; i++) {
        printf("%d", packet[i]);
        if (i < 29) printf(".");
    }
    printf("\n");

    printf("Destination IP Address: ");
    for (int i = 30; i < 34; i++) {
        printf("%d", packet[i]);
        if (i < 33) printf(".");
    }
    printf("\n");

    // Extract the source and destination port numbers
    printf("Source Port Number: %d\n", ((int)packet[34] << 8) | (int)packet[35]);
    printf("Destination Port Number: %d\n", ((int)packet[36] << 8) | (int)packet[37]);

    printf("\n");
}