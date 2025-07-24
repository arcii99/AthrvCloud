//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// SMTP server parameters
#define SERVER_IP_ADDR "192.168.1.1"
#define SERVER_PORT 25

int main() {
    int client_sock = socket(AF_INET, SOCK_STREAM, 0); // create a TCP socket
    if (client_sock == -1) {
        perror("socket() error");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT); // convert host byte order to network byte order
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDR);

    int ret = connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("connect() error");
        exit(1);
    }

    char recv_buffer[BUFFER_SIZE];
    char send_buffer[BUFFER_SIZE];

    ret = recv(client_sock, recv_buffer, BUFFER_SIZE, 0); // wait for server response
    if (ret == -1) {
        perror("recv() error");
        exit(1);
    }
    printf("%s", recv_buffer);

    // send HELO command
    sprintf(send_buffer, "HELO example.com\r\n");
    ret = send(client_sock, send_buffer, strlen(send_buffer), 0);
    if (ret == -1) {
        perror("send() error");
        exit(1);
    }

    ret = recv(client_sock, recv_buffer, BUFFER_SIZE, 0); // wait for server response
    if (ret == -1) {
        perror("recv() error");
        exit(1);
    }
    printf("%s", recv_buffer);

    // send MAIL FROM command
    sprintf(send_buffer, "MAIL FROM: <sender@example.com>\r\n");
    ret = send(client_sock, send_buffer, strlen(send_buffer), 0);
    if (ret == -1) {
        perror("send() error");
        exit(1);
    }

    ret = recv(client_sock, recv_buffer, BUFFER_SIZE, 0); // wait for server response
    if (ret == -1) {
        perror("recv() error");
        exit(1);
    }
    printf("%s", recv_buffer);

    // send RCPT TO command
    sprintf(send_buffer, "RCPT TO: <receiver@example.com>\r\n");
    ret = send(client_sock, send_buffer, strlen(send_buffer), 0);
    if (ret == -1) {
        perror("send() error");
        exit(1);
    }

    ret = recv(client_sock, recv_buffer, BUFFER_SIZE, 0); // wait for server response
    if (ret == -1) {
        perror("recv() error");
        exit(1);
    }
    printf("%s", recv_buffer);

    // send DATA command
    sprintf(send_buffer, "DATA\r\n");
    ret = send(client_sock, send_buffer, strlen(send_buffer), 0);
    if (ret == -1) {
        perror("send() error");
        exit(1);
    }

    ret = recv(client_sock, recv_buffer, BUFFER_SIZE, 0); // wait for server response
    if (ret == -1) {
        perror("recv() error");
        exit(1);
    }
    printf("%s", recv_buffer);

    // send email content
    sprintf(send_buffer, "From: sender@example.com\r\n");
    sprintf(send_buffer, "%sTo: receiver@example.com\r\n", send_buffer);
    sprintf(send_buffer, "%sSubject: Test Email\r\n", send_buffer);
    sprintf(send_buffer, "%s\r\n", send_buffer);
    sprintf(send_buffer, "%sThis is a test email.\r\n", send_buffer);
    sprintf(send_buffer, "%s.\r\n", send_buffer);

    ret = send(client_sock, send_buffer, strlen(send_buffer), 0);
    if (ret == -1) {
        perror("send() error");
        exit(1);
    }

    ret = recv(client_sock, recv_buffer, BUFFER_SIZE, 0); // wait for server response
    if (ret == -1) {
        perror("recv() error");
        exit(1);
    }
    printf("%s", recv_buffer);

    // send QUIT command
    sprintf(send_buffer, "QUIT\r\n");
    ret = send(client_sock, send_buffer, strlen(send_buffer), 0);
    if (ret == -1) {
        perror("send() error");
        exit(1);
    }

    ret = recv(client_sock, recv_buffer, BUFFER_SIZE, 0); // wait for server response
    if (ret == -1) {
        perror("recv() error");
        exit(1);
    }
    printf("%s", recv_buffer);

    close(client_sock); // close the socket
    return 0;
}