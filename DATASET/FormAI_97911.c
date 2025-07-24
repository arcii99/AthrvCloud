//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: mathematical
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) 
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *fp;

    // Open the network device for packet capture
    if ((fp = pcap_open_live("en0", 65535, 1, 1000, errbuf)) == NULL) 
    {
        fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", "en0");
        return 1;
    }

    // Compile the filter expression
    struct bpf_program filter;
    char filter_exp[] = "ip";
    bpf_u_int32 netmask;
    if (pcap_compile(fp, &filter, filter_exp, 0, netmask) == -1) 
    {
        fprintf(stderr, "\nError compiling filter: %s\n", pcap_geterr(fp));
        return 1;
    }

    // Apply the filter expression to the capture device
    if (pcap_setfilter(fp, &filter) == -1) 
    {
        fprintf(stderr, "\nError setting filter: %s\n", pcap_geterr(fp));
        return 1;
    }

    // Loop to capture packets and pass them to the packet_handler function
    pcap_loop(fp, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(fp);

    return 0;
}

// Function to handle captured packets
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    // Print packet timestamp and size
    printf("%ld:%ld (%ld)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

    // Parse the Ethernet header
    const u_char *ethernet_header = pkt_data;
    int ethernet_type = (ethernet_header[12] << 8) | ethernet_header[13];

    // Parse the IPv4 header
    if (ethernet_type == 0x0800) 
    {
        const u_char *ipv4_header = pkt_data + 14;
        int ipv4_total_length = (ipv4_header[2] << 8) | ipv4_header[3];
        int ipv4_protocol = ipv4_header[9];
        const u_char *ipv4_payload = ipv4_header + 4 * (ipv4_header[0] & 0x0f);

        // Print source and destination IP addresses and protocol
        printf("    %d.%d.%d.%d -> %d.%d.%d.%d  (proto=%d, len=%d)\n",
            ipv4_header[12], ipv4_header[13], ipv4_header[14], ipv4_header[15], 
            ipv4_header[16], ipv4_header[17], ipv4_header[18], ipv4_header[19],
            ipv4_protocol, ipv4_total_length - 4 * (ipv4_header[0] & 0x0f));

        // Parse the TCP header if the protocol is TCP
        if (ipv4_protocol == 0x06) 
        {
            const u_char *tcp_header = ipv4_payload;
            int tcp_header_length = 4 * (tcp_header[12] >> 4);
            const u_char *tcp_payload = tcp_header + tcp_header_length;

            // Print source and destination port numbers
            printf("        %d -> %d\n", (tcp_header[0] << 8) | tcp_header[1], 
                                          (tcp_header[2] << 8) | tcp_header[3]);
        }
    }
}