//FormAI DATASET v1.0 Category: Firewall ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080 // Port number to listen on
#define MAX_CONNECTIONS 10 // Maximum number of connections
#define BUFFER_SIZE 1024 // Maximum number of bytes to receive in a single read

// Function to check if a string is a valid IP address
int is_valid_ip(char *ip_address)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    return result != 0;
}

int main()
{
    char buffer[BUFFER_SIZE]; // Buffer to receive data in
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create the socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Set the socket address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on port %d...\n", PORT);
    
    // Loop indefinitely to handle incoming connections
    while (1)
    {
        // Accept a new incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        
        // Read data from the socket
        valread = read(new_socket, buffer, BUFFER_SIZE);
        
        // Check if the data is a valid IP address
        if (is_valid_ip(buffer))
        {
            printf("%s is a valid IP address\n", buffer);
            // Send an acknowledgement message to the client
            send(new_socket, "Acknowledged", strlen("Acknowledged"), 0);
        }
        else
        {
            printf("%s is not a valid IP address\n", buffer);
            // Send an error message to the client
            send(new_socket, "Error: Invalid IP address", strlen("Error: Invalid IP address"), 0);
        }
        
        // Close the socket
        close(new_socket);
        printf("Connection closed\n");
    }
    
    return 0;
}