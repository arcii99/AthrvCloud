//FormAI DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response_message = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to my simple web server!</h1></body></html>";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening to incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started on port %d...\n", PORT);
    
    while(1)
    {
        // Accepting incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("accept");
        }
        else
        {
            printf("Connection established with %s:%d...\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // Reading HTTP request
            valread = read(new_socket, buffer, BUFFER_SIZE);
            printf("%s\n", buffer);

            // Sending HTTP response message
            send(new_socket, response_message, strlen(response_message), 0);
            printf("Response sent to %s:%d...\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // Closing connection
            close(new_socket);
            printf("Connection closed with %s:%d...\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        }
    }

    return 0;
}