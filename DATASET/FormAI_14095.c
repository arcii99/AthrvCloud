//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <unistd.h>

#define ETHER_ADDR_LEN 6
#define IEEE80211_STYPE_PROBE_REQ 0x0040

/* Struct for storing radio header information */
struct radiotap_header {
    u_int8_t    it_version;     /* set to 0 */
    u_int8_t    it_pad;
    u_int16_t   it_len;         /* entire length */
    u_int32_t   it_present;     /* fields present */
};

/* Struct for storing IEEE 802.11 MAC frame information */
struct ieee80211_hdr {
    u_int16_t   frame_control;
    u_int16_t   duration_id;
    u_int8_t    addr1[ETHER_ADDR_LEN];
    u_int8_t    addr2[ETHER_ADDR_LEN];
    u_int8_t    addr3[ETHER_ADDR_LEN];
    u_int16_t   seq_ctrl;
};

/* Callback function for capturing packets */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {

    struct radiotap_header *rthdr;
    struct ieee80211_hdr *wifihdr;
    int i;

    // Parse the radiotap header
    rthdr = (struct radiotap_header*)pkt_data;
    pkt_data += rthdr->it_len;

    // Parse the 802.11 header
    wifihdr = (struct ieee80211_hdr*)pkt_data;

    // Check if this is a Probe Request frame
    if ((wifihdr->frame_control & 0xfff) == IEEE80211_STYPE_PROBE_REQ) {
        printf("Probe Request from %02x:%02x:%02x:%02x:%02x:%02x for %s\n",
               wifihdr->addr2[0], wifihdr->addr2[1], wifihdr->addr2[2],
               wifihdr->addr2[3], wifihdr->addr2[4], wifihdr->addr2[5],
               pkt_data + sizeof(struct ieee80211_hdr));
    }
}

int main(int argc, char **argv) {

    char *dev = "";
    pcap_t *fp;
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Find the default network device for packet capture
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }

    // Get the network address and mask of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the network device for packet capture
    fp = pcap_open_live(dev, 65535, 1, 1000, errbuf);
    if (fp == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    // Set the filter to capture only Probe Request frames
    struct bpf_program filter;
    char filter_exp[] = "type mgt subtype probe-req";
    if (pcap_compile(fp, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(fp));
        return(2);
    }
    if (pcap_setfilter(fp, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(fp));
        return(2);
    }

    // Begin packet capture loop
    printf("Scanning for wireless networks...\n");
    pcap_loop(fp, -1, packet_handler, NULL);

    // Close the network device for packet capture
    pcap_close(fp);
    return(0);
}