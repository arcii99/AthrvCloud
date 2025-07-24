//FormAI DATASET v1.0 Category: Networking ; Style: excited
// I am so excited to share this C Networking example program with you!

#include <stdio.h>      // Standard Input-Output library
#include <stdlib.h>     // Standard library with general functions (e.g., dynamic memory allocation)
#include <string.h>     // String manipulation functions
#include <sys/socket.h> // Socket library
#include <arpa/inet.h>  // IP address conversion library
#include <unistd.h>     // POSIX library for operating system interaction (e.g., close())
#include <errno.h>      // Error handling library

#define PORT 8080       // Port number for our server

void handle_error(const char* message) {
    // This function will handle any error that might occur during the program
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int sock = 0, valread;                  // Variables for socket and bytes received
    struct sockaddr_in serv_addr;           // Address structure for the server
    char hello[] = "Hello from client!";    // Message we will send to the server
    char buffer[1024] = {0};                // Buffer to store the message we will receive from the server

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    // Set up the server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        handle_error("Invalid address/ Address not supported");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Connection failed");
    }

    // Send the message to the server
    send(sock, hello, strlen(hello), 0);
    printf("Message sent to the server: %s\n", hello);

    // Receive the message from the server
    valread = read(sock, buffer, 1024);
    printf("Message received from the server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}