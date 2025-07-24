//FormAI DATASET v1.0 Category: Networking ; Style: Ken Thompson
/* Ken Thompson style network programming example */
/* A simple client-server program in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFF_SIZE 1024

int main() {

    int sockfd, new_sockfd, client_addr_len, bytes_received, bytes_sent;
    struct sockaddr_in serv_addr, client_addr;
    char recv_buff[MAX_BUFF_SIZE], send_buff[MAX_BUFF_SIZE];

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("ERROR: Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // bind the socket to a port and IP address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("ERROR: Unable to bind socket to port and IP address");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("ERROR: Unable to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // accept incoming connections
    client_addr_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (new_sockfd == -1) {
        perror("ERROR: Unable to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    printf("Incoming connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // receive data
    bytes_received = recv(new_sockfd, recv_buff, MAX_BUFF_SIZE, 0);
    if (bytes_received == -1) {
        perror("ERROR: Unable to receive data");
        exit(EXIT_FAILURE);
    }

    printf("Data received from client: %s\n", recv_buff);

    // send data
    strcpy(send_buff, "Hello, this is the server!");
    bytes_sent = send(new_sockfd, send_buff, strlen(send_buff), 0);
    if (bytes_sent == -1) {
        perror("ERROR: Unable to send data");
        exit(EXIT_FAILURE);
    }

    printf("Data sent to client: %s\n", send_buff);

    // close sockets and exit
    close(new_sockfd);
    close(sockfd);
    exit(EXIT_SUCCESS);
}