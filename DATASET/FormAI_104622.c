//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    char *host = "www.google.com";
    char *path = "/";
    int port = 80;
    char request[1024];
    int client_socket;
    struct sockaddr_in server_address;
    
    // Create client socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // Set server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }
    
    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }
    
    // Send HTTP request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:87.0) Gecko/20100101 Firefox/87.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nConnection: close\r\n\r\n", path, host);
    if (send(client_socket, request, strlen(request), 0) < 0) {
        perror("Send request error");
        exit(EXIT_FAILURE);
    }
    
    // Receive HTTP response
    int response_length = 4096;
    char response[response_length];
    int num_bytes;
    while ((num_bytes = read(client_socket, response, response_length)) > 0) {
        fwrite(response, 1, num_bytes, stdout);
    }
    if (num_bytes < 0) {
        perror("Receive response error");
        exit(EXIT_FAILURE);
    }
    
    close(client_socket);
    
    return 0;
}