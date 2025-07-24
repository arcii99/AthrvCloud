//FormAI DATASET v1.0 Category: Socket programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[]) 
{ 
    int client_socket = 0;
    struct sockaddr_in server_address; 

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    memset(&server_address, '0', sizeof(server_address)); 

    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 

    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    char message[1024] = {0};
    printf("Enter a message: ");
    fgets(message, 1024, stdin);

    if( send(client_socket , message , strlen(message) , 0) < 0) 
    { 
        printf("\nSend failed \n"); 
        return -1; 
    } 

    char buffer[1024] = {0}; 
    if(read(client_socket, buffer, 1024) < 0)
    { 
        printf("\nRead failed \n"); 
        return -1; 
    } 

    printf("Server response: %s\n",buffer ); 

    return 0; 
}