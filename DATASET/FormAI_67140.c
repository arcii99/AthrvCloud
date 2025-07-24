//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv) {
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr;
    struct bpf_program fp;
    bpf_u_int32 net, mask;
    int promisc = 1;
    int timeout = 1000;
    int snaplen = 65535; // max packet size

    // get interface name
    if (argc > 1) {
        dev = argv[1];
    } else {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            printf("pcap_lookupdev() failed: %s\n", errbuf);
            exit(1);
        }
    }

    // get network and subnet mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("pcap_lookupnet() failed: %s\n", errbuf);
        exit(1);
    }
    
    // open interface
    descr = pcap_open_live(dev, snaplen, promisc, timeout, errbuf);
    if (descr == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    // compile filter
    if (pcap_compile(descr, &fp, "tcp", 0, net) == -1) {
        printf("pcap_compile() failed\n");
        pcap_close(descr);
        exit(1);
    }

    // set filter
    if (pcap_setfilter(descr, &fp) == -1) {
        printf("pcap_setfilter() failed\n");
        pcap_close(descr);
        exit(1);
    }

    // start capture loop
    pcap_loop(descr, -1, packetHandler, NULL);
    
    // cleanup
    pcap_freecode(&fp);
    pcap_close(descr);
    
    return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    printf("Packet captured!\n");
    printf("Size: %d bytes\n", pkthdr->len);
    printf("Timestamp: %s\n", ctime(&pkthdr->ts.tv_sec));
}