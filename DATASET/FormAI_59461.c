//FormAI DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <unistd.h>  

#define MAX_MSG_LEN 200  

void handle_client(int client_socket);  

int main(int argc, char *argv[])  
{  
    int server_socket, client_socket, port_number;  
    struct sockaddr_in server_address, client_address;  
    char message[MAX_MSG_LEN];  

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);  
    if (server_socket == -1)  
    {  
        printf("Failed to create server socket.");  
        return 1;  
    }  
      
    // Set server address
    server_address.sin_family = AF_INET;  
    server_address.sin_addr.s_addr = INADDR_ANY;  
    server_address.sin_port = htons(8888);  

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)  
    {  
        printf("Failed to bind server socket.");  
        return 1;  
    }  

    // Listen for incoming connections
    listen(server_socket, 3);  
    
    // Accept incoming connections and handle them
    while(1)  
    {  
        printf("\nWaiting for incoming connections...\n");  
        int client_address_length = sizeof(client_address);  
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length);  
        if (client_socket < 0)  
        {  
            printf("Failed to accept client connection.");  
            return 1;  
        }  
        
        printf("New client connected.\n");
        handle_client(client_socket);
    }  
    
    return 0;  
}  

void handle_client(int client_socket)  
{  
    char name[MAX_MSG_LEN];  
    char message[MAX_MSG_LEN];  
    char client_reply[MAX_MSG_LEN];  
        
    // Get player's name
    read(client_socket, name, MAX_MSG_LEN);  
    printf("%s has joined the game.\n", name);  
    write(client_socket, "Welcome to the game!\n", strlen("Welcome to the game!\n") + 1);  
    
    // Game logic
    while(1)  
    {  
        // Get player's message
        read(client_socket, message, MAX_MSG_LEN);  
        printf("%s says: %s\n", name, message);  

        // Check if player wants to quit
        if(strncmp(message, "QUIT", 4) == 0)  
        {  
            printf("%s has quit the game.\n", name);  
            break;  
        }  
        
        // Echo back player's message
        sprintf(client_reply, "%s says: %s", name, message);  
        write(client_socket, client_reply, strlen(client_reply) + 1);  
    }  
    
    // Close client socket
    close(client_socket);  
}