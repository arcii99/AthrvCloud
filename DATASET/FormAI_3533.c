//FormAI DATASET v1.0 Category: Socket programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

// function to handle each client connection
void handle_client(int connfd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    ssize_t nbytes = read(connfd, buffer, sizeof(buffer));
    
    if (nbytes == -1) {
        perror("read error");
        return;
    }

    printf("Received message from client: %s\n", buffer);

    char *response = "Hello from the server!";
    if (write(connfd, response, strlen(response)) == -1) {
        perror("write error");
        return;
    }

    close(connfd);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd == -1) {
        perror("socket creation error");
        exit(1);
    }

    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("socket bind error");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("socket listen error");
        exit(1);
    }

    printf("Server listening on port %d\n", ntohs(addr.sin_port));

    while (1) {
        int connfd = accept(sockfd, NULL, NULL);
        
        if (connfd == -1) {
            perror("connection accept error");
            continue;
        }

        if (fork() == 0) {
            // child process handles incoming message and responds
            handle_client(connfd);
            exit(0);
        }
        
        // parent process continues listening for incoming connections
        close(connfd);
    }

    close(sockfd);
    return 0;
}