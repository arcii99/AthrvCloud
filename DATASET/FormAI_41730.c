//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 2048

int main(int argc, char **argv) {
    SSL_CTX *ctx;
    SSL *ssl;
    int server_socket, result;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    // Initialize OpenSSL library
    SSL_library_init();
    SSL_load_error_strings();

    // Set up SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        printf("Error creating SSL context");
        exit(1);
    }

    // Load root CA certificates
    if (!SSL_CTX_load_verify_locations(ctx, "/etc/ssl/certs/ca-certificates.crt", NULL)) {
        printf("Error loading root CA certificates");
        exit(1);
    }

    // Create TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0) {
        printf("Error creating socket");
        exit(1);
    }

    // Set up server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("mail.example.com");
    server.sin_port = htons(993);

    // Connect to server
    result = connect(server_socket, (struct sockaddr *) &server, sizeof(server));
    if (result < 0) {
        printf("Error connecting to server");
        exit(1);
    }

    // Set up SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, server_socket);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    // Initiate SSL handshake
    result = SSL_connect(ssl);
    if (result != 1) {
        printf("Error establishing SSL connection, error code: %d", result);
        exit(1);
    }

    // Enter username and password
    char username[BUF_SIZE/2], password[BUF_SIZE/2];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    username[strcspn(username, "\r\n")] = 0;
    password[strcspn(password, "\r\n")] = 0;

    // Construct and send login command
    sprintf(buffer, "A001 LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive response from server
    SSL_read(ssl, buffer, BUF_SIZE);

    // Check if login was successful
    if (strstr(buffer, "OK") == NULL) {
        printf("Error logging in, server response: %s", buffer);
        exit(1);
    }

    // Construct and send list command
    sprintf(buffer, "A002 LIST \"\" \"*\"\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive response from server
    SSL_read(ssl, buffer, BUF_SIZE);

    // Check if list command was successful
    if (strstr(buffer, "OK") == NULL) {
        printf("Error listing mails, server response: %s", buffer);
        exit(1);
    }

    // Parse mailbox list and display to user
    char *line = strtok(buffer, "\r\n");
    while (line != NULL) {
        if (strstr(line, "* LIST") != NULL) {
            // Extract mailbox name
            char *mailbox = strtok(line, "\"");
            mailbox = strtok(NULL, "\"");

            // Display mailbox name
            printf("%s\n", mailbox);
        }

        line = strtok(NULL, "\r\n");
    }

    // Construct and send logout command
    sprintf(buffer, "A003 LOGOUT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive response from server
    SSL_read(ssl, buffer, BUF_SIZE);

    // Close SSL connection and free resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(server_socket);

    return 0;
}