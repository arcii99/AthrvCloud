//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void handle_error(const char *msg);

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
  
    // create SSL context
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
  
    // load root cert
    if (!SSL_CTX_load_verify_locations(ctx, "/etc/ssl/certs/ca-certificates.crt", NULL)) {
        handle_error("Error loading root cert");
    }
  
    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Error creating socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(995); // secure POP3 port
    if (inet_aton("pop3.example.com", &server_addr.sin_addr) == 0) {
        handle_error("Error converting address");
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        handle_error("Error connecting to server");
    }

    // create SSL object and attach to socket
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
  
    // perform SSL handshake
    if ((ret = SSL_connect(ssl)) != 1) {
        handle_error("Error performing SSL handshake");
    }

    // read welcome message
    memset(buffer, 0, BUFFER_SIZE);
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // authenticate with user/pass
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    SSL_write(ssl, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    SSL_read(ssl, buffer, BUFFER_SIZE);

    if (strncmp(buffer, "+OK", 3) != 0) {
        handle_error("Error sending username");
    }

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    SSL_write(ssl, buffer, strlen(buffer));

    memset(buffer, 0, BUFFER_SIZE);
    SSL_read(ssl, buffer, BUFFER_SIZE);

    if (strncmp(buffer, "+OK", 3) != 0) {
        handle_error("Error sending password");
    }

    // list messages
    memset(buffer, 0, BUFFER_SIZE);
    SSL_write(ssl, "LIST\r\n", 6);
    SSL_read(ssl, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // quit
    SSL_write(ssl, "QUIT\r\n", 6);
    SSL_read(ssl, buffer, BUFFER_SIZE);

    // cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}

void handle_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}