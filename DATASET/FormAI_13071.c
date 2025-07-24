//FormAI DATASET v1.0 Category: Socket programming ; Style: future-proof
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
 
#define PORT 8000 
#define MAX_CLIENTS 50 

int main(int argc, char const *argv[]) 
{ 
    int sockfd, new_socket, valread; 
    struct sockaddr_in serveraddr, clientaddr; 
    int addrlen = sizeof(serveraddr); 
    char buffer[1024] = {0}; 
    char welcome_message[1024] = "Welcome to the C Socket Chatbot!"; 

    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set socket options 
    int opt = 1; 
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Prepare the sockaddr_in structure 
    serveraddr.sin_family = AF_INET; 
    serveraddr.sin_addr.s_addr = INADDR_ANY; 
    serveraddr.sin_port = htons( PORT ); 
    
    // Bind the socket to create a named socket 
    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listen for incoming connections 
    if (listen(sockfd, MAX_CLIENTS) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    // Accept incoming connections 
    int num_clients = 0; 
    int client_sockets[MAX_CLIENTS]; 
    for (int i=0; i<MAX_CLIENTS; i++) 
    { 
        client_sockets[i] = 0; 
    } 
    while(1) 
    { 
        if ((new_socket = accept(sockfd, (struct sockaddr *)&clientaddr, 
                                (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 
        
        // Add client socket to array 
        for (int i=0; i<MAX_CLIENTS; i++) 
        { 
            if (client_sockets[i] == 0) 
            { 
                client_sockets[i] = new_socket; 
                num_clients++; 
                break; 
            } 
        } 

        // Send welcome message to new client 
        send(new_socket, welcome_message, strlen(welcome_message), 0); 

        // Handle communication with client 
        while(1) 
        { 
            valread = read(new_socket, buffer, 1024); 
            if(valread == 0) 
            { 
                printf("Client disconnected\n"); 
                break; 
            } 
            buffer[valread] = '\0'; // add null terminator to end of message 

            // Echo message to all clients connected 
            for (int i=0; i<num_clients; i++) 
            { 
                if (client_sockets[i] != new_socket) 
                { 
                    send(client_sockets[i], buffer, strlen(buffer), 0); 
                } 
            } 
        } 

        // Remove client socket from array 
        for (int i=0; i<MAX_CLIENTS; i++) 
        { 
            if (client_sockets[i] == new_socket) 
            { 
                client_sockets[i] = 0; 
                num_clients--; 
                break; 
            } 
        } 
    } 
    return 0; 
}