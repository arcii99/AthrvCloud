//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: happy
// Welcome to the happiest Network Packet Monitoring example program!
// This program will monitor network packets and bring a smile to your face

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> // required for packet capture

void handlePacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Wow, such a beautiful packet!\n"); // let's compliment every packet
}

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // get the default network device
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        printf("Oops, failed to find the default network device: %s", errbuf);
        return 1;
    }

    // get the network address and mask of the network device
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Oops, failed to get network address and mask for %s: %s", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open the network device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        printf("Oops, failed to open network device %s: %s", dev, errbuf);
        return 1;
    }

    // compile and apply the filter to the network device
    if(pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        printf("Oops, failed to compile filter: %s", pcap_geterr(handle));
        return 1;
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        printf("Oops, failed to apply filter: %s", pcap_geterr(handle));
        return 1;
    }

    // start capturing packets and handling them with our custom function
    pcap_loop(handle, -1, handlePacket, NULL);

    // close the network device and return happy!
    pcap_close(handle);
    printf("Hooray, we successfully monitored network packets! :)");
    return 0;
}