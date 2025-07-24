//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_SERVER "imap.gmail.com"
#define IMAP_PORT 993

#define BUFFER_SIZE 1024

#define LOGIN_USERNAME "username@gmail.com"
#define LOGIN_PASSWORD "password"

int main(int argc, char *argv[]) {

    // Connect to IMAP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
    }
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(IMAP_SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(IMAP_PORT);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
    }

    // Initialize SSL
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        perror("Error connecting with SSL");
    }

    // Login
    char buffer[BUFFER_SIZE];
    int nread = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (nread < 0) {
        perror("Error reading from server");
    }
    char login_string[BUFFER_SIZE];
    sprintf(login_string, "LOGIN %s %s\r\n", LOGIN_USERNAME, LOGIN_PASSWORD);
    nread = SSL_write(ssl, login_string, strlen(login_string));
    if (nread < 0) {
        perror("Error writing to server");
    }
    nread = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (nread < 0) {
        perror("Error reading from server");
    }
    printf("%.*s\n", nread, buffer);

    // List mailboxes
    char list_string[BUFFER_SIZE];
    sprintf(list_string, "LIST \"\" *\r\n");
    nread = SSL_write(ssl, list_string, strlen(list_string));
    if (nread < 0) {
        perror("Error writing to server");
    }
    nread = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (nread < 0) {
        perror("Error reading from server");
    }
    printf("%.*s\n", nread, buffer);

    // Logout
    char logout_string[BUFFER_SIZE];
    sprintf(logout_string, "LOGOUT\r\n");
    nread = SSL_write(ssl, logout_string, strlen(logout_string));
    if (nread < 0) {
        perror("Error writing to server");
    }
    nread = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (nread < 0) {
        perror("Error reading from server");
    }
    printf("%.*s\n", nread, buffer);

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);

    return 0;
}