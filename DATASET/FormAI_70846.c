//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: realistic
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char *dev;  // name of the device to capture packets from
    char errbuf[PCAP_ERRBUF_SIZE];  // buffer for error messages
    pcap_t *handle;  // session handle
    struct bpf_program fp;  // compiled filter expression
    bpf_u_int32 net;  // IP address of the network to capture packets from
    bpf_u_int32 mask;  // subnet mask of the network to capture packets from
    char filter_exp[] = "tcp port 80";  // filter expression
    
    // find the default device to capture packets from
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    
    // get the network address and subnet mask of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    
    // open the session for capturing packets
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }
    
    // compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't apply filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    
    // start capturing packets
    printf("Starting packet capture on device %s...\n", dev);
    pcap_loop(handle, -1, packet_handler, NULL);
    
    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 0;  // number of packets processed
    printf("Packet %d:\n", ++count);
    printf("    Length: %d\n", header->len);
    printf("    Data:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}