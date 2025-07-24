//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define NUM_THREADS 10

struct thread_args{
    int start_range;
    int end_range;
};

void* scan(void* args){
    struct thread_args* thread_args = (struct thread_args*) args;
    int start_range = thread_args->start_range;
    int end_range = thread_args->end_range;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("socket() error");
        pthread_exit(NULL);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    struct hostent* he;
    if ((he = gethostbyname("localhost")) == NULL){
        perror("gethostbyname() error");
        pthread_exit(NULL);
    }
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
    for (int ip = start_range; ip <= end_range; ip++){
        char ip_string[16];
        sprintf(ip_string, "%d.%d.%d.%d", (ip >> 24) & 0xff, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
        server_addr.sin_port = htons(80);
        if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof server_addr) == 0){
            printf("IP Address: %s is up\n", ip_string);
        }
    }
    close(sockfd);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    struct thread_args args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++){
        args[i].start_range = i * (0x1000000 / NUM_THREADS);
        args[i].end_range = (i + 1) * (0x1000000 / NUM_THREADS) - 1;
        pthread_create(&threads[i], NULL, scan, &args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}