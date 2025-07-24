//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define MAXIMUM_PACKET_SIZE 4096
#define DEFAULT_TIMEOUT 5000

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_color(char *message, char *color) {
    printf("%s%s%s", color, message, ANSI_COLOR_RESET);
}

int sockfd = -1;
int should_exit = 0;

unsigned short calculate_checksum(unsigned short *paddress, int len) {
    int nleft = len;
    int sum = 0;
    unsigned short *w = paddress;
    unsigned short answer = 0;

    while (nleft > 1) {
        sum += *w++;
        nleft -= sizeof(unsigned short);
    }

    if (nleft == 1) {
        *((unsigned char *) &answer) = *((unsigned char *) w);
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

int ping(struct sockaddr_in *addr) {
    struct timeval timeout = {0, DEFAULT_TIMEOUT};
    clock_t start, end;
    double elapsed_time;
    int addr_len = sizeof(struct sockaddr_in);
    int packet_size = 0, status = 0, bytes_received = 0;
    unsigned char packet_buffer[MAXIMUM_PACKET_SIZE];

    packet_size = 8;

    memset(packet_buffer, 0, MAXIMUM_PACKET_SIZE);

    packet_buffer[0] = 8;
    packet_buffer[1] = 0;
    packet_buffer[2] = 0;
    packet_buffer[3] = 0;
    packet_buffer[4] = 0;
    packet_buffer[5] = 1;
    packet_buffer[6] = 0 >> 8;
    packet_buffer[7] = 0 & 0xff;

    *(unsigned short *) (packet_buffer + 2) = calculate_checksum((unsigned short *) packet_buffer, packet_size);

    start = clock();

    if (sendto(sockfd, packet_buffer, packet_size, 0, (struct sockaddr *) addr, addr_len) <= 0) {
        print_color("sendto failed", ANSI_COLOR_RED);
        return status;
    }

    memset(packet_buffer, 0, MAXIMUM_PACKET_SIZE);

    bytes_received = recv(sockfd, packet_buffer, MAXIMUM_PACKET_SIZE, 0);

    end = clock();
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;

    if (bytes_received < 0) {
        print_color("recv failed", ANSI_COLOR_RED);
        return status;
    }

    if (packet_buffer[0] == 0) {
        print_color("Success!\n", "\033[0;32m");
        status = 1;
    } else {
        print_color("Failed!\n", ANSI_COLOR_RED);
    }

    printf("Time taken %ld ms\n", (long int) elapsed_time);

    return status;
}

void signal_handler(int signo) {
    should_exit = 1;
}

void loop(struct sockaddr_in *addr, char *ip_str) {
    while (!should_exit) {
        int status = ping(addr);

        if (status) {
            print_color("Signal strength is strong\n", "\033[0;32m");
        } else {
            print_color("Signal strength is weak\n", ANSI_COLOR_RED);
        }

        sleep(1);
    }

    close(sockfd);

    printf("Exiting....\n");
}

int main(int argc, char **argv) {
    struct addrinfo hints, *result, *p;
    struct sockaddr_in *ip_access;
    int status = 0;
    char ip_str[INET_ADDRSTRLEN];

    if (argc != 2) {
        print_color("usage: wifi_signal_strength_analyzer <ip_address>\n", ANSI_COLOR_RED);
        return 1;
    }

    signal(SIGINT, signal_handler);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &result)) != 0) {
        print_color("getaddrinfo failed", ANSI_COLOR_RED);
        return 1;
    }

    for (p = result; p != NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) {
            ip_access = (struct sockaddr_in *) p->ai_addr;
            inet_ntop(AF_INET, &ip_access->sin_addr, ip_str, INET_ADDRSTRLEN);
            printf("Scanning access point at %s\n", ip_str);
            break;
        }
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    loop(ip_access, ip_str);

    freeaddrinfo(result);

    return 0;
}