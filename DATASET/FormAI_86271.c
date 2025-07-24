//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main() {

    char errbuf[PCAP_ERRBUF_SIZE];
    char *device = pcap_lookupdev(errbuf);

    if (device == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    
    printf("Happy network monitoring time! Using device: %s\n", device);
    
    // open device for live capture
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", device, errbuf);
        return 1;
    }
    
    // compile the filter expression
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    
    if (pcap_lookupnet(device, &net, NULL, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", device, errbuf);
        net = 0;
    }
    
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    
    // start capturing packets
    printf("Listening for packets...\n");
    pcap_loop(handle, -1, handle_packet, NULL);
    
    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    
    printf("Done!\n");
    return 0;
}

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // handle each packet as it comes in
    printf("Packet captured! Length: %d\n", header->len);
}