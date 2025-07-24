//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFSIZE 1024
#define SERVERPORT 110

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *username, *password, recvbuff[BUFFSIZE], sendbuff[BUFFSIZE];

    if(argc != 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }

    username = argv[2];

    password = getpass("Enter your password: ");

    // Create the socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVERPORT);
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(1);
    }

    // Connect to server
    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Receive welcome message from server
    recv(sock, recvbuff, BUFFSIZE, 0);
    printf("%s", recvbuff);

    // Send login information
    sprintf(sendbuff, "USER %s\r\n", username);
    send(sock, sendbuff, strlen(sendbuff), 0);
    recv(sock, recvbuff, BUFFSIZE, 0);
    printf("%s", recvbuff);

    sprintf(sendbuff, "PASS %s\r\n", password);
    send(sock, sendbuff, strlen(sendbuff), 0);
    recv(sock, recvbuff, BUFFSIZE, 0);
    printf("%s", recvbuff);

    // List messages
    sprintf(sendbuff, "LIST\r\n");
    send(sock, sendbuff, strlen(sendbuff), 0);
    recv(sock, recvbuff, BUFFSIZE, 0);
    printf("%s", recvbuff);
    while(strcmp(recvbuff, ".\r\n")) {
        recv(sock, recvbuff, BUFFSIZE, 0);
        printf("%s", recvbuff);
    }

    // Delete first message
    sprintf(sendbuff, "DELE 1\r\n");
    send(sock, sendbuff, strlen(sendbuff), 0);
    recv(sock, recvbuff, BUFFSIZE, 0);
    printf("%s", recvbuff);

    // Quit session
    sprintf(sendbuff, "QUIT\r\n");
    send(sock, sendbuff, strlen(sendbuff), 0);
    recv(sock, recvbuff, BUFFSIZE, 0);
    printf("%s", recvbuff);

    // Close socket and exit
    close(sock);
    exit(0);
}