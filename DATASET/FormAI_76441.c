//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
#include<sys/socket.h> 
#include<arpa/inet.h> 
#include<unistd.h> 

#define PORT 8080 

int main() 
{ 

    char server_message[2000]; 
  
    // Create socket 
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); 
    if (server_socket == -1) 
    { 
        printf("Could not create socket"); 
        return -1; 
    } 
    printf("Socket created.\n"); 

    // Define the server address and port 
    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); 
  
    // Bind the socket to our specified ip and port 
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        perror("bind failed. Error"); 
        return -1; 
    } 
    printf("Socket bound.\n"); 

    // Listen for incoming connections 
    listen(server_socket, 5); 
    printf("Listening for incoming connections...\n"); 
  
    // Accept connections 
    int client_socket = accept(server_socket, NULL, NULL); 
    if (client_socket < 0) 
    { 
        perror("accept failed"); 
        return -1; 
    } 
    printf("Connection accepted.\n"); 

    // Send message to client 
    strcpy(server_message, "Welcome to the server!"); 
    send(client_socket, server_message, sizeof(server_message), 0); 
    printf("Message sent to client.\n"); 
    
    // Receive message from client 
    char client_message[2000]; 
    recv(client_socket, client_message, sizeof(client_message), 0); 
    printf("Client message received: %s\n", client_message); 

    // Close the sockets 
    close(server_socket); 
    close(client_socket); 
    
    return 0; 
}