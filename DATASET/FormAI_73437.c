//FormAI DATASET v1.0 Category: Socket programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int create_socket() {
    int sock;
    struct sockaddr_in server_address;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed!");
        exit(1);
    }
    
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    server_address.sin_port = htons(8080);
    
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }
    
    return sock;
}

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;
    
    method = TLSv1_2_client_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        perror("Failed to create SSL context");
        exit(1);
    }
    
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    SSL_CTX_set_ecdh_auto(ctx, 1);
}

void do_communication(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    memset(buffer, 0, BUFFER_SIZE);
    
    SSL_write(ssl, "Hello Server!", strlen("Hello Server!"));
    bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (bytes_read > 0) {
        printf("Received from server: %s\n", buffer);
    }
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int server_socket;
    
    init_openssl();
    ctx = create_context();
    configure_context(ctx);
    
    server_socket = create_socket();
    
    ssl = SSL_new(ctx);
    if (!ssl) {
        printf("Failed to create SSL object\n");
        exit(1);
    }
    
    SSL_set_fd(ssl, server_socket);
    
    if (SSL_connect(ssl) <= 0) {
        perror("SSL Connection failed");
        exit(1);
    }
    
    do_communication(ssl);
    
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(server_socket);
    SSL_CTX_free(ctx);
    cleanup_openssl();
    
    return 0;
}