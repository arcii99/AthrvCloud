//FormAI DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int client_sock = 0;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error\n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    if (connect(client_sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Connection Failed\n"); 
        return -1;
    }

    printf("Connected to server\n");

    while(1)
    {
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);

        if(message[0] == '\n') { continue; } // Empty message, prompt again

        message[strcspn(message, "\n")] = 0; // Remove trailing newline

        send(client_sock, message, strlen(message), 0); // Send message to server

        if(strncmp(message, "exit", 4) == 0) { break; } // If client sends "exit", exit the loop

        memset(buffer, 0, sizeof(buffer)); // Clear buffer

        if(read(client_sock, buffer, BUFFER_SIZE) <= 0) // Read response from server
        {
            printf("Server disconnected\n");
            break;
        } 

        printf("Server response: %s\n", buffer); // Print response from server
    }

    printf("Closing connection\n");
    close(client_sock); // Close socket

    return 0;
}