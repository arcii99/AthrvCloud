//FormAI DATASET v1.0 Category: Networking ; Style: modular
/* This is a simple modular program that creates a client-server chat system using sockets in C.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

void *receiver(void *sockfd) {
    int connfd = *(int *)sockfd;
    char recv_buffer[1024];
    bzero(recv_buffer, sizeof(recv_buffer));
    while (1) {
        int receive_flag = recv(connfd, recv_buffer, sizeof(recv_buffer), 0);
        if (receive_flag <= 0) {
            printf("Server closed!!!\n");
            exit(EXIT_SUCCESS);
        }
        printf("\nServer: %s\n", recv_buffer);
        bzero(recv_buffer, sizeof(recv_buffer));
    }
    return 0;
}

void *transmitter(void *sockfd) {
    int connfd = *(int *)sockfd;
    char send_buffer[1024];
    bzero(send_buffer, sizeof(send_buffer));
    while (1) {
        fgets(send_buffer, 1024, stdin);
        send(connfd, send_buffer, strlen(send_buffer), 0);
        bzero(send_buffer, sizeof(send_buffer));
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./client <server IP address>\n");
        exit(EXIT_FAILURE);
    }
    int port = 8080;
    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connfd == -1) {
        printf("Could not create socket!!!\n");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &server_address.sin_addr);
    if (connect(connfd, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) {
        printf("Could not connect to the server!!!\n");
        exit(EXIT_FAILURE);
    }
    printf("Connected to the server %s\n", argv[1]);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, receiver, &connfd);
    pthread_create(&t2, NULL, transmitter, &connfd);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    close(connfd);
    return 0;
}