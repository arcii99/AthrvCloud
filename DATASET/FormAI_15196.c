//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    static int count = 1;
    const u_char *packet;
    struct tm *ltime;
    char timestr[16];
    time_t local_tv_sec;

    packet = pkt_data;
    local_tv_sec = header->ts.tv_sec;
    ltime = localtime(&local_tv_sec);
    strftime(timestr, sizeof(timestr), "%H:%M:%S", ltime);

    printf("[%d] %s.%06d len:%d\n", count, timestr, header->ts.tv_usec, header->len);
    
    // Check for duplicates
    static unsigned char prev_packet[65535] = {0};
    if (!memcmp(prev_packet, pkt_data, header->len)) {
        printf("Duplicate packet detected!\n");
    }
    memcpy(prev_packet, pkt_data, header->len); // Save current packet for future comparison
    
    count++;
}

int main(int argc, char **argv)
{
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int num_packets = 100;

    // Get the name of the first suitable network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Open the network device for packet capture
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, "tcp or udp", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Set the callback function for packet processing
    if (pcap_loop(handle, num_packets, packet_handler, NULL) == -1) {
        fprintf(stderr, "Couldn't start packet capture: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Close the handle and free resources
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}