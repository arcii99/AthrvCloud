//FormAI DATASET v1.0 Category: Email Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define MAX_RECIPIENTS 10
#define SMTP_PORT 587

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [recipient1@address.com],[recipient2@address.com],.. [subject]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    SSL_CTX *ctx;
    SSL *ssl;
    const SSL_METHOD *method;
    int sockfd, bytes_sent, bytes_received;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char username[BUF_SIZE], password[BUF_SIZE], hostname[BUF_SIZE], buffer[BUF_SIZE];
    char recipients[MAX_RECIPIENTS][BUF_SIZE], subject[BUF_SIZE], message[BUF_SIZE];
    memset(recipients, 0, sizeof recipients);

    // Get the email username and password
    printf("Enter your email address: ");
    fgets(username, BUF_SIZE, stdin);
    printf("Enter your password: ");
    fgets(password, BUF_SIZE, stdin);
    // Remove newline characters from input
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    // Get the SMTP server hostname
    printf("Enter the hostname of your email provider (e.g. smtp.gmail.com): ");
    fgets(hostname, BUF_SIZE, stdin);
    hostname[strcspn(hostname, "\n")] = 0;

    // Parse the recipient list and subject
    char *to = strtok(argv[1], ",");
    int i;
    for (i = 0; to != NULL && i < MAX_RECIPIENTS; i++) {
        strcpy(recipients[i], to);
        to = strtok(NULL, ",");
    }
    if (to != NULL && i >= MAX_RECIPIENTS) {
        printf("Only %d recipients are allowed.\n", MAX_RECIPIENTS);
        exit(EXIT_FAILURE);
    }
    strcpy(subject, argv[2]);

    // Get the message body from user input
    printf("Enter your message: ");
    fgets(message, BUF_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;

    // Initialize OpenSSL and create a new SSL context
    SSL_library_init();
    SSL_load_error_strings();
    method = TLSv1_2_client_method();
    ctx = SSL_CTX_new(method);
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Connect to the SMTP server
    server = gethostbyname(hostname);
    if (server == NULL) {
        error("Error: no such host");
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error: opening socket");
    }
    memset(&serv_addr, 0, sizeof serv_addr);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    serv_addr.sin_addr = *((struct in_addr*) server->h_addr);
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof serv_addr) < 0) {
        error("Error: connecting");
    }

    // Set up the SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Authenticate with the SMTP server
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    if (bytes_received < 0) {
        error("Error: reading from socket");
    }
    printf("%s\n", buffer);
    memset(buffer, 0, BUF_SIZE);
    bytes_sent = SSL_write(ssl, "EHLO client\r\n", strlen("EHLO client\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    if (bytes_received < 0) {
        error("Error: reading from socket");
    }
    printf("%s\n", buffer);
    memset(buffer, 0, BUF_SIZE);
    bytes_sent = SSL_write(ssl, "STARTTLS\r\n", strlen("STARTTLS\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    if (bytes_received < 0) {
        error("Error: reading from socket");
    }
    printf("%s\n", buffer);
    memset(buffer, 0, BUF_SIZE);
    SSL *tmp_ssl;
    tmp_ssl = SSL_new(ctx);
    SSL_set_fd(tmp_ssl, sockfd);
    SSL_set_connect_state(tmp_ssl);
    if (SSL_do_handshake(tmp_ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    if (!SSL_CTX_check_private_key(ctx)) {
        error("Error: private key does not match public key\n");
    }
    SSL_free(tmp_ssl);
    bytes_sent = SSL_write(ssl, "EHLO client\r\n", strlen("EHLO client\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    if (bytes_received < 0) {
        error("Error: reading from socket");
    }
    printf("%s\n", buffer);
    memset(buffer, 0, BUF_SIZE);
    bytes_sent = SSL_write(ssl, "AUTH LOGIN\r\n", strlen("AUTH LOGIN\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    if (bytes_received < 0) {
        error("Error: reading from socket");
    }
    printf("%s\n", buffer);
    memset(buffer, 0, BUF_SIZE);
    bytes_sent = SSL_write(ssl, username, strlen(username));
    bytes_sent = SSL_write(ssl, "\r\n", strlen("\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    if (bytes_received < 0) {
        error("Error: reading from socket");
    }
    printf("%s\n", buffer);
    memset(buffer, 0, BUF_SIZE);
    bytes_sent = SSL_write(ssl, password, strlen(password));
    bytes_sent = SSL_write(ssl, "\r\n", strlen("\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    if (bytes_received < 0) {
        error("Error: reading from socket");
    }
    printf("%s\n", buffer);
    memset(buffer, 0, BUF_SIZE);

    // Send email headers and message body
    bytes_sent = SSL_write(ssl, "MAIL FROM:<", strlen("MAIL FROM:<"));
    bytes_sent = SSL_write(ssl, username, strlen(username));
    bytes_sent = SSL_write(ssl, ">\r\n", strlen(">\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    for (i = 0; i < MAX_RECIPIENTS && strlen(recipients[i]) > 0; i++) {
        bytes_sent = SSL_write(ssl, "RCPT TO:<", strlen("RCPT TO:<"));
        bytes_sent = SSL_write(ssl, recipients[i], strlen(recipients[i]));
        bytes_sent = SSL_write(ssl, ">\r\n", strlen(">\r\n"));
        if (bytes_sent < 0) {
            error("Error: writing to socket");
        }
    }
    bytes_sent = SSL_write(ssl, "DATA\r\n", strlen("DATA\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    printf("%s\n", buffer);
    bytes_sent = SSL_write(ssl, "Subject: ", strlen("Subject: "));
    bytes_sent = SSL_write(ssl, subject, strlen(subject));
    bytes_sent = SSL_write(ssl, "\r\n", strlen("\r\n"));
    bytes_sent = SSL_write(ssl, "To: ", strlen("To: "));
    bytes_sent = SSL_write(ssl, recipients[0], strlen(recipients[0]));
    for (i = 1; i < MAX_RECIPIENTS && strlen(recipients[i]) > 0; i++) {
        bytes_sent = SSL_write(ssl, ", ", strlen(", "));
        bytes_sent = SSL_write(ssl, recipients[i], strlen(recipients[i]));
    }
    bytes_sent = SSL_write(ssl, "\r\n\r\n", strlen("\r\n\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_sent = SSL_write(ssl, message, strlen(message));
    bytes_sent = SSL_write(ssl, "\r\n.\r\n", strlen("\r\n.\r\n"));
    if (bytes_sent < 0) {
        error("Error: writing to socket");
    }
    bytes_received = SSL_read(ssl, buffer, BUF_SIZE);
    printf("%s\n", buffer);

    // Close the SSL connection and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return EXIT_SUCCESS;
}