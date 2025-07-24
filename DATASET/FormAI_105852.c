//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int connect_to_server(char *server_ip, int port) {
    struct sockaddr_in server_address;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void receive_message(int sockfd) {
    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    int bytes_received = recv(sockfd, buffer, MAX_BUFFER - 1, 0);

    if (bytes_received == -1) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);
}

int main() {
    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());

    if (!ssl_ctx) {
        perror("Error creating SSL context");
        exit(EXIT_FAILURE);
    }

    SSL *ssl = SSL_new(ssl_ctx);

    if (!ssl) {
        perror("Error creating SSL structure");
        exit(EXIT_FAILURE);
    }

    char *server_ip = "imap.gmail.com";
    int port = 993;
    int sockfd = connect_to_server(server_ip, port);

    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    receive_message(sockfd);

    char *username = "YOUR_USERNAME";
    char *password = "YOUR_PASSWORD";
    char message[MAX_BUFFER];
    memset(message, 0, MAX_BUFFER);

    sprintf(message, "LOGIN %s %s\r\n", username, password);

    if (SSL_write(ssl, message, strlen(message)) <= 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    receive_message(sockfd);

    sprintf(message, "SELECT INBOX\r\n");

    if (SSL_write(ssl, message, strlen(message)) <= 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    receive_message(sockfd);

    SSL_shutdown(ssl);
    close(sockfd);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    return EXIT_SUCCESS;
}