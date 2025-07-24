//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

void printError(const char *message) {
    fprintf(stderr, "%s\n", message);
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
}

int main() {
    SSL_CTX *sslContext;
    SSL *sslConnection;
    int socketFd;
    struct sockaddr_in serverAddress;
    char buffer[BUFF_SIZE];

    // initialize the SSL library
    SSL_library_init();
    SSL_load_error_strings();

    // create a new SSL context object
    sslContext = SSL_CTX_new(TLS_method());

    // set the root certificates
    if (SSL_CTX_load_verify_locations(sslContext, NULL, "/etc/ssl/certs") == 0) {
        printError("Error: SSL_CTX_load_verify_locations");
    }

    // create a new socket
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1) {
        printError("Error: failed to create socket");
    }

    // set the server address
    memset(&serverAddress, '\0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(993);
    if (inet_pton(AF_INET, "imap.gmail.com", &serverAddress.sin_addr) != 1) {
        printError("Error: invalid address");
    }

    // connect to the server
    if (connect(socketFd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        printError("Error: failed to connect to server");
    }

    // create an SSL connection object and attach it to the socket
    sslConnection = SSL_new(sslContext);
    SSL_set_fd(sslConnection, socketFd);

    // establish SSL connection with server
    if (SSL_connect(sslConnection) != 1) {
        printError("Error: failed to establish SSL connection");
    }

    // send login credentials
    SSL_write(sslConnection, "LOGIN email@example.com password\r\n", strlen("LOGIN email@example.com password\r\n"));
    SSL_read(sslConnection, buffer, BUFF_SIZE);

    // select the INBOX mailbox
    SSL_write(sslConnection, "SELECT INBOX\r\n", strlen("SELECT INBOX\r\n"));
    SSL_read(sslConnection, buffer, BUFF_SIZE);

    // search for all unread messages
    SSL_write(sslConnection, "SEARCH UNSEEN\r\n", strlen("SEARCH UNSEEN\r\n"));
    SSL_read(sslConnection, buffer, BUFF_SIZE);

    // logout and close the connection
    SSL_write(sslConnection, "LOGOUT\r\n", strlen("LOGOUT\r\n"));
    SSL_shutdown(sslConnection);
    close(socketFd);

    SSL_CTX_free(sslContext);

    return 0;
}