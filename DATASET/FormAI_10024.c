//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_HOSTS 10
#define TIMEOUT_SEC 1

struct host {
    char *name;
    struct sockaddr_in addr;
    int seq_num;
    bool is_alive;
    struct timeval sent_time;
    struct timeval recv_time;
};

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sock;
    struct host hosts[MAX_HOSTS];
    int num_hosts = 0;
    fd_set read_fds;
    FD_ZERO(&read_fds);
    int max_sd = 0;

    if (argc < 2) {
        error("Usage: ./ping_test host1 [host2] ... [hostN]");
    }

    /* Create socket */
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        error("Unable to create socket");
    }

    /* Set timeout */
    struct timeval tv;
    tv.tv_sec = TIMEOUT_SEC;
    tv.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv)) < 0) {
        error("Unable to set timeout");
    }

    /* Set up hosts */
    for (int i = 1; i < argc && num_hosts < MAX_HOSTS; i++) {
        struct host h;
        struct hostent *he;
        memset(&h, 0, sizeof(h)); // initialize struct to 0
        he = gethostbyname(argv[i]);
        if (he == NULL) {
            printf("Unable to resolve host %s\n", argv[i]);
        } else {
            h.name = argv[i];
            h.addr.sin_family = AF_INET;
            h.addr.sin_port = htons(0);
            memcpy(&h.addr.sin_addr, he->h_addr_list[0], he->h_length);
            hosts[num_hosts] = h;
            num_hosts++;
        }
    }

    /* Send ping packets */
    int seq_num = 1;
    for (int i = 0; i < num_hosts; i++) {
        struct host *h = &hosts[i];
        h->seq_num = seq_num++;
        h->is_alive = false;
        gettimeofday(&h->sent_time, NULL);
        if (sendto(sock, &h->seq_num, sizeof(h->seq_num), 0, (struct sockaddr *)&h->addr, sizeof(h->addr)) < 0) {
            printf("Unable to send ping packet to %s\n", h->name);
        } else {
            if (sock > max_sd) {
                max_sd = sock;
            }
            FD_SET(sock, &read_fds);
        }
    }

    /* Wait for responses */
    int num_alive = 0;
    while (num_alive < num_hosts) {
        if (select(max_sd + 1, &read_fds, NULL, NULL, &tv) < 0) {
            error("Select error");
        }
        for (int i = 0; i < num_hosts; i++) {
            struct host *h = &hosts[i];
            if (FD_ISSET(sock, &read_fds)) {
                int seq_num;
                socklen_t len = sizeof(h->addr);
                if (recvfrom(sock, &seq_num, sizeof(seq_num), 0, (struct sockaddr *)&h->addr, &len) < 0) {
                    printf("Unable to receive ping response from %s\n", h->name);
                } else {
                    if (seq_num == h->seq_num) {
                        h->is_alive = true;
                        h->recv_time = tv;
                        num_alive++;
                    } else {
                        printf("Received incorrect sequence number from %s\n", h->name);
                    }
                }
            } else {
                printf("No response received from %s\n", h->name);
            }
        }
    }

    /* Print results */
    printf("%-30s %-10s %-10s %-10s\n", "Host", "Is Alive", "RTT", "Lost Packets");
    for (int i = 0; i < num_hosts; i++) {
        struct host *h = &hosts[i];
        if (h->is_alive) {
            long rtt = 1000 * (h->recv_time.tv_sec - h->sent_time.tv_sec) + (h->recv_time.tv_usec - h->sent_time.tv_usec) / 1000;
            printf("%-30s %-10s %-10ld %-10d\n", h->name, "yes", rtt, 0);
        } else {
            printf("%-30s %-10s %-10s %-10d\n", h->name, "no", "-", 1);
        }
    }

    return 0;
}