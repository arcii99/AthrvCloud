//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: light-weight
#include <stdio.h>  
#include <string.h>   // For using strlen() function  
#include <sys/socket.h>  
#include <arpa/inet.h>   //For using inet_addr() function  
#include <unistd.h>  // For using close() function  
#define PORT 6000    

int main() {  
    int sock_desc = socket(AF_INET, SOCK_STREAM, 0);// Creating socket file descriptor  
    if (sock_desc == -1)  
        printf("socket creation failed...\n");  
    else
        printf("Socket successfully created..\n");  
    struct sockaddr_in serv_addr;  
    serv_addr.sin_family = AF_INET;    
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Setting loopback IP Address  
    serv_addr.sin_port = htons(PORT);  // Setting Port number  
    // Connecting to server  
    if (connect(sock_desc, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) != 0) {  
        printf("Connection to the server failed...\n");  
        return 0;  
    }  
    printf("Connected to the server..\n");  
    char buffer[256];  
    int n;  
    // Get message from user input  
    printf("Enter message for server: ");  
    scanf("%s", buffer);   // Reading message from user input  
    // Sending message to the server  
    if (send(sock_desc, buffer, strlen(buffer), 0) == -1) {  
        printf("Send failed...\n");  
        return 0;  
    }  
    printf("Message sent to server...\n");  
    // Receiving the server message using recv() function  
    if ((n = recv(sock_desc, buffer, sizeof(buffer)-1, 0)) == -1) {  
        printf("Receive failed...\n");  
        return 0;  
    }  
    buffer[n] = '\0';  
    printf("Received message from server: %s\n", buffer);  
    close(sock_desc);  // Closing the socket descriptor  
    return 0;  
}