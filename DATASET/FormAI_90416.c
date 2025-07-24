//FormAI DATASET v1.0 Category: Networking ; Style: Cryptic
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
 
#define BUFFER_SIZE 1024
#define PORT_NUMBER 9191 

int main() { 
    int server_socket; 
    struct sockaddr_in server_address; 
    char data[BUFFER_SIZE], encryptedData[BUFFER_SIZE], decryptedData[BUFFER_SIZE];
    
    // Creating the server socket 
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Defining the server socket address 
    bzero((char *) &server_address, sizeof(server_address)); 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); 
    server_address.sin_port = htons(PORT_NUMBER); 
    
    // Bind the server socket to the server address 
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) { 
        perror("Socket binding failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming client connections 
    if (listen(server_socket, 5) == -1) { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Server started, waiting for incoming connections...\n");
    
    while(1) { 
        int client_socket; 
        struct sockaddr_in client_address; 
        socklen_t client_address_length = sizeof(client_address); 
        
        // Accepting the incoming client connection 
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length)) == -1) { 
            perror("Accepting connection failed"); 
            exit(EXIT_FAILURE); 
        } 
        
        printf("Incoming connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port)); 
        
        // Receive data from the client 
        if (recv(client_socket, data, BUFFER_SIZE, 0) == -1) { 
            perror("Data receiving failed"); 
            exit(EXIT_FAILURE); 
        }
        
        printf("Encrypted data received: %s\n", data);
        
        // Decrypt the received data
        int i = 0; 
        while(data[i]) { 
            encryptedData[i] = data[i] - 3; 
            i++; 
        } 
        encryptedData[i] = '\0';
        
        printf("Decrypted data: %s\n", encryptedData);
        
        // Encrypt the data to be sent back to the client 
        i = 0; 
        while(encryptedData[i]) { 
            decryptedData[i] = encryptedData[i] + 3; 
            i++; 
        } 
        decryptedData[i] = '\0';
        
        // Send the encrypted data back to the client 
        if (send(client_socket, decryptedData, strlen(decryptedData), 0) == -1) {
            perror("Data sending failed"); 
            exit(EXIT_FAILURE); 
        } 
        
        printf("Data sent back to the client: %s\n", decryptedData);
        
        close(client_socket); 
    } 
    
    close(server_socket); 
    return 0; 
}