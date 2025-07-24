//FormAI DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<pthread.h>

#define MAX_THREADS 65535

void *scan_port(void *socket_desc){
    int port = *(int*)socket_desc;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(port);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0){
        printf("Port %d is open\n", port);
    }
    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Please provide an IP address\n");
        return 1;
    }

    char *ip = argv[1];
    pthread_t threads[MAX_THREADS];
    int rc, t;
    int port_nums[MAX_THREADS];
    int thread_count = 0;

    printf("Scanning started on IP address %s....\n", ip);
    for(int port = 1; port <= MAX_THREADS; port++){
        port_nums[thread_count] = port;
        rc = pthread_create(&threads[thread_count], NULL, scan_port, &port_nums[thread_count]);
        if(rc){
            printf("Error creating threads: %d\n", rc);
            exit(-1);
        }
        thread_count++;

        if(thread_count == MAX_THREADS){
            for(int i = 0; i < MAX_THREADS; i++){
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }
    }
    for(int i = 0; i < thread_count; i++){
        pthread_join(threads[i], NULL);
    }
    printf("Scan complete");
    return 0;
}