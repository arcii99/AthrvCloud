//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 4096

/* Helper function to print socket error message */
void print_socket_error(const char *error)
{
    perror(error);
    exit(1);
}

/* Function to send HTTP request and print response */
void send_http_request(char *server_address, int port, char *request)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFF_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        print_socket_error("ERROR: Unable to create socket");

    // Set server address and port
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_address, &serv_addr.sin_addr) <= 0) 
        print_socket_error("ERROR: Invalid server address");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        print_socket_error("ERROR: Unable to connect to server");

    // Send HTTP request
    if (write(sockfd, request, strlen(request)) < 0)
        print_socket_error("ERROR: Unable to send message to server");

    // Receive HTTP response and print
    while ((n = read(sockfd, buffer, MAX_BUFF_SIZE-1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    if (n < 0)
        print_socket_error("ERROR: Unable to receive message from server");

    // Close socket
    close(sockfd);
}

int main(int argc, char *argv[]) 
{
    char *server_address = "example.com";
    int port = 80;
    char request[MAX_BUFF_SIZE];
    
    // Create HTTP request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", server_address);

    // Send HTTP request and receive response
    send_http_request(server_address, port, request);

    return 0;
}