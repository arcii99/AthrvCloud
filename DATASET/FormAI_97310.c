//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>

#define MAX_PACKET_LEN 4096

struct pkt_metrics {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq_num;
    uint32_t ack_num;
    uint32_t tcp_payload_len;
};

void process_packet(const uint8_t *packet, const int len, struct pkt_metrics *metrics);
void print_metrics(const struct pkt_metrics *metrics);

int main(int argc, char **argv)
{
    int socket_raw;
    struct sockaddr_in saddr;
    uint8_t packet_buffer[MAX_PACKET_LEN];
    struct pkt_metrics metrics;

    memset(&metrics, 0, sizeof(metrics));

    //Create a raw socket that listens to TCP packets
    if ((socket_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("ERROR: Could not create raw socket");
        return -1;
    }

    //Bind the socket to a specific interface
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("192.168.0.10"); //Replace with IP address of the interface you want to listen on
    saddr.sin_port = htons(0); //Bind to any port
    if (bind(socket_raw, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
        perror("ERROR: Could not bind socket to interface");
        close(socket_raw);
        return -1;
    }

    printf("Listening for TCP packets...\n");

    //Listen for incoming TCP packets and process them
    while (1) {
        int packet_len = recvfrom(socket_raw, packet_buffer, MAX_PACKET_LEN, 0, NULL, NULL);
        if (packet_len < 0) {
            perror("ERROR: Failed to receive packet");
            continue;
        }

        process_packet(packet_buffer, packet_len, &metrics);
        print_metrics(&metrics);

        //Reset metrics for the next packet
        memset(&metrics, 0, sizeof(metrics));
    }

    close(socket_raw);
    return 0;
}

void process_packet(const uint8_t *packet, const int len, struct pkt_metrics *metrics)
{
    struct iphdr *iph = (struct iphdr *)packet;
    struct tcphdr *tcph = (struct tcphdr *)(packet + (iph->ihl * 4)); //Get the TCP header structure
    uint8_t *payload = (uint8_t *)(packet + (iph->ihl * 4) + (tcph->doff * 4)); //Get the TCP payload

    metrics->src_ip = ntohl(iph->saddr);
    metrics->dst_ip = ntohl(iph->daddr);
    metrics->src_port = ntohs(tcph->source);
    metrics->dst_port = ntohs(tcph->dest);
    metrics->seq_num = ntohl(tcph->seq);
    metrics->ack_num = ntohl(tcph->ack_seq);
    metrics->tcp_payload_len = ntohs(iph->tot_len) - (iph->ihl * 4) - (tcph->doff * 4);

    //TODO: Perform QoS analysis and update metrics accordingly
}

void print_metrics(const struct pkt_metrics *metrics)
{
    char src_ip_str[INET_ADDRSTRLEN];
    char dst_ip_str[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(metrics->src_ip), src_ip_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(metrics->dst_ip), dst_ip_str, INET_ADDRSTRLEN);

    printf("Source IP: %s\n", src_ip_str);
    printf("Destination IP: %s\n", dst_ip_str);
    printf("Source Port: %d\n", metrics->src_port);
    printf("Destination Port: %d\n", metrics->dst_port);
    printf("Sequence Number: %u\n", metrics->seq_num);
    printf("Acknowledgement Number: %u\n", metrics->ack_num);
    printf("TCP Payload Length: %u bytes\n", metrics->tcp_payload_len);
    printf("---\n");
}