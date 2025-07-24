//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define BUFFER_SIZE 1024
 
int main(int argc, char *argv[]) 
{ 
    int sock; 
    struct sockaddr_in server_addr; 
    char message[BUFFER_SIZE], server_reply[BUFFER_SIZE]; 
     
    // Create the socket 
    sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock == -1) { 
        perror("Socket creation failed"); 
        return 1; 
    } 
     
    // Set server details 
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(110); //POP3 Server default port
     
    // Connect to server 
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { 
        perror("Connection failed"); 
        return 1; 
    } 
     
    // Receive server response 
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) { 
        perror("Receive failed"); 
        return 1; 
    } 
    printf("%s\n", server_reply); // Server greeting
     
    // Send user name 
    printf("Enter your username: "); 
    fgets(message, sizeof(message), stdin); 
    strcat(message, "\r\n"); // Terminate each command with \r\n 
    send(sock, message, strlen(message), 0); 
     
    // Receive server response 
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) { 
        perror("Receive failed"); 
        return 1; 
    } 
    printf("%s\n", server_reply); // Server response
     
    // Send password 
    printf("Enter your password: "); 
    fgets(message, sizeof(message), stdin); 
    strcat(message, "\r\n"); // Terminate each command with \r\n 
    send(sock, message, strlen(message), 0); 
     
    // Receive server response 
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) { 
        perror("Receive failed"); 
        return 1; 
    } 
    printf("%s\n", server_reply); // Server response
     
    // Send list command 
    strcpy(message, "list\r\n"); // Terminate each command with \r\n 
    send(sock, message, strlen(message), 0); 
     
    // Receive server response 
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) { 
        perror("Receive failed"); 
        return 1; 
    } 
    printf("%s\n", server_reply); // Server response
     
    // Send quit command 
    strcpy(message, "quit\r\n"); // Terminate each command with \r\n 
    send(sock, message, strlen(message), 0); 
     
    // Receive server response 
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) { 
        perror("Receive failed"); 
        return 1; 
    } 
    printf("%s\n", server_reply); // Server response
     
    close(sock); // Close the socket 
     
    return 0; 
}