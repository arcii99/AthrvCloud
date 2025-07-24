//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_REQUEST_LENGTH 1024

int main() {
    int socket_fd, valread;
    struct sockaddr_in server_addr;
    char request[MAX_REQUEST_LENGTH] = {0};
    char* server_ip = "127.0.0.1";
    
    // Creating socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Can't create socket, I am out of energy, need to recharge!\n");
        return -1;
    }
    
    printf("Socket created, now I am charged up and ready to go!\n");
    
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_port = htons(SERVER_PORT); // Port number
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr)<=0) {
        printf("Invalid IP address, I am going to crash now!\n");
        return -1;
    }
   
    // Connecting to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed, I am literally crashing now!\n");
        return -1;
    }

    printf("Connected to server, woohoo!\n");
    
    // Sending request
    strcpy(request, "GET / HTTP/1.1\r\n"); // Request line
    strcat(request, "Host: example.com\r\n"); // Host header
    strcat(request, "\r\n"); // Blank line to indicate end of headers
    
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        printf("Request failed, I am so embarrassed now!\n");
        return -1;
    }

    printf("Request sent, waiting for response, fingers crossed :)\n");
    
    char response[MAX_REQUEST_LENGTH] = {0};
    
    // Receiving response
    if ((valread = read(socket_fd, response, MAX_REQUEST_LENGTH)) < 0) {
        printf("Failed to receive response, I am going to cry now!\n");
        return -1;
    }
    
    printf("Response received!, can't believe it worked haha!\n");
    printf("%s", response);
    
    close(socket_fd);
    return 0;
}