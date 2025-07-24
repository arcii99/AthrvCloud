//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <pcap.h>

void packetHandler(unsigned char *userData, const struct pcap_pkthdr* pkthdr, const unsigned char* packetData) {
    printf("Packet captured!\n");
}

int main(int argc, char *argv[]) {
    int i = 0;
    char *device = NULL;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct bpf_program filterProgram;
    char filterString[1024] = "tcp and port 80";
    bpf_u_int32 netMask, netAddr;

    // Get device and network information
    device = pcap_lookupdev(errorBuffer);
    if (device == NULL) {
        fprintf(stderr, "Error: Unable to find network device: %s\n", errorBuffer);
        return 1;
    }

    if (pcap_lookupnet(device, &netAddr, &netMask, errorBuffer) == -1) {
        fprintf(stderr, "Error: Unable to lookup net: %s\n", errorBuffer);
        return 1;
    }

    // Open network device for packet capture
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errorBuffer);
    if (handle == NULL) {
        fprintf(stderr, "Error: Unable to open network interface: %s\n", errorBuffer);
        return 1;
    }

    // Set filter for capture
    if (pcap_compile(handle, &filterProgram, filterString, 0, netAddr) == -1) {
        fprintf(stderr, "Error: Unable to compile packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filterProgram) == -1) {
        fprintf(stderr, "Error: Unable to set packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Loop and capture packets
    while (i < 10) {
        pcap_dispatch(handle, 1, packetHandler, NULL);
        i++;
    }

    // Cleanup
    pcap_freecode(&filterProgram);
    pcap_close(handle);

    printf("Packet capture complete!\n");

    return 0;
}