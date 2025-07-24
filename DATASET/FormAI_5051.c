//FormAI DATASET v1.0 Category: DOS detector ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <time.h>

// Constants
#define MAX_TCP_PORTS 65536
#define INTER_PACKET_DELAY_MICROSECONDS 1000

// Variables
int tcp_counts[MAX_TCP_PORTS] = {0};
struct timespec last_packet_time = {0, 0};

// Function prototypes
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_stats();

int main(int argc, char **argv)
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Get the network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Get the network device's network IP address and subnet mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the network device capture handle
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, "tcp", 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", "tcp", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set the compiled filter expression
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", "tcp", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Start capturing packets on the network device
    pcap_loop(handle, 0, handle_packet, NULL);

    // Cleanup and exit
    pcap_freecode(&fp);
    pcap_close(handle);
    return EXIT_SUCCESS;
}

// Callback function for packet capture
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // Parse the Ethernet header
    struct ether_header *eth_header = (struct ethhdr *)packet;
    if (ntohs(eth_header->ether_type) != ETHERTYPE_IP)
    {
        return; // Not an IP packet
    }

    // Parse the IP header
    struct iphdr *ip_header = (struct iphdr *)(packet + sizeof(struct ether_header));
    if (ip_header->protocol != IPPROTO_TCP)
    {
        return; // Not a TCP packet
    }

    // Parse the TCP header
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
    int dst_port = ntohs(tcp_header->dest);
    if (dst_port >= MAX_TCP_PORTS)
    {
        return; // Invalid port number
    }

    // Update the TCP port counts and check for DoS attack
    tcp_counts[dst_port]++;
    struct timespec current_time;
    clock_gettime(CLOCK_REALTIME, &current_time);
    if (current_time.tv_sec - last_packet_time.tv_sec > 1)
    {
        print_stats();
        last_packet_time = current_time;
    }

    // Add a small delay between packets to reduce CPU usage
    struct timespec delay_time = {0, INTER_PACKET_DELAY_MICROSECONDS * 1000};
    nanosleep(&delay_time, NULL);
}

// Function to print the current stats and check for DoS attack
void print_stats()
{
    int total_tcp_count = 0;
    int max_tcp_count = 0;
    int max_tcp_port = 0;
    for (int i = 0; i < MAX_TCP_PORTS; i++)
    {
        total_tcp_count += tcp_counts[i];
        if (tcp_counts[i] > max_tcp_count)
        {
            max_tcp_count = tcp_counts[i];
            max_tcp_port = i;
        }
        tcp_counts[i] = 0; // Reset the TCP port count
    }
    printf("[%ld] Total TCP packets: %d, Most active port: %d (%d packets)\n", time(NULL), total_tcp_count, max_tcp_port, max_tcp_count);
    if (max_tcp_count > 1000)
    {
        printf("*** Possible DoS attack detected! ***\n");
    }
}