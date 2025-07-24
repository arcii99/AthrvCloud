//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: statistical
#include <pcap.h>
#include <stdio.h>

/* Callback function to process captured packets */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {

    static int packet_count = 0;           // count of processed packets
    const int packet_size = header->len;   // size of the packet in bytes

    // print packet statistics
    printf("Packet #%d, size: %d bytes\n", ++packet_count, packet_size);
}

int main() {

    char errbuf[PCAP_ERRBUF_SIZE];  // buffer to store error messages
    char *dev_name;                 // device name
    pcap_t *pcap_handle;            // handle to capture session

    // get name of the first available network device
    dev_name = pcap_lookupdev(errbuf);
    if (dev_name == NULL) {
        fprintf(stderr, "Error finding network device: %s\n", errbuf);
        return 1;
    }

    // open the network device for packet capture
    pcap_handle = pcap_open_live(dev_name, BUFSIZ, 0, 1000, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Error opening device for capture: %s\n", errbuf);
        return 1;
    }

    // set packet capture filter
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }

    // capture packets until interrupted
    pcap_loop(pcap_handle, 0, packet_handler, NULL);

    // close the packet capture session
    pcap_close(pcap_handle);
    return 0;
}