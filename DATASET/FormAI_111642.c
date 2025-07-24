//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 80 // HTTP Port
#define MAX_BUFFER_SIZE 1024 // Maximum Buffer Size

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Usage: %s <IP Address or domain name>\n", argv[0]);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0); // Create a Socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) { // Try to connect to the server
        perror("Connection failed");
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE]; // Create a buffer for the response
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]); // Send HTTP GET request to the server
    send(sock, buffer, strlen(buffer), 0);

    while (1) { // Loop until all data is received
        int bytes_received = recv(sock, buffer, MAX_BUFFER_SIZE - 1, 0);
        if (bytes_received < 0) { // Error in receiving data
            perror("Error in receiving data");
            exit(1);
        }
        if (bytes_received == 0) break; // All data is received
        buffer[bytes_received] = '\0'; // Append a null character at the end of the buffer
        printf("%s", buffer); // Print the received data on the screen
    }

    close(sock); // Close the socket
    return 0;
}