//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 4096

int main(int argc, char* argv[]) {
    if(argc != 4) {
        printf("Usage: pop3client <server-ip> <username> <password>\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(110);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);

    if(recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Failed to receive");
        exit(1);
    }

    printf("%s", buffer);   

    sprintf(buffer, "USER %s\r\n", argv[2]);
    if(send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send user name");
        exit(1);
    }

    memset(buffer, 0, MAX_SIZE);
    if(recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Failed to receive");
        exit(1);
    }

    printf("%s", buffer);   

    sprintf(buffer, "PASS %s\r\n", argv[3]);
    if(send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send password");
        exit(1);
    }

    memset(buffer, 0, MAX_SIZE);
    if(recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Failed to receive");
        exit(1);
    }

    printf("%s", buffer);   

    sprintf(buffer, "LIST\r\n");
    if(send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send command");
        exit(1);
    }

    memset(buffer, 0, MAX_SIZE);
    if(recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Failed to receive");
        exit(1);
    }

    printf("%s", buffer);   

    sprintf(buffer, "QUIT\r\n");
    if(send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send command");
        exit(1);
    }

    memset(buffer, 0, MAX_SIZE);
    if(recv(sock, buffer, MAX_SIZE, 0) < 0) {
        perror("Failed to receive");
        exit(1);
    }

    printf("%s", buffer);   
    
    close(sock);

    return 0;
}