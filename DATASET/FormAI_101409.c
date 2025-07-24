//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Alan Touring
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    char pcap_errbuf[PCAP_ERRBUF_SIZE];  // buffer to store pcap error messages
    pcap_t *pcap_handle = NULL;          // pcap session handle
    char *interface_name = NULL;         // name of the interface to capture packets from
    struct bpf_program filter;           // libpcap filter structure
    bpf_u_int32 subnet_mask;             // subnet mask of the interface
    bpf_u_int32 ip_address;              // IP address of the interface
    char filter_exp[] = "ip";            // libpcap filter expression

    /* Get the name of the interface to capture from */
    if (argc > 1) {
        interface_name = argv[1];
    } else {
        fprintf(stderr, "Usage: %s interface_name\n", argv[0]);
        exit(1);
    }

    /* Open the session in promiscuous mode */
    pcap_handle = pcap_open_live(interface_name, BUFSIZ, 1, 1000, pcap_errbuf);
    if (!pcap_handle) {
        fprintf(stderr, "pcap_open_live(): %s\n", pcap_errbuf);
        exit(1);
    }

    /* Get the subnet mask and IP address of the interface */
    if (pcap_lookupnet(interface_name, &ip_address, &subnet_mask, pcap_errbuf) < 0) {
        fprintf(stderr, "pcap_lookupnet(): %s\n", pcap_errbuf);
        exit(1);
    }

    /* Compile the filter expression */
    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, subnet_mask) < 0) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    /* Apply the compiled filter */
    if (pcap_setfilter(pcap_handle, &filter) < 0) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    /* Loop indefinitely and call the packet_handler function */
    pcap_loop(pcap_handle, -1, packet_handler, NULL);

    /* Close the session */
    pcap_close(pcap_handle);

    return 0;
}

/* Callback function to process captured packets */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet received\n");
}