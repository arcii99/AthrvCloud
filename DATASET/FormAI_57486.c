//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 143

int main(int argc, char* argv[]) {
    char *ip_addr = "127.0.0.1";
    int sock_fd;
    struct sockaddr_in serv_addr;
    char buffer[4096] = { 0 };

    // create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set IP address and port number of IMAP server
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    // receive server greeting message
    memset(buffer, 0, sizeof(buffer));
    read(sock_fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // send login credentials
    char user_name[100], password[100];
    printf("Enter your username: ");
    scanf("%s", user_name);
    printf("Enter your password: ");
    scanf("%s", password);

    sprintf(buffer, "LOGIN %s %s\r\n", user_name, password);
    write(sock_fd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    read(sock_fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // send select command to select mailbox
    sprintf(buffer, "SELECT INBOX\r\n");
    write(sock_fd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    read(sock_fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // send fetch command to retrieve email
    sprintf(buffer, "FETCH 1 BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)]\r\n");
    write(sock_fd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    read(sock_fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    close(sock_fd);
    exit(EXIT_SUCCESS);
}