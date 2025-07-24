//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define HOST "imap.gmail.com"
#define PORT "993"

int main() {
    printf("Welcome to the IMAP Client program! Let's get started...\n");

    //Create a socket
    int socket_desc;
    struct sockaddr_in server_addr;
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }
    
    //Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(HOST);
    server_addr.sin_port = htons(atoi(PORT));

    //Connect to server
    if (connect(socket_desc, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    printf("Connected to server %s on port %s\n", HOST, PORT);

    //Initialize SSL connection
    SSL_CTX* ctx = SSL_CTX_new(TLSv1_2_client_method());
    SSL* ssl;
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, socket_desc);

    //Connect SSL
    if (SSL_connect(ssl) != 1) {
        printf("Error: Could not establish secure connection\n");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        exit(1);
    }

    printf("Secure connection established using %s\n", SSL_get_cipher(ssl));

    //Login to IMAP server
    char buffer[1024];
    char username[50], password[50];
    printf("Please enter your username: ");
    fgets(username, 50, stdin);
    printf("Please enter your password: ");
    fgets(password, 50, stdin);
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    //Select INBOX folder
    SSL_write(ssl, "SELECT INBOX\r\n", strlen("SELECT INBOX\r\n"));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    //List all emails in INBOX
    SSL_write(ssl, "FETCH 1:* (BODY[HEADER.FIELDS (SUBJECT FROM)])\r\n", strlen("FETCH 1:* (BODY[HEADER.FIELDS (SUBJECT FROM)])\r\n"));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    //Logout and close SSL connection
    SSL_write(ssl, "LOGOUT\r\n", strlen("LOGOUT\r\n"));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    close(socket_desc);

    printf("Program terminated. Goodbye!\n");

    return 0;
}