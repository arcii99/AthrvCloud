//FormAI DATASET v1.0 Category: Client Server Application ; Style: immersive
// Welcome to our immersive C Client Server Application!
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the port number to be used by this program
#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from the server-side!";

    // Create the socket file descriptor and check for errors
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options to allow reusing the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set the IP and port numbers of the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the server address and check for errors
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connection requests from clients and check for errors
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection requests from clients and handle each request
    while (1)
    {
        // Wait for incoming connection requests
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Read the message sent by the client and print it to the console
        valread = read(new_socket, buffer, 1024);
        printf("Received message from client: %s\n", buffer);

        // Send a response message back to the client
        send(new_socket, hello, strlen(hello), 0);
        printf("Response sent to client.\n");

        // Close the socket connection with the client
        close(new_socket);
    }

    // Close the socket connection with the server
    close(server_fd);

    return 0;
}