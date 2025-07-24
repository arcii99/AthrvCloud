//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: inquisitive
#include <stdio.h>
#include <pcap.h>

/* The callback function */
void capture(uint8_t *args, const struct pcap_pkthdr* header, const uint8_t* packet)
{
    printf("Packet captured of length %d\n", header->len);
}

int main(int argc, char **argv)
{
    char *dev; // device to capture on
    pcap_t *handle; // session handle
    char errbuf[PCAP_ERRBUF_SIZE]; // error string
    struct bpf_program fp; // compiled filter 
    char filter_exp[] = "ip"; // filter expression
    bpf_u_int32 mask; // subnet mask
    bpf_u_int32 net; // IP

    // obtain the network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", dev); // print device name

    // obtain network address and mask associated with the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open a session for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }
    printf("Capture session started...\n");

    // compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // start capturing packets
    pcap_loop(handle, 0, capture, NULL);

    // close the session
    pcap_close(handle);
    printf("Session closed.\n");

    return 0;
}