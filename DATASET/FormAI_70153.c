//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define MAX_BUFFER_SIZE 1024

void print_error(const char *msg) {
    fprintf(stderr, "[ERROR] %s\n", msg);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_error("Usage: ./imap_client <server_address> <username>");
        return 1;
    }

    const char *server_address = argv[1];
    const char *username = argv[2];
    char *password = NULL;
    size_t password_len = 0;
    ssize_t read_password_len = 0;

    printf("Password: ");
    read_password_len = getline(&password, &password_len, stdin);
    if (read_password_len <= 0) {
        print_error("Invalid password");
        return 1;
    }
    password[read_password_len - 1] = '\0'; // Remove newline character

    SSL_load_error_strings();
    SSL_library_init();

    SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ssl_ctx) {
        print_error("Failed to create SSL context");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        print_error("Failed to create socket");
        return 1;
    }

    struct hostent *host = gethostbyname(server_address);
    if (!host) {
        print_error("No such host");
        return 1;
    }

    struct sockaddr_in server_address_in;
    bzero(&server_address_in, sizeof(server_address_in));
    server_address_in.sin_family = AF_INET;
    server_address_in.sin_port = htons(IMAP_PORT);
    server_address_in.sin_addr = *((struct in_addr*) host->h_addr);

    if (connect(sockfd, (struct sockaddr*) &server_address_in, sizeof(server_address_in)) < 0) {
        print_error("Failed to connect to server");
        return 1;
    }

    SSL *ssl = SSL_new(ssl_ctx);
    if (!ssl) {
        print_error("Failed to create SSL object");
        return 1;
    }

    if (SSL_set_fd(ssl, sockfd) == 0) {
        print_error("Failed to set SSL file descriptor");
        return 1;
    }

    if (SSL_connect(ssl) != 1) {
        print_error("Failed to establish SSL connection");
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];

    // Send LOGIN command
    snprintf(buffer, MAX_BUFFER_SIZE, "LOGIN %s \"%s\"\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));

    // Read response
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);
    
    // Send LIST command to get list of mailboxes
    SSL_write(ssl, "LIST \"\" \"*\"\n", strlen("LIST \"\" \"*\"\n"));

    // Read response
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    free(password);

    close(sockfd);

    return 0;
}