//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 1024
#define DEFAULT_PORT 12345

static volatile int running = 1;

void sigint_handler(int sig) {
    running = 0;
}

void print_usage(const char *program_name) {
    printf("Usage: %s [-p PORT]\n\n"
           "Options:\n"
           "  -p PORT   port number to listen on for incoming messages\n", program_name);
}

int main(int argc, char **argv) {
    int port = DEFAULT_PORT;
    int option;
    while ((option = getopt(argc, argv, "p:")) != -1) {
        switch (option) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    signal(SIGINT, sigint_handler);

    // create UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // bind socket to port
    struct sockaddr_in address;
    memset(&address, 0, sizeof(struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("Failed to bind socket to port %d: %s\n", port, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", port);

    struct timeval start_time, end_time;

    while (running) {
        char packet[MAX_PACKET_SIZE];
        struct sockaddr_storage client_address;
        socklen_t client_address_len = sizeof(client_address);

        // receive packet
        ssize_t packet_size = recvfrom(sockfd, packet, sizeof(packet), 0,
                                       (struct sockaddr *)&client_address, &client_address_len);
        if (packet_size == -1) {
            if (errno == EINTR) {
                // interrupted by signal, just continue listening
                continue;
            }
            printf("Failed to receive UDP packet: %s\n", strerror(errno));
            break;
        }

        // measure packet processing time
        gettimeofday(&start_time, NULL);

        // simulate packet processing by sleeping for a random time
        srand(time(NULL));
        usleep(rand() % 50000);

        gettimeofday(&end_time, NULL);
        long processing_time_us = (end_time.tv_sec - start_time.tv_sec) * 1000000L +
                                  (end_time.tv_usec - start_time.tv_usec);

        // print processing time and packet size
        printf("Processed UDP packet of size %ld in %ld microseconds\n", packet_size, processing_time_us);
    }

    // cleanup
    close(sockfd);

    return 0;
}