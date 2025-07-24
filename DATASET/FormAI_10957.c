//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024
#define MAIL_SERVER_IP "127.0.0.1"
#define MAIL_SERVER_PORT 143

int main() {
    // create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("ERROR: Socket creation failed");
        exit(1);
    }

    // set server address and port number
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(MAIL_SERVER_IP);
    server_addr.sin_port = htons(MAIL_SERVER_PORT);

    // connect to server
    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR: Connection failed");
        exit(1);
    }

    // receive server greeting
    char buf[BUFF_SIZE];
    memset(buf, 0, BUFF_SIZE);
    if (recv(sock_fd, buf, BUFF_SIZE, 0) < 0) {
        perror("ERROR: Failed to receive server greeting");
        exit(1);
    }
    printf("%s", buf);

    // send login command to server
    char username[] = "username";
    char password[] = "password";
    char login_cmd[BUFF_SIZE];
    snprintf(login_cmd, BUFF_SIZE, "a001 LOGIN %s %s\r\n", username, password);
    if (send(sock_fd, login_cmd, strlen(login_cmd), 0) < 0) {
        perror("ERROR: Failed to send login command");
        exit(1);
    }

    // receive login response from server
    memset(buf, 0, BUFF_SIZE);
    if (recv(sock_fd, buf, BUFF_SIZE, 0) < 0) {
        perror("ERROR: Failed to receive login response");
        exit(1);
    }
    printf("%s", buf);

    // send select inbox command to server
    char select_cmd[] = "a002 SELECT INBOX\r\n";
    if (send(sock_fd, select_cmd, strlen(select_cmd), 0) < 0) {
        perror("ERROR: Failed to send select inbox command");
        exit(1);
    }

    // receive select response from server
    memset(buf, 0, BUFF_SIZE);
    if (recv(sock_fd, buf, BUFF_SIZE, 0) < 0) {
        perror("ERROR: Failed to receive select response");
        exit(1);
    }
    printf("%s", buf);

    // send fetch command to server
    char fetch_cmd[] = "a003 FETCH 1 BODY[HEADER]\r\n";
    if (send(sock_fd, fetch_cmd, strlen(fetch_cmd), 0) < 0) {
        perror("ERROR: Failed to send fetch command");
        exit(1);
    }

    // receive fetch response from server
    memset(buf, 0, BUFF_SIZE);
    if (recv(sock_fd, buf, BUFF_SIZE, 0) < 0) {
        perror("ERROR: Failed to receive fetch response");
        exit(1);
    }
    printf("%s", buf);

    // send logout command to server
    char logout_cmd[] = "a004 LOGOUT\r\n";
    if (send(sock_fd, logout_cmd, strlen(logout_cmd), 0) < 0) {
        perror("ERROR: Failed to send logout command");
        exit(1);
    }

    // receive logout response from server
    memset(buf, 0, BUFF_SIZE);
    if (recv(sock_fd, buf, BUFF_SIZE, 0) < 0) {
        perror("ERROR: Failed to receive logout response");
        exit(1);
    }
    printf("%s", buf);

    // close socket
    close(sock_fd);

    return 0;
}