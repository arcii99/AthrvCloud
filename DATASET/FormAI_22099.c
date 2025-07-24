//FormAI DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *html = "<html><head><title>Medieval Web Page</title></head><body><h1>Welcome to My Castle!</h1><p>Our knights will be happy to serve you.</p></body></html>";
    char buffer[1024] = {0};
    int valread;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Failed to create socket\n");
        return -1;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("Failed to set socket options\n");
        return -1;
    }

    // Set socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0)
    {
        printf("Failed to bind socket\n");
        return -1;
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0)
    {
        printf("Failed to listen for connections\n");
        return -1;
    }

    printf("Medieval Web Server started on port %d...\n", PORT);

    while (1)
    {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            printf("Failed to accept connection\n");
            return -1;
        }

        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Read data from client
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);

        // Send response to client's request
        char header[1024] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        write(new_socket, header, strlen(header));
        write(new_socket, html, strlen(html));

        // Close socket
        close(new_socket);
    }

    return 0;
}