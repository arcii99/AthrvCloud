//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user_args, const struct pcap_pkthdr *pkthdr, const u_char *packet) {

    // Print the packet
    printf("Packet Captured:\n");
    printf("=================\n");
    printf("Packet Size: %d\n", pkthdr->len);
    printf("Number of bytes: %d\n", pkthdr->caplen);
    printf("Recieved Time: %s", ctime((const time_t *)&pkthdr->ts.tv_sec));
    printf("Ethernet Header:\n");

    int i;
    for (i = 0; i < pkthdr->caplen; i++) {
        printf(" %02X", *(packet + i));
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n\n\n");
}

int main(int argc, char *argv[]) {

    pcap_t *pcap_handle;
    char err_buf[PCAP_ERRBUF_SIZE];
    char *dev_name;
    bpf_u_int32 net_addr;
    bpf_u_int32 mask;

    // Look for a device
    dev_name = pcap_lookupdev(err_buf);
    if (dev_name == NULL) {
        fprintf(stderr, "Error finding device: %s\n", err_buf);
        exit(EXIT_FAILURE);
    }

    // Get address and mask
    if (pcap_lookupnet(dev_name, &net_addr, &mask, err_buf) == -1) {
        fprintf(stderr, "Error getting network address and mask: %s\n", err_buf);
        exit(EXIT_FAILURE);
    }

    // Open the session
    pcap_handle = pcap_open_live(dev_name, BUFSIZ, 1, 0, err_buf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Error opening the capture session: %s\n", err_buf);
        exit(EXIT_FAILURE);
    }

    // Capture packets
    pcap_loop(pcap_handle, -1, packet_handler, NULL);

    // Close the session
    pcap_close(pcap_handle);

    return 0;
}