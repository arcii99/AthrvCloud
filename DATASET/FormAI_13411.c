//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: distributed
#include <pcap.h> 

#define MAX_PKT_SIZE 65535

int main(int argc, char *argv[]) 
{ 
    char *dev, errbuf[PCAP_ERRBUF_SIZE]; 
    pcap_t *handle; 
    struct bpf_program fp; 
    char filter_exp[] = "tcp"; // filter expression for tcp packets only
    bpf_u_int32 mask; 
    bpf_u_int32 net; 
    struct pcap_pkthdr header; 
    const u_char *packet; 

    // Step 1: Find a device to sniff on
    dev = pcap_lookupdev(errbuf); 
    if (dev == NULL) { 
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf); 
        return(2); 
    } 

    // Step 2: Get network number and mask associated with device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) { 
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf); 
        net = 0; 
        mask = 0; 
    } 

    // Step 3: Open the device for sniffing
    handle = pcap_open_live(dev, MAX_PKT_SIZE, 1, 1000, errbuf); 
    if (handle == NULL) { 
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf); 
        return(2); 
    } 

    // Step 4: Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) { 
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle)); 
        return(2); 
    } 

    // Step 5: Set the filter
    if (pcap_setfilter(handle, &fp) == -1) { 
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle)); 
        return(2); 
    } 

    // Step 6: Begin sniffing loop
    while(1) {
        packet = pcap_next(handle, &header); 
        printf("Received Packet Length: %d\n", header.len); 
    }

    // Step 7: Close the handle
    pcap_close(handle); 
    return(0);
}