//FormAI DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) 
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char response[1024] = "Welcome traveler, what can we do for you?";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting server options
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to IP address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_fd, 3) < 0) 
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accepting new connection requests
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    
    // Communication loop
    while(1) 
    {
        printf("Listening for client input...\n");

        // Receive message from client
        int valread = read(new_socket, buffer, 1024);
        printf("Message received from client: %s\n", buffer);

        // Determine server response
        if (strncmp(buffer, "What is this place?", 18) == 0) 
        {
            strcpy(response, "This is the kingdom of King Arthur, where chivalry and honor reign supreme.");
        }
        else if (strncmp(buffer, "Who are you?", 12) == 0) 
        {
            strcpy(response, "I am a humble innkeeper, providing lodging and sustenance to weary travelers.");
        }
        else if (strncmp(buffer, "Can you recommend a place to visit?", 34) == 0) 
        {
            strcpy(response, "The majestic castle of Camelot is a must-see, where King Arthur and his knights reside.");
        }
        else if (strncmp(buffer, "Thank you", 9) == 0) 
        {
            strcpy(response, "You are most welcome. May your travels be safe and prosperous.");
        }
        else 
        {
            strcpy(response, "I'm sorry, I don't understand. Please ask me a different question.");
        }

        // Send response to client
        send(new_socket, response, strlen(response), 0);
    }
    return 0;
}