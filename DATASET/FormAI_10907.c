//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: authentic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* callback function for packet processing */
void process_packet(u_char *args, const struct pcap_pkthdr *header,
                    const u_char *buffer)
{
    // print the current timestamp
    printf("\nPacket timestamp: %s", ctime((const time_t *)&header->ts.tv_sec));
    
    // get the packet length
    printf("Packet length: %d\n", header->len);
    
    // get the source and destination IP addresses
    struct sockaddr_in *source_ip, *dest_ip;
    source_ip = (struct sockaddr_in *)&buffer[26];
    dest_ip = (struct sockaddr_in *)&buffer[30];
    printf("Source IP address: %s\n", inet_ntoa(source_ip->sin_addr));
    printf("Dest IP address: %s\n", inet_ntoa(dest_ip->sin_addr));
    
    // get the protocol type
    printf("Protocol type: ");
    switch(buffer[23]) {
        case 1:
            printf("ICMP\n");
            break;
        case 6:
            printf("TCP\n");
            break;
        case 17:
            printf("UDP\n");
            break;
        default:
            printf("Other\n");
            break;
    }
}

int main(int argc, char *argv[])
{
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "ip";
    bpf_u_int32 subnet_mask, ip;
    int packet_count_limit = 10;
    int timeout_limit = 10000;
    
    // get the default network device
    char *device = pcap_lookupdev(error_buffer);
    
    // get the network device information
    pcap_lookupnet(device, &ip, &subnet_mask, error_buffer);
    
    // open the network device for capturing packets
    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    
    // compile and apply the filter expression
    pcap_compile(handle, &filter, filter_exp, 0, ip);
    pcap_setfilter(handle, &filter);
    
    // start capturing packets and process them
    pcap_loop(handle, packet_count_limit, process_packet, NULL);
    
    // close the network device
    pcap_close(handle);
    
    return 0;
}