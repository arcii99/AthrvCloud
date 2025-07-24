//FormAI DATASET v1.0 Category: Socket programming ; Style: enthusiastic
// Hello adventurous programmer! 
// Get ready to embark on the journey of C Socket programming!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_MSG_LENGTH 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_MSG_LENGTH] = {0};
    char *greetings = "Hello from the server!";

    // Create server socket descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Server socket creation failed.");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Server socket binding failed.");
        return -1;
    }

    // Listen to clients
    if (listen(server_fd, 3) < 0)
    {
        printf("Server socket listen failed.");
        return -1;
    }

    printf("Listening for incoming requests...\n");
    while (1)
    {
        // Accept connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            printf("Server socket accept failed.");
            return -1;
        }

        // Read from client
        valread = read(new_socket, buffer, MAX_MSG_LENGTH);
        printf("Received message from client: %s\n", buffer);

        // Send back a greeting to client
        send(new_socket, greetings, strlen(greetings), 0);
        printf("Greeting sent to the client!\n");

        // Close the socket
        close(new_socket);
    }

    return 0;
}