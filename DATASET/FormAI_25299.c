//FormAI DATASET v1.0 Category: Socket programming ; Style: visionary
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080 /* Port number */

int main(int argc, char const *argv[]) 
{ 
    int client_socket; 
    struct sockaddr_in server_address; 

    /* Creating socket file descriptor */
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    memset(&server_address, '0', sizeof(server_address)); 

    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 

    /* Convert IPv4 and IPv6 addresses from text to binary form */
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    /* Connect to the server */ 
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    char message[1024] = {0};
    char buffer[1024] = {0};

    printf("Enter a message to send to the server: ");
    fgets(message, 1024, stdin);

    /* Send the message to the server */
    send(client_socket, message, strlen(message), 0);

    printf("Message Sent!\n");

    /* Receive the message from the server */
    read(client_socket, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    /* Close the socket */
    close(client_socket);

    return 0; 
}