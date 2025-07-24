//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: accurate
#include <stdio.h>
#include <pcap.h>

#define SNAP_LEN 65535

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct pcap_pkthdr header;
    const u_char *packet;
  
    // Get device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
  
    // Get network and subnet mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
  
    // Open capture device
    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }
  
    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
  
    // Apply filter 
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
  
    // Capture packets
    while (packet = pcap_next(handle, &header)){
        printf("Received a packet with length of [%d]\n", header.len);
        printf("\n");
    }
  
   // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
  
    printf("\nCapture complete.\n");
    return(0);
}