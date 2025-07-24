//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char* unused, const struct pcap_pkthdr* packet_header, const u_char* packet_data) {
    printf("Packet captured!\n");
    printf("Packet length: %d\n", packet_header->len);
}

int main(int argc, char* argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* pcap_handle;
    char* device;
    const int packet_count_limit = 1;
    const int timeout_limit = 10000; 
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    bpf_u_int32 subnet_mask, ip;
    int packet_capture_retval;

    // determine capture device
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }

    // get IP and subnet mask info
    if (pcap_lookupnet(device, &ip, &subnet_mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", device, errbuf);
        return(2);
    }

    // open capture device
    pcap_handle = pcap_open_live(device, BUFSIZ, 0, timeout_limit, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        return(2);
    }

    // apply filter
    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, ip) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(pcap_handle));
        return(2);
    }
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(pcap_handle));
        return(2);
    }

    // start packet capture loop
    packet_capture_retval = pcap_loop(pcap_handle, packet_count_limit, packet_handler, NULL);
    if (packet_capture_retval == -1) {
        fprintf(stderr, "Error occurred during packet capture: %s\n", pcap_geterr(pcap_handle));
        return(2);
    }

    // clean up
    pcap_freecode(&filter);
    pcap_close(pcap_handle);

    return 0;
}