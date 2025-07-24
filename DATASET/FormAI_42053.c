//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_THREADS 1024
#define TIMEOUT 2

struct thread_data{
    unsigned short port;
    char *ip_address;
};

void *scan_port(void *threadarg){
    struct thread_data *data;
    data = (struct thread_data *) threadarg;
    int sock_desc;
    struct sockaddr_in target_addr;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_desc == -1){
        printf("Could not create socket for Port %hu\n", data->port);
        return NULL;
    }
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(data->ip_address);
    target_addr.sin_port = htons(data->port);

    // set the socket timeout for connect operation
    setsockopt (sock_desc, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,
                sizeof(timeout));
    if(connect(sock_desc, (struct sockaddr *)&target_addr, sizeof(target_addr)) != 0){
        // port closed or host is not reachable
        close(sock_desc);
        return NULL;
    }
    printf("Port %hu on %s is Open!\n", data->port, data->ip_address);
    close(sock_desc);
    return NULL;
}

int main(int argc, char** argv) {
    if(argc < 2){
        printf("Please enter an IP address to scan!\n");
        return -1;
    }
    char *ip_address = argv[1];
    int i, j, thread_count;
    struct thread_data port_data[MAX_THREADS];
    pthread_t threads[MAX_THREADS];

    thread_count = 0;
    printf("Scanning ports on %s:\n", ip_address);
    for(i = 1; i <= 65535; i += MAX_THREADS){
        // create threads to scan a range of ports
        for(j = 0; j < MAX_THREADS; j++){
            port_data[j].port = i + j;
            port_data[j].ip_address = ip_address;
            if(pthread_create(&threads[j], NULL, scan_port, (void *)&port_data[j]) != 0){
                // failed to create thread
                printf("Error: failed to create thread for Port %hu\n", port_data[j].port);
                continue;
            }
            thread_count++;
            if(thread_count >= MAX_THREADS){
                // wait for all threads to complete before creating more
                for(j = 0; j < MAX_THREADS; j++){
                    pthread_join(threads[j], NULL);
                }
                thread_count = 0;
            }
        }
    }
    // wait for any remaining threads to complete
    for(j = 0; j < thread_count; j++){
        pthread_join(threads[j], NULL);
    }
    printf("Port Scan Complete!\n");
    return 0;
}