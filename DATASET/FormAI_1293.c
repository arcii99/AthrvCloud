//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PROXY_PORT 8080
#define MAX_BUFF_SIZE 4096

void handle_connection(int sockfd, char *buffer);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server-ip-address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr, client_addr;
    int sockfd;
    pid_t pid;

    
    /* Create the proxy socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Failed to create proxy socket");
        return EXIT_FAILURE;
    }

    /* Bind the socket to a specific IP and port */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PROXY_PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Failed to bind the proxy socket");
        close(sockfd);
        return EXIT_FAILURE;
    }

    /* Start listening */
    if (listen(sockfd, 10) < 0) {
        perror("Error: Failed to listen");
        close(sockfd);
        return EXIT_FAILURE;
    }

    printf("Proxy server started. Listening to incoming connections on port %d ...\n", PROXY_PORT);

    /*. Accept incoming connections and handle them as separate child processes. */
    while (1) {
        socklen_t client_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

        if (client_sockfd < 0) {
            perror("Error: Unable to establish connection");
            continue;
        }

        pid = fork();
        if (pid < 0) {
            perror("Error: Failed to create child process");
            close(client_sockfd);
            continue;
        } else if (pid == 0) { /* Child process */
            close(sockfd);
            handle_connection(client_sockfd, argv[1]);
            exit(EXIT_SUCCESS);
        } else { /* Parent process */
            close(client_sockfd);
            continue;
        }
    }
    return EXIT_SUCCESS;
}

void handle_connection(int sockfd, char *remote_ip) {
    struct sockaddr_in remote_addr;
    char remote_buff[MAX_BUFF_SIZE], proxy_buff[MAX_BUFF_SIZE];
    int remote_sockfd, n;

    /* Create a socket to connect to the remote server */
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(80);

    if (inet_aton(remote_ip, &remote_addr.sin_addr) == 0) {
        perror("inet_aton() failed to convert IP address");
        close(sockfd);
        return;
    }

    remote_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_sockfd < 0) {
        perror("Error: Failed to create remote socket");
        close(sockfd);
        return;
    }

    /* Connect to the remote server */
    if (connect(remote_sockfd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("Error: Failed to connect to remote server");
        close(sockfd);
        close(remote_sockfd);
        return;
    }

    printf("Proxy established a connection with %s:%d\n", remote_ip, 80);

    /* Forward data between the client and the remote server */
    memset(remote_buff, 0, sizeof(remote_buff));
    while (recv(sockfd, remote_buff, sizeof(remote_buff), 0) > 0) {
        printf("Received %d bytes from client\n", strlen(remote_buff));

        /* Send to remote server */
        if (send(remote_sockfd, remote_buff, strlen(remote_buff), 0) < 0) {
            perror("Error: Failed to send data to remote server");
            break;
        }

        printf("Sent %d bytes to remote server\n", strlen(remote_buff));
        memset(remote_buff, 0, sizeof(remote_buff));

        /* Receive from remote server */
        if ((n = recv(remote_sockfd, proxy_buff, sizeof(proxy_buff), 0)) > 0) {
            printf("Received %d bytes from remote server\n", n);

            /* Send to client */
            if (send(sockfd, proxy_buff, n, 0) < 0) {
                perror("Error: Failed to send data to client");
                break;
            }

            printf("Sent %d bytes to client\n", n);
            memset(proxy_buff, 0, sizeof(proxy_buff));
        } else {
            break;
        }
    }

    close(sockfd);
    close(remote_sockfd);

    printf("Proxy closed connection with %s:%d\n", remote_ip, 80);
}