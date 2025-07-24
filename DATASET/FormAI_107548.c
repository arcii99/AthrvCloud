//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>              // for printf() and scanf()
#include <stdlib.h>             // for exit()
#include <string.h>             // for memset()
#include <errno.h>              // for errno
#include <unistd.h>             // for close()
#include <arpa/inet.h>          // for sockaddr_in and inet_addr()
#include <sys/socket.h>         // for socket(), bind(), and connect()
#include <netinet/in.h>         // for IPPROTO_TCP, sockaddr_in, and in_addr

#define PORT 8080               // port to proxy server

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        exit(1);
    }
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);                 // create a client socket
    if (client_socket == -1) {
        printf("Failed to create socket : %s\n", strerror(errno));
        exit(1);
    }

    // specify a server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &server_address.sin_addr) == 0) {
        printf("Invalid IP address : %s\n", argv[1]);
        exit(1);
    }

    // connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect : %s\n", strerror(errno));
        exit(1);
    }

    char request[1000], response[1000000];
    while (1) {
        printf("Enter the URL : ");
        fflush(stdout);                 // flush the output buffer
        memset(request, 0, sizeof(request));
        memset(response, 0, sizeof(response));
        scanf("%s", request);
        if (strlen(request) == 1 && request[0] == 'q') break;         // exit loop when user types 'q'
        send(client_socket, request, strlen(request), 0);             // send HTTP request to server
        recv(client_socket, response, sizeof(response), 0);           // receive HTTP response from server
        printf("%s\n", response);                                      // print the response
    }

    close(client_socket);                                               // close the client socket
    return 0;
}