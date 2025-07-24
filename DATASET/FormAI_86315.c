//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
    static int count = 1;
    printf("Packet number %d:\n", count);
    printf("    Time stamp: %s\n", ctime((const time_t*)&header->ts.tv_sec));
    printf("    Length: %d\n", header->len);
    printf("    Captured length: %d\n", header->caplen);
    printf("    Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
        packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);
    printf("    Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
        packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
    count++;
}

int main(){
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    bpf_u_int32 net, mask;
    char filter_exp[] = "icmp";
    int num_packets = 10;

    // get a device to capture packets from
    char *device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Failed to find default device: %s\n", error_buffer);
        return 1;
    }
    printf("Device: %s\n", device);

    // get network information for the device
    if (pcap_lookupnet(device, &net, &mask, error_buffer) == -1) {
        fprintf(stderr, "Failed to get netmask for device %s: %s\n", device, error_buffer);
        net = 0;
        mask = 0;
    }

    // open the device for capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open device %s: %s\n", device, error_buffer);
        return 1;
    }

    // compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Failed to compile filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // apply the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to apply filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // start capturing packets
    printf("Capturing %d packets...\n", num_packets);
    pcap_loop(handle, num_packets, got_packet, NULL);

    // clean up
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Done.\n");

    return 0;
}