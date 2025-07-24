//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <stdio.h>
#include <pcap.h>

void print_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    int i;

    printf("Packet Capture\n");

    for (i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    printf("\nEnd Packet\n");
}

int main(int argc, char **argv)
{
    pcap_t *handle;
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    printf("Starting Packet Capturing...\n");

    /* Define the device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }
    printf("Device: %s\n", dev);

    /* Look up network information for the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open capture device */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    /* Loop and capture packets */
    pcap_loop(handle, 0, print_packet, NULL);

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Packet Capturing finished.\n");

    return 0;
}