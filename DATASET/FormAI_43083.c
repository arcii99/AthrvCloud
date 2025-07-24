//FormAI DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define BUFSIZE 1500 // Maximum size of the data in IP packet
#define MAXCOUNT 3 // Maximum number of packets sent and received
#define TIMEOUT 1000 // Timeout for waiting to receive a packet in milliseconds

char sendbuf[BUFSIZE]; // Buffer for outgoing ICMP packet
char recvbuf[BUFSIZE]; // Buffer for incoming ICMP packet

// Calculates the checksum for ICMP packet
unsigned short checksum(void *b, int len) {    
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for ( sum = 0; len > 1; len -= 2 )
        sum += *buf++;

    if ( len == 1 )
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

// Handles alarm signal during waiting for receiving a packet
void handler(int signum) {
    return;
}

// Sends an ICMP packet to specified host
void send_icmp(int s, struct sockaddr_in *addr, int seq, int pid) {
    struct icmp *icmp;
    int len;

    // Fill ICMP header
    icmp = (struct icmp *)sendbuf;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_seq = seq;
    icmp->icmp_id = pid;
    icmp->icmp_cksum = 0;
    icmp->icmp_cksum = checksum(icmp, sizeof(struct icmp));

    // Send ICMP packet
    len = sendto(s, sendbuf, sizeof(struct icmp), 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
    if (len < 0) {
        perror("sendto() error");
        exit(EXIT_FAILURE);
    }
}

// Receives an ICMP packet from specified host
int recv_icmp(int s, struct sockaddr_in *addr) {
    struct iphdr *ip;
    struct icmp *icmp;
    int len, addr_len;

    // Wait for receiving a packet until timeout occurs
    signal(SIGALRM, handler);
    alarm(TIMEOUT);
    addr_len = sizeof(struct sockaddr_in);
    len = recvfrom(s, recvbuf, sizeof(struct iphdr) + sizeof(struct icmp), 0, (struct sockaddr *)addr, &addr_len);
    alarm(0);
    if (len < 0 && errno == EINTR) // Timeout occurred
        return -1;
    if (len < 0) {
        perror("recvfrom() error");
        exit(EXIT_FAILURE);
    }

    // Check IP and ICMP headers
    ip = (struct iphdr *)recvbuf;
    icmp = (struct icmp *)(recvbuf + (ip->ihl << 2));
    if (ip->saddr != addr->sin_addr.s_addr || icmp->icmp_type != ICMP_ECHOREPLY || icmp->icmp_id != getpid())
        return -1;

    return TIMEOUT - alarm(0); // Return round trip time in milliseconds
}

// Performs a ping test to specified host
void ping_test(char *host) {
    struct hostent *he;
    struct sockaddr_in addr;
    int s, i, rtts[MAXCOUNT], success_count = 0;
    float avg_rtt = 0.0;

    // Lookup IP address of the host
    if ((he = gethostbyname(host)) == NULL) {
        perror("gethostbyname() error");
        exit(EXIT_FAILURE);
    }

    // Open raw socket for sending/receiving ICMP packets
    if ((s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    // Fill sockaddr_in structure
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr *)he->h_addr;

    // Send and receive ICMP packets for specified number of times
    for (i = 0; i < MAXCOUNT; i++) {
        send_icmp(s, &addr, i, getpid());
        if (recv_icmp(s, &addr) > 0) {
            success_count++;
            rtts[i] = recv_icmp(s, &addr);
            avg_rtt += rtts[i];
            printf("Ping response from %s - Round trip time = %d ms\n", host, rtts[i]);
        }
        else {
            printf("Ping timed out for %s\n", host);
        }
        sleep(1);
    }

    // Print summary of the ping test
    printf("\nPing summary for %s\n", host);
    printf("Packets sent = %d, Received = %d, Loss = %d (%.0f%% loss), Average RTT = %.2f ms\n", MAXCOUNT, success_count, MAXCOUNT-success_count, ((float)(MAXCOUNT-success_count)/(float)MAXCOUNT)*100.0, (success_count>0)? avg_rtt/success_count:0.0);

    close(s); // Close raw socket
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping_test(argv[1]);

    return 0;
}