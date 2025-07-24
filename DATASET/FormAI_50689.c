//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

void handle_connection(int sockfd, struct sockaddr_in client_addr) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    int read_len = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if(read_len < 0) {
        perror("Error in recv");
        exit(EXIT_FAILURE);
    }
    printf("Data received from %s: %s\n", inet_ntoa(client_addr.sin_addr), buffer);
    close(sockfd);
}

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if(bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if(listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("Error in listening for connections");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Accept new connection
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &addr_len);
        if(newsockfd < 0) {
            perror("Error in accepting new connection");
            exit(EXIT_FAILURE);
        }
        pid_t pid = fork();
        if(pid < 0) {
            perror("Error in creating child process");
            exit(EXIT_FAILURE);
        }
        if(pid != 0) {
            close(newsockfd);
            continue;
        }
        // Child process
        close(sockfd);
        // Handle incoming connection
        handle_connection(newsockfd, client_addr);
        exit(EXIT_SUCCESS);
    }
    return 0;
}