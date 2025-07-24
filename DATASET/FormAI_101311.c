//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define PORT_NUM 8080
#define PACKET_SIZE 1380
#define NUM_PACKETS 100
#define PTHREAD_NUM 10

double get_time();

int s = 0;
char *server_address;
char packet[PACKET_SIZE];
int num_packets_sent = 0;

void *send_packets(void *arg) {
    while (num_packets_sent < NUM_PACKETS) {
        if (sendto(s, packet, PACKET_SIZE, 0, (struct sockaddr *) arg, sizeof(struct sockaddr_in)) < 0) {
            perror("sendto failed");
            exit(1);
        }
        num_packets_sent++;
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    server_address = argv[1];

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(PORT_NUM);

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket failed");
        return 1;
    }

    for (int i = 0; i < PACKET_SIZE; i++)
        packet[i] = '0' + (i % 10);

    pthread_t threads[PTHREAD_NUM];
    for (int i = 0; i < PTHREAD_NUM; i++) {
        if (pthread_create(&threads[i], NULL, send_packets, (void *) &server) < 0) {
            perror("pthread_create failed");
            return 1;
        }
    }

    double start_time = get_time();
    for (int i = 0; i < PTHREAD_NUM; i++) {
        if (pthread_join(threads[i], NULL) < 0) {
            perror("pthread_join failed");
            return 1;
        }
    }
    double end_time = get_time();

    double elapsed_time = end_time - start_time;
    double throughput = (PACKET_SIZE * NUM_PACKETS * 8.0 / 1000000.0) / elapsed_time;

    printf("Throughput: %.2f Mbps\n", throughput);

    if (close(s) < 0) {
        perror("close failed");
        return 1;
    }

    return 0;
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}