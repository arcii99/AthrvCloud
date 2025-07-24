//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 25
#define BUFFER_SIZE 1024

// Function to print error message and exit program
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    char *server_ip = "127.0.0.1"; // Replace with the IP address of your SMTP server

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Failed to create socket");
    }

    // Set socket options to reuse address and prevent time wait
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        handle_error("Failed to set socket options");
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval)) < 0) {
        handle_error("Failed to set socket options");
    }
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 10000;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0) {
        handle_error("Failed to set socket receive timeout");
    }

    // Connect to SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) < 0) {
        handle_error("Invalid server IP address");
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr , sizeof(server_addr)) < 0) {
        handle_error("Failed to connect to server");
    }

    // Initialize SSL connection
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        handle_error("Failed to establish SSL connection");
    }

    char buffer[BUFFER_SIZE];
    strcpy(buffer, "EHLO myhost\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    strcpy(buffer, "MAIL FROM:<sender@example.com>\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    strcpy(buffer, "RCPT TO:<recipient@example.com>\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    strcpy(buffer, "DATA\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));

    strcpy(buffer, "Subject: Test email\r\n");
    strcat(buffer, "From: sender@example.com\r\n");
    strcat(buffer, "To: recipient@example.com\r\n");
    strcat(buffer, "\r\n");
    strcat(buffer, "This is a test email from my SMTP client.\r\n");
    strcat(buffer, ".\r\n");

    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    strcpy(buffer, "QUIT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Clean up SSL and socket resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}