//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

// Define the number of packets to capture
#define NUM_PACKETS 10

// Define the structure for the IP header
struct ipheader {
    unsigned char      iph_ihl:4, // IP header length
                       iph_ver:4; // IP version
    unsigned char      iph_tos;  // Type of Service
    unsigned short int iph_len;  // IP packet length in bytes
    unsigned short int iph_id;   // Identification
    unsigned short int iph_offset; // Fragment offset field
    unsigned char      iph_ttl;  // Time to Live
    unsigned char      iph_protocol; // Protocol type
    unsigned short int iph_chksum;   // IP Header checksum
    struct  in_addr    iph_sourceip; // Source IP address
    struct  in_addr    iph_destip;   // Destination IP address
};

// Define the structure for the TCP header
struct tcpheader {
    unsigned short int tcph_srcport; // Source port number
    unsigned short int tcph_destport; // Destination port number
    unsigned int       tcph_seqnum; // Sequence number
    unsigned int       tcph_acknum; // Acknowledgement number
    unsigned char      tcph_reserved:4, // Reserved bits
                       tcph_offset:4; // Data offset
    unsigned char      tcph_flags; // TCP Flags
    unsigned short int tcph_win;   // TCP Window size
    unsigned short int tcph_chksum; // TCP Checksum
    unsigned short int tcph_urgptr; // TCP Urgent pointer
};

// Define the function to print packet information
void print_packet_info(unsigned char* buffer, int size) {
    // Define pointers to the IP header and TCP header in the buffer
    struct ipheader* ip = (struct ipheader*)(buffer + sizeof(struct ethhdr));
    int ip_header_length = ip->iph_ihl * 4;
    struct tcpheader* tcp = (struct tcpheader*)(buffer + ip_header_length + sizeof(struct ethhdr));
    int tcp_header_length = tcp->tcph_offset * 4;
    // Print the packet details
    printf("\n****************Packet Info*****************\n");
    printf("Packet size: %d bytes\n", size);
    printf("Source IP Address: %s\n", inet_ntoa(ip->iph_sourceip));
    printf("Destination IP Address: %s\n", inet_ntoa(ip->iph_destip));
    printf("Source Port: %d\n", ntohs(tcp->tcph_srcport));
    printf("Destination Port: %d\n", ntohs(tcp->tcph_destport));
    printf("Flags: ");
    if(tcp->tcph_flags & TH_FIN) printf("FIN ");
    if(tcp->tcph_flags & TH_SYN) printf("SYN ");
    if(tcp->tcph_flags & TH_RST) printf("RST ");
    if(tcp->tcph_flags & TH_PUSH) printf("PUSH ");
    if(tcp->tcph_flags & TH_ACK) printf("ACK ");
    if(tcp->tcph_flags & TH_URG) printf("URG ");
    printf("\n");
}

// Define the function to capture packets
void capture_packets(int sock) {
    unsigned char buffer[65536]; // Packet buffer
    int bytes_received; // Number of bytes received in a packet
    int total_packets = 0; // Total packets received
    while(total_packets < NUM_PACKETS) {
        // Receive a packet
        memset(buffer, 0, sizeof(buffer));
        bytes_received = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        if(bytes_received < 0) {
            printf("Error receiving packet: %s\n", strerror(errno));
            continue;
        }
        // Print packet information
        print_packet_info(buffer, bytes_received);
        total_packets++;
    }
}

// Define the main function
int main() {
    // Create a raw socket
    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_IP));
    if(sock < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }
    printf("Raw socket created...\n");
    // Promote the current process to a root user
    if(setuid(0) < 0) {
        printf("Error promoting to root user: %s\n", strerror(errno));
        exit(1);
    }
    printf("Promoted to root user...\n");
    // Activate the packet capturing
    capture_packets(sock);
    // Close the socket
    close(sock);
    return 0;
}