//FormAI DATASET v1.0 Category: Chat server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serverAddr, clientAddr[MAX_CLIENTS];
    int newSocket[MAX_CLIENTS];
    struct sockaddr_in newAddr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];
    int clientCount = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    printf("Server socket opened successfully\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    printf("Socket bind successful\n");

    if(listen(sockfd, MAX_CLIENTS) == 0) {
        printf("Listening for incoming connections\n");
    } else {
        perror("Error listening for connections");
        exit(1);
    }

    while(1) {
        addr_size = sizeof(newAddr);
        newSocket[clientCount] = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if(newSocket[clientCount] < 0) {
            perror("Error accepting client connection");
            exit(1);
        } else {
            printf("New client connected: %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
        }

        // fork a child process for new client connection
        pid_t pid = fork();
        if(pid < 0) {
            perror("Error forking process for client connection");
            exit(1);
        }

        // child process
        if(pid == 0) {
            close(sockfd); // close child process copy of server socket

            while(1) {
                memset(buffer, '\0', BUFFER_SIZE);
                if(read(newSocket[clientCount], buffer, BUFFER_SIZE) < 0) {
                    perror("Error reading message from client");
                    exit(1);
                }
                printf("Received message from client %d: %s\n", clientCount, buffer);

                // check if client wants to exit
                if(strncmp(buffer, "exit", 4) == 0) {
                    printf("Client %d disconnected\n", clientCount);
                    break;
                }

                // send message to client
                char reply[BUFFER_SIZE] = "Server received your message";
                if(write(newSocket[clientCount], reply, strlen(reply)) < 0) {
                    perror("Error sending message to client");
                    exit(1);
                }
                printf("Sent message to client %d\n", clientCount);
            }
            // close client connection socket
            close(newSocket[clientCount]);
            exit(0);
        } else {
            // parent process
            close(newSocket[clientCount]); // close parent process copy of client connection socket
            if(++clientCount >= MAX_CLIENTS) {
                printf("Maximum number of clients exceeded\n");
                break;
            }
        }
    }
    // close server socket
    close(sockfd);
    return 0;
}