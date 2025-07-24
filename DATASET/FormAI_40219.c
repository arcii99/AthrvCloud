//FormAI DATASET v1.0 Category: Networking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd, n;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("[!] Socket creation error.\n");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        printf("[!] Invalid address/ Address not supported.\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("[!] Connection Failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("[+] Connected to the server!\n");
    printf("----------------------------------------------\n");
    printf("Welcome to my networking program, please enter a message:\n");

    while (1) {
        fgets(buffer, MAXLINE, stdin);
        write(sockfd, buffer, strlen(buffer));
        if (strcmp(buffer, "exit\n") == 0) {
            printf("[!] You have disconnected from the server.\n");
            break;
        }
        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, MAXLINE);
        printf("[+] Server: %s", buffer);
    }

    close(sockfd);
    return 0;
}