//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 20
#define MAX_DEVICES 100

struct Device {
    char *ip;
    char *mac;
    int port;
};

struct ThreadArgs {
    struct in_addr *local_addr;
    int subnet;
    int port;
    struct Device *devices;
    int num_devices;
};

void *scan_subnet(void *args) {
    struct ThreadArgs *ta = (struct ThreadArgs *) args;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(ta->port);
    unsigned char ip_subnet[4];
    memcpy(ip_subnet, &ta->local_addr->s_addr, 4);
    int count = 0;
    for (int i = 1; i <= 255; i++) {
        ip_subnet[3] = i;
        addr.sin_addr.s_addr = *(unsigned int *) ip_subnet;
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket()");
            continue;
        }
        int ret = connect(sock, (struct sockaddr *) &addr, sizeof(addr));
        if (ret >= 0) {
            struct Device d;
            d.ip = strdup(inet_ntoa(addr.sin_addr));
            d.mac = NULL;
            d.port = ta->port;
            ta->devices[count++] = d;
        }
        close(sock);
    }
    return NULL;
}

void scan_network(struct in_addr *local_addr, int subnet, int port, struct Device *devices, int *num_devices) {
    pthread_t threads[MAX_THREADS];
    struct ThreadArgs args[MAX_THREADS];
    *num_devices = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        args[i].local_addr = local_addr;
        args[i].subnet = subnet;
        args[i].port = port;
        args[i].devices = &devices[*num_devices];
        args[i].num_devices = 0;
        if (pthread_create(&threads[i], NULL, scan_subnet, &args[i])) {
            perror("pthread_create()");
            exit(1);
        }
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror("pthread_join()");
            exit(1);
        }
        *num_devices += args[i].num_devices;
    }
}

int main() {
    struct in_addr local_addr;
    if (!inet_aton("192.168.1.10", &local_addr)) {
        perror("inet_aton()");
        exit(1);
    }
    struct Device devices[MAX_DEVICES];
    int num_devices;
    scan_network(&local_addr, 24, 80, devices, &num_devices);
    for (int i = 0; i < num_devices; i++) {
        printf("%s:%d\n", devices[i].ip, devices[i].port);
    }
    return 0;
}