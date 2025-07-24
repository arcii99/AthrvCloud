//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s ftp_server username\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *ftp_server = argv[1];
    char *username = argv[2];
    char password[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    printf("Enter your FTP password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);

    if (inet_pton(AF_INET, ftp_server, &serv_addr.sin_addr) <= 0)
        error("ERROR invalid IP address");

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting to FTP server");

    ssize_t bytes_received = read(sockfd, response, BUFFER_SIZE);
    if (bytes_received < 0)
        error("ERROR reading response from server");
    response[bytes_received] = '\0';
    printf("%s", response);

    snprintf(command, BUFFER_SIZE, "USER %s\r\n", username);
    if (write(sockfd, command, strlen(command)) < 0)
        error("ERROR writing to server");

    bytes_received = read(sockfd, response, BUFFER_SIZE);
    if (bytes_received < 0)
        error("ERROR reading response from server");
    response[bytes_received] = '\0';
    printf("%s", response);

    snprintf(command, BUFFER_SIZE, "PASS %s\r\n", password);
    if (write(sockfd, command, strlen(command)) < 0)
        error("ERROR writing to server");

    bytes_received = read(sockfd, response, BUFFER_SIZE);
    if (bytes_received < 0)
        error("ERROR reading response from server");
    response[bytes_received] = '\0';
    printf("%s", response);

    snprintf(command, BUFFER_SIZE, "PASV\r\n");
    if (write(sockfd, command, strlen(command)) < 0)
        error("ERROR writing to server");

    bytes_received = read(sockfd, response, BUFFER_SIZE);
    if (bytes_received < 0)
        error("ERROR reading response from server");
    response[bytes_received] = '\0';
    printf("%s", response);

    char *p1 = strrchr(response, ',');
    char *p2 = strrchr(p1 - 1, ',');
    int port = atoi(p1 + 1) * 256 + atoi(p2 + 1);

    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0)
        error("ERROR opening socket");

    struct sockaddr_in data_addr;
    bzero(&data_addr, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    data_addr.sin_addr = serv_addr.sin_addr;

    if (connect(data_sockfd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0)
        error("ERROR connecting to FTP server (data port)");

    snprintf(command, BUFFER_SIZE, "LIST\r\n");
    if (write(sockfd, command, strlen(command)) < 0)
        error("ERROR writing to server");

    bytes_received = read(sockfd, response, BUFFER_SIZE);
    if (bytes_received < 0)
        error("ERROR reading response from server");
    response[bytes_received] = '\0';
    printf("%s", response);

    bytes_received = read(data_sockfd, response, BUFFER_SIZE);
    while (bytes_received > 0) {
        fwrite(response, bytes_received, 1, stdout);
        bytes_received = read(data_sockfd, response, BUFFER_SIZE);
    }

    if (bytes_received < 0)
        error("ERROR reading response from server (data port)");

    close(data_sockfd);
    close(sockfd);

    return 0;
}