//FormAI DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64
#define MAX_HOPS 255
#define TIMEOUT_SECONDS 1
#define PROTOCOL_ICMP 1

void print_usage(char* program_name) {
    printf("Usage: %s [-h] [-t timeout] [-m max_hops] destination\n", program_name);
    printf("\nOptional arguments:\n");
    printf("\t-h: Displays this help message.\n");
    printf("\t-t: Sets the maximum timeout in seconds (default: 1).\n");
    printf("\t-m: Sets the maximum number of hops (default: 255).\n");
}

int create_socket() {
    int sockfd;

    sockfd = socket(AF_INET, SOCK_RAW, PROTOCOL_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SECONDS;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_ping(int sockfd, struct sockaddr_in* dest_addr, int ttl) {
    char packet[PACKET_SIZE];
    struct icmphdr* icmphdr_ptr;
    struct timeval* time_ptr;
    int packet_size = sizeof(struct icmphdr) + sizeof(struct timeval);

    memset(packet, 0, PACKET_SIZE);

    icmphdr_ptr = (struct icmphdr*) packet;
    icmphdr_ptr->type = ICMP_ECHO;
    icmphdr_ptr->code = 0;
    icmphdr_ptr->un.echo.sequence = 0;
    icmphdr_ptr->un.echo.id = getpid() & 0xFFFF;

    time_ptr = (struct timeval*) (packet + sizeof(struct icmphdr));
    if (gettimeofday(time_ptr, NULL) < 0) {
        perror("gettimeofday");
        exit(EXIT_FAILURE);
    }

    if (sendto(sockfd, packet, packet_size, 0, (struct sockaddr*)dest_addr, sizeof(*dest_addr)) < 0) {
        perror("sendto");
    }
}

double get_elapsed_time(struct timeval* start_time, struct timeval* end_time) {
    return (end_time->tv_sec - start_time->tv_sec) * 1000.0
           + (end_time->tv_usec - start_time->tv_usec) / 1000.0;
}

void print_result(int ttl, char* addr, double time) {
    if (addr != NULL) {
        printf("%d\t%s\t%.3f ms\n", ttl, addr, time);
    } else {
        printf("%d\t***\n", ttl);
    }
}

void receive_ping(int sockfd, struct sockaddr_in* sender_addr, char* sender_ip, int ttl) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in recv_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    struct iphdr* iphdr_ptr;
    struct icmphdr* icmphdr_ptr;
    struct timeval* time_ptr;
    double elapsed_time;

    memset(buffer, 0, PACKET_SIZE);

    if (recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr*)&recv_addr, &len) < 0) {
        return;
    }

    iphdr_ptr = (struct iphdr*) buffer;
    icmphdr_ptr = (struct icmphdr*) (buffer + (iphdr_ptr->ihl * 4));
    time_ptr = (struct timeval*) (buffer + (iphdr_ptr->ihl * 4) + sizeof(struct icmphdr));

    if (icmphdr_ptr->type == ICMP_ECHOREPLY) {
        elapsed_time = get_elapsed_time(time_ptr, &(struct timeval){0});
        inet_ntop(AF_INET, &(recv_addr.sin_addr), sender_ip, INET_ADDRSTRLEN);
        print_result(ttl, sender_ip, elapsed_time);
    } else if (icmphdr_ptr->type == ICMP_TIME_EXCEEDED) {
        inet_ntop(AF_INET, &(recv_addr.sin_addr), sender_ip, INET_ADDRSTRLEN);
        print_result(ttl, sender_ip, -1);
    }
}

void do_ping(int sockfd, struct sockaddr_in* dest_addr, int ttl) {
    char sender_ip[INET_ADDRSTRLEN];

    send_ping(sockfd, dest_addr, ttl);
    receive_ping(sockfd, dest_addr, sender_ip, ttl);
}

int main(int argc, char** argv) {
    int sockfd, max_hops, ttl = 1, c;
    double timeout = TIMEOUT_SECONDS;
    char* dest;
    struct sockaddr_in dest_addr;

    while ((c = getopt(argc, argv, "ht:m:")) != -1) {
        switch (c) {
            case 'h':
                print_usage(argv[0]);
                exit(EXIT_SUCCESS);
            case 't':
                timeout = atof(optarg);
                break;
            case 'm':
                max_hops = atoi(optarg);
                break;
            default:
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (optind >= argc) {
        printf("Error: destination address not provided.\n");
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    dest = argv[optind];

    sockfd = create_socket();

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    if (inet_aton(dest, &(dest_addr.sin_addr)) == 0) {
        struct hostent* hostent_ptr;
        hostent_ptr = gethostbyname(dest);
        if (hostent_ptr == NULL || hostent_ptr->h_addr_list[0] == NULL) {
            printf("Error: Could not resolve destination address.\n");
            exit(EXIT_FAILURE);
        }
        dest_addr.sin_addr = *((struct in_addr*) hostent_ptr->h_addr_list[0]);
    }

    while (ttl <= max_hops) {
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
        do_ping(sockfd, &dest_addr, ttl);
        ttl++;
    }

    close(sockfd);

    return 0;
}