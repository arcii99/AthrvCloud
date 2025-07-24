//FormAI DATASET v1.0 Category: Email Client ; Style: distributed
/* A Distributed Email Client in C */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define SERVER_PORT 9999 
#define MAX_MESSAGE_SIZE 1024 

int main(int argc, char *argv[]) { 
    // create a socket 
    int client_socket = socket(AF_INET, SOCK_STREAM, 0); 
    if (client_socket < 0) { 
        printf("Failed to create socket!\n"); 
        exit(1); 
    } 

    // specify the server address 
    struct sockaddr_in server_address; 
    memset(&server_address, 0, sizeof(server_address)); 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server_address.sin_port = htons(SERVER_PORT); 

    // connect to server 
    if (connect(client_socket, (const struct sockaddr *)&server_address, sizeof(server_address)) < 0) { 
        printf("Failed to connect to server!\n"); 
        exit(1); 
    } 

    // send a message to server 
    char message[MAX_MESSAGE_SIZE]; 
    memset(message, 0, sizeof(message)); 
    printf("Please input the email message:\n"); 
    fgets(message, MAX_MESSAGE_SIZE-1, stdin); 
    write(client_socket, message, strlen(message)); 

    // receive the reply from server 
    char reply[MAX_MESSAGE_SIZE]; 
    memset(reply, 0, sizeof(reply)); 
    read(client_socket, reply, sizeof(reply)); 
    printf("The server replied: %s\n", reply); 

    // close the socket 
    close(client_socket); 

    return 0; 
}