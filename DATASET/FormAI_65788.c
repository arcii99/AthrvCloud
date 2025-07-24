//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.example.com"
#define PORT 993

int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024], cmd[256], username[256], password[256];
    int bytes, n;

    // Initialize SSL library
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    // Create a new SSL context for TLSv1.2
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        fprintf(stderr, "SSL_CTX_new() failed\n");
        exit(EXIT_FAILURE);
    }

    // Set up SSL options
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_COMPRESSION | SSL_OP_SINGLE_DH_USE);

    // Create a new TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "socket() failed\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the IMAP server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    server_addr.sin_port = htons(PORT);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "connect() failed\n");
        exit(EXIT_FAILURE);
    }

    // Create a new SSL object for the socket
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    // Perform SSL handshake
    if (SSL_connect(ssl) < 1) {
        fprintf(stderr, "SSL_connect() failed\n");
        exit(EXIT_FAILURE);
    }

    // Get server greeting message
    bytes = SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send LOGIN command
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\r\n")] = 0; // remove newline characters
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\r\n")] = 0; // remove newline characters
    sprintf(cmd, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, cmd, strlen(cmd));

    // Read response to LOGIN command
    bytes = SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send SELECT command for INBOX
    sprintf(cmd, "SELECT INBOX\r\n");
    SSL_write(ssl, cmd, strlen(cmd));

    // Read response to SELECT command
    bytes = SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send FETCH command for first message
    sprintf(cmd, "FETCH 1 BODY[HEADER]\r\n");
    SSL_write(ssl, cmd, strlen(cmd));

    // Read response to FETCH command
    bytes = SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Close SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);

    // Close TCP socket
    close(sock);

    // Clean up SSL library
    SSL_CTX_free(ctx);
    ERR_free_strings();
    EVP_cleanup();
    return 0;
}