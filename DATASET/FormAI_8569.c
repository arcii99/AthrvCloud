//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;

    // Find a network device to listen on
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", dev);

    // Open the device for packet capture
    if (pcap_lookupnet(dev, &net, NULL, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
    }
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Begin capturing packets
    pcap_loop(handle, -1, process_packet, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("\nCapture complete.\n");

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    static int count = 0;

    // Print packet header information
    printf("Packet #%d\n", ++count);
    printf("\tArrival Time: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("\tPacket length: %d\n", header->len);
    printf("\tData length: %d\n", header->caplen);

    // Print packet data in hex format
    printf("\tData: ");
    for (int i = 0; i < header->caplen; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n\n");
}