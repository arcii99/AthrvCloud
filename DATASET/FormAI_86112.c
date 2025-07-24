//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: romantic
#include <pcap.h> /* include library for packet capturing */

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *dev = "eth0"; /* specify the device to capture packets on */
    char errbuf[PCAP_ERRBUF_SIZE]; /* buffer to hold error messages */
    pcap_t *handle; /* handle to the device */
    struct bpf_program fp; /* compiled filter program (expression) */
    char filter_exp[] = "tcp port 80"; /* expression to compile */
    const int num_packets = 10; /* number of packets to capture */

    /* initialize packet capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 2;
    }

    /* compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, 0) == -1) {
        fprintf(stderr, "Could not compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not apply filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    /* start capturing packets */
    pcap_loop(handle, num_packets, packet_handler, NULL);

    /* cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Done\n");
    return 0;
}

/* handle each captured packet */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet length: %d\n", header->len);
    /* add code to analyze and process the packet here */
}