//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993 // SSL IMAP port
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [server_address] [username] [password]\n", argv[0]);
        exit(0);
    }

    char *server_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Connect to server
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // Zero-fill server_addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    server_addr.sin_port = htons(IMAP_PORT);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Open SSL connection
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLS_method());
    if (!ssl_ctx) {
        perror("Error creating SSL context");
        exit(1);
    }
    SSL *ssl = SSL_new(ssl_ctx);
    if (!ssl) {
        perror("Error creating SSL object");
        exit(1);
    }
    SSL_set_fd(ssl, sock_fd);
    if (SSL_connect(ssl) <= 0) {
        perror("Error connecting SSL");
        exit(1);
    }

    // Read server banner
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer)); // Zero-fill buffer
    SSL_read(ssl, buffer, sizeof(buffer)-1);
    printf("%s", buffer);

    // Send login command
    char login_command[BUFFER_SIZE];
    memset(login_command, 0, sizeof(login_command)); // Zero-fill login_command
    sprintf(login_command, "LOGIN %s %s\n", username, password);
    SSL_write(ssl, login_command, strlen(login_command));

    // Read server response
    memset(buffer, 0, sizeof(buffer)); // Zero-fill buffer
    SSL_read(ssl, buffer, sizeof(buffer)-1);
    printf("%s", buffer);

    // Send list command
    SSL_write(ssl, "LIST \"\" *\n", 10);

    // Read server response containing mailbox list
    memset(buffer, 0, sizeof(buffer)); // Zero-fill buffer
    SSL_read(ssl, buffer, sizeof(buffer)-1);
    printf("%s", buffer);

    // Close connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sock_fd);

    return 0;
}