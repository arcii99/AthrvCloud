//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 80

int main(int argc, char *argv[]) {
    
    struct sockaddr_in server_addr;
    int sock = 0, bytes_read = 0;
    char buffer[2048] = {0};
    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }
    
    // Set up server address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "93.184.216.34", &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return EXIT_FAILURE;
    }
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }
    
    // Send request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Send failed");
        return EXIT_FAILURE;
    }
    
    // Receive response
    while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0) {
        printf("%.*s", bytes_read, buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    
    if (bytes_read < 0) {
        perror("Read failed");
        return EXIT_FAILURE;
    }
    
    close(sock);
    
    return EXIT_SUCCESS;
}