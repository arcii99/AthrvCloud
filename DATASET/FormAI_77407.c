//FormAI DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKET_SIZE     64
#define ICMP_HEAD_LEN   8

// Function to calculate the checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for ( sum = 0; len > 1; len -= 2 ) {
        sum += *buf++;
    }

    if ( len == 1 ) {
        sum += *(unsigned char*)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    
    return result;
}

// Function to send ping request
void send_ping(int socketfd, struct sockaddr_in address, int pid) {
    char packet[PACKET_SIZE];
    memset(packet, 0, sizeof(packet));

    struct icmp* icmp_hdr = (struct icmp*) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = pid & 0xFFFF;
    icmp_hdr->icmp_seq = 0;
    icmp_hdr->icmp_cksum = checksum(icmp_hdr, PACKET_SIZE - ICMP_HEAD_LEN);

    // Sent the packet
    int sent_bytes = sendto(socketfd, packet, sizeof(packet), 0, (struct sockaddr*) &address, sizeof(address));
    if(sent_bytes == -1) {
        printf("Failed to send ping request.");
    }
}

// Function to receive the ping reply
double receive_ping(int socketfd, struct sockaddr_in address, int pid, int timeout) {
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    char response[PACKET_SIZE];
    memset(response, 0, sizeof(response));

    int len = sizeof(address);
    int received_bytes = recvfrom(socketfd, response, sizeof(response), 0, (struct sockaddr*) &address, &len);

    if(received_bytes == -1) {
        printf("Request timed out!\n");
        return -1;
    } else {
        struct iphdr* ip_hdr = (struct iphdr*) response;
        int ip_hdr_len = ip_hdr->ihl * 4;

        struct icmp* icmp_hdr = (struct icmp*) (response + ip_hdr_len);
        int icmp_hdr_len = received_bytes - ip_hdr_len;

        if(icmp_hdr->icmp_id == (pid & 0xFFFF)) {
            printf("Received reply from %s. Time = %ldms\n", inet_ntoa(address.sin_addr), (long int)(time(NULL)));
            return (double) (time(NULL));
        }
    }

    return -1;
}

// Main function
int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("\nUsage: %s <ip address>\n", argv[0]);
    } else {
        int pid = getpid();
        struct sockaddr_in address;

        int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        if(sockfd < 0) {
            printf("Unable to create raw socket.");
            return 0;
        }

        // Fill in the address details
        address.sin_family = AF_INET;
        address.sin_port = 0;
        address.sin_addr.s_addr = inet_addr(argv[1]);

        // Send ping requests and receive responses
        for(int i=0; i<10; i++) {
            send_ping(sockfd, address, pid);
            double recv_time = receive_ping(sockfd, address, pid, 1);

            if(recv_time != -1) {
                printf("Ping successful!\n");
            }
        }

        close(sockfd);
    }

    return 0;
}