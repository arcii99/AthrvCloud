//FormAI DATASET v1.0 Category: Socket programming ; Style: retro
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char retro_msg[1024] = ""; 
    char *hello = "Welcome to Retro Chat!"; 
    char client_message[1024]; 

    // Create socket 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    // Send message to server 
    send(sock, hello, strlen(hello), 0 ); 
    printf("Welcome message sent\n"); 

    // Receive message from server 
    valread = read( sock , retro_msg, 1024); 
    printf("\n%s\n",retro_msg ); 

    // Chat loop
    while(1) 
    {   
        printf("You: ");
        memset(client_message, 0, 1024); 
        fgets(client_message, 1024, stdin); 

        // Send message to server 
        send(sock , client_message , strlen(client_message) , 0 ); 

        // Receive message from server 
        valread = read( sock , retro_msg, 1024); 
        
        if(strcmp(retro_msg, "The server has disconnected") == 0)
        {
            printf("\n%s\n", retro_msg);
            break;
        }

        printf("Server: %s\n", retro_msg);
    } 

    // Close socket
    close(sock); 
    return 0; 
}