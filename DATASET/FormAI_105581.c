//FormAI DATASET v1.0 Category: Networking ; Style: satisfied
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int client_socket = 0; 
    struct sockaddr_in server_address; 
    char message[200]; 
    char server_response[1024]; 
  
    // Creating a socket 
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
  
    memset(&server_address, '0', sizeof(server_address)); 
  
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 
      
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
  
    // Connect to the server 
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    printf("Connected to the Server.\n");

    while(1) {
        memset(&message, 0, sizeof(message));
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
   
        // Send the message to server 
        if(send(client_socket, message, strlen(message), 0) < 0) 
        { 
            printf("\nSend failed\n"); 
            return -1; 
        } 
   
        // Receive the server response 
        if(recv(client_socket, server_response, 1024, 0) < 0) 
        { 
            printf("\nReceive failed\n"); 
        }

        printf("Server response: %s\n", server_response);
    }

    return 0; 
}