//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void scanner(char *ip_addr) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("[ERROR] Socket creation failed.\n");
        exit(0);
    } else {
        printf("[INFO] Socket successfully created.\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip_addr);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("[ERROR] Connection failed.\n");
        exit(0);
    } else {
        printf("[INFO] Connected to %s.\n", ip_addr);
    }

    close(sockfd);    
}

int main() {
    char ip_addr[MAX];
    char *token;

    printf("\n==========================================================\n");
    printf("Welcome to the Wireless Network Scanner.\n");
    printf("==========================================================\n");
    printf("Enter the IP address(es) you want to scan (separated by ','): ");
    fgets(ip_addr, MAX, stdin);
    token = strtok(ip_addr, ",");

    while (token != NULL) {
        char *trimmed = token;
        while (isspace(*trimmed)) {
            trimmed++;
        }
        int len = strlen(trimmed);
        if (len > 0 && trimmed[len-1] == '\n') {
            trimmed[len-1] = '\0';
        }
        scanner(trimmed);
        token = strtok(NULL, ",");
    }

    printf("==========================================================\n");
    printf("Scan complete.\n");

    return 0;
}