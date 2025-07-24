//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: genious
#include <stdio.h>
#include <pcap.h>

#define LINE_LEN 16

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
    int i=0;
    printf("Packet Captured at: %s", ctime((time_t*)&pkthdr->ts.tv_sec));
    printf("===================\n");
    for(i=0; i<pkthdr->len; i++) {
        if(i%LINE_LEN==0) {
            printf("%08x ", i);
        }
        printf("%02x ", packetData[i]);
        if((i+1)%LINE_LEN==0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    pcap_t* descr;
    char errbuf[PCAP_ERRBUF_SIZE];
    char* device;
    int promisciousMode = 0;
    int bufferSize = 1024;

    device = pcap_lookupdev(errbuf);
    if(device == NULL) {
        fprintf(stderr, "Error finding default device: %s\n", errbuf);
        return 2;
    }

    descr = pcap_open_live(device, bufferSize, promisciousMode, 0, errbuf);
    if(descr == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device, errbuf);
        return 2;
    }

    if(pcap_datalink(descr)!=DLT_EN10MB) {
        fprintf(stderr, "Device %s does not provide Ethernet headers - not supported\n", device);
        return 2;
    }

    printf("Listening on device: %s\n", device);
    pcap_loop(descr, -1, packetHandler, NULL);
    pcap_close(descr);
    return 0;
}