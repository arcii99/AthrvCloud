//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
/* Romeo and Juliet Simple Web Server Example Program */
/* Written by: Juliet */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    printf("O Romeo, O Romeo, wherefore art thou web server?\n");
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        printf("Alack, there was an error creating the socket!\n");
        return -1;
    }
    printf("The socket was created successfully!\n");

    // Bind socket to port
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    memset(&address, 0, addrlen);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0)
    {
        printf("My only love, there was an error binding the socket to the port.\n");
        return -1;
    }
    printf("The socket was successfully bound to port 8080!\n");

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        printf("Oh, happy dagger! There was an error listening for incoming connections.\n");
        return -1;
    }
    printf("The server is now listening for incoming connections!\n");

    while(1)
    {
        // Accept incoming connection
        int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_fd < 0)
        {
            printf("My bounty is as boundless as the sea, and yet there was an error accepting the incoming connection.\n");
            continue;
        }
        printf("There has been an incoming connection. Hark!\n");

        // Read incoming request
        char buffer[1024] = {0};
        read(client_fd, buffer, 1024);
        printf("The request received was: %s\n", buffer);

        // Send response
        char *message = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>O happy dagger!</h1><p>This is the response from the web server!</p></body></html>";
        send(client_fd, message, strlen(message), 0);
        printf("Response sent!\n");

        // Close client connection
        close(client_fd);
        printf("Connection closed.\n");
    }

    return 0;
}