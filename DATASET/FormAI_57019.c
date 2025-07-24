//FormAI DATASET v1.0 Category: Socket programming ; Style: all-encompassing
/* A simple chat program between a client and server using Socket programming */

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) 
{ 
    int socket_fd, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 

    // Creating socket file descriptor 
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation failed \n"); 
        return -1; 
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    // Connect the socket to the server address 
    if (connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    // Send message to the server
    send(socket_fd , hello , strlen(hello) , 0 ); 

    // Read message from the server 
    valread = read( socket_fd , buffer, 1024); 
    printf("%s\n",buffer ); 
    
    // Keep sending and receiving messages until user inputs 'bye'
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer,1024,stdin); 
        send(socket_fd , buffer , strlen(buffer) , 0 ); 

        if(strncmp(buffer, "bye", 3)==0) {
            printf("User has disconnected from chat\n");
            break;
        }
        memset(buffer, 0, sizeof(buffer));
        valread = read(socket_fd , buffer, 1024); 
        printf("%s", buffer);
    }
    return 0; 
}