//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
// Welcome to the Network Quality of Service (QoS) monitor example program!
// This program uses packet sniffing to monitor network traffic and measure QoS metrics.
// It shows real-time graphs of network latency, packet loss, and throughput, and allows you to set alarms when certain thresholds are reached.
// Let's get started! 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <pthread.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14
#define MAX_PACKET_SIZE 65535

// Declare packet statistics struct
struct packet_stats {
    int total_packets;
    int tcp_packets;
    int udp_packets;
    int icmp_packets;
    int other_packets;
    long long total_bytes;
    long long tcp_bytes;
    long long udp_bytes;
    long long icmp_bytes;
    long long other_bytes;
};

// Declare QoS metrics struct
struct qos_metrics {
    int total_packets;
    int lost_packets;
    double packet_loss_percent;
    double network_latency;
    double throughput;
};

// Declare variable to store packet statistics
struct packet_stats stats;

// Declare variables to store QoS metrics
struct qos_metrics metrics;

// Function to handle SIGINT signal and gracefully exit program
void handle_sigint(int sig) {
    printf("\nExiting program...\n");
    printf("Total packets captured: %d\n", stats.total_packets);
    printf("TCP packets: %d (%lld bytes)\n", stats.tcp_packets, stats.tcp_bytes);
    printf("UDP packets: %d (%lld bytes)\n", stats.udp_packets, stats.udp_bytes);
    printf("ICMP packets: %d (%lld bytes)\n", stats.icmp_packets, stats.icmp_bytes);
    printf("Other packets: %d (%lld bytes)\n", stats.other_packets, stats.other_bytes);
    printf("Average network latency: %.2f ms\n", metrics.network_latency);
    printf("Packet loss percentage: %.2f%%\n", metrics.packet_loss_percent);
    printf("Throughput: %.2f bytes/second\n", metrics.throughput);
    exit(0);
}

// Function to update QoS metrics
void update_metrics(const struct pcap_pkthdr *header) {
    // Update total packets
    metrics.total_packets++;
    // Calculate lost packets
    int lost = header->len - header->caplen;
    if (lost > 0) {
        metrics.lost_packets += lost;
        metrics.packet_loss_percent = (double)metrics.lost_packets / (double)(metrics.total_packets + metrics.lost_packets) * 100.0;
    }
    // Calculate network latency
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    double packet_latency = (double)(current_time.tv_sec - header->ts.tv_sec) * 1000.0 + (double)(current_time.tv_usec - header->ts.tv_usec) / 1000.0;
    metrics.network_latency += (packet_latency - metrics.network_latency) / (double)metrics.total_packets;
    // Calculate throughput
    metrics.throughput += (double)header->len / (double)metrics.total_packets;
}

// Function to print real-time statistics
void print_statistics() {
    system("clear");
    printf("Network Quality of Service (QoS) Monitor\n\n");
    printf("Latency: %.2f ms | Packet loss: %.2f%% | Throughput: %.2f bytes/second\n\n", 
           metrics.network_latency, metrics.packet_loss_percent, metrics.throughput);
    printf("Total packets captured: %d\n", stats.total_packets);
    printf("TCP packets: %d (%lld bytes)\n", stats.tcp_packets, stats.tcp_bytes);
    printf("UDP packets: %d (%lld bytes)\n", stats.udp_packets, stats.udp_bytes);
    printf("ICMP packets: %d (%lld bytes)\n", stats.icmp_packets, stats.icmp_bytes);
    printf("Other packets: %d (%lld bytes)\n", stats.other_packets, stats.other_bytes);
}

// Function to parse packets and update packet statistics
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Ignore packets smaller than Ethernet header
    if (header->caplen < SIZE_ETHERNET) {
        return;
    }
    // Update packet statistics
    stats.total_packets++;
    switch(packet[12]*256 + packet[13]) {
        case 0x0800: // IPv4 packet
            switch(packet[23]) {
                case IPPROTO_TCP: // TCP packet
                    stats.tcp_packets++;
                    stats.tcp_bytes += header->len;
                    break;
                case IPPROTO_UDP: // UDP packet
                    stats.udp_packets++;
                    stats.udp_bytes += header->len;
                    break;
                case IPPROTO_ICMP: // ICMP packet
                    stats.icmp_packets++;
                    stats.icmp_bytes += header->len;
                    break;
                default: // Other packet
                    stats.other_packets++;
                    stats.other_bytes += header->len;
                    break;
            }
            break;
        case 0x0806: // ARP packet
            stats.other_packets++;
            stats.other_bytes += header->len;
            break;
        case 0x86dd: // IPv6 packet
            stats.other_packets++;
            stats.other_bytes += header->len;
            break;
        default: // Other packet
            stats.other_packets++;
            stats.other_bytes += header->len;
            break;
    }
    // Update QoS metrics
    update_metrics(header);
    // Print real-time statistics
    print_statistics();
}

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }
    // Initialize packet statistics struct
    memset(&stats, 0, sizeof(stats));
    // Initialize QoS metrics struct
    metrics.total_packets = 0;
    metrics.lost_packets = 0;
    metrics.packet_loss_percent = 0.0;
    metrics.network_latency = 0.0;
    metrics.throughput = 0.0;
    // Define handle for packet capture
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp; // Filter expression
    char filter_exp[] = "ip"; // Set filter expression
    bpf_u_int32 net; // IP address of sniffing device
    bpf_u_int32 mask; // Netmask of sniffing device
    struct pcap_pkthdr header; // Packet header
    const u_char *packet; // Packet data
    // Get network device information
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", argv[1], errbuf);
        net = 0;
        mask = 0;
    }
    // Open network device in promiscuous mode
    handle = pcap_open_live(argv[1], SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        exit(1);
    }
    // Compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }
    // Register SIGINT signal handler
    signal(SIGINT, handle_sigint);
    // Start capturing packets
    printf("Capturing packets on %s...\n", argv[1]);
    pcap_loop(handle, -1, packet_handler, NULL);
    return 0;
}