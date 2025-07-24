//FormAI DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

int main() { 
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("216.58.194.174");
    
    int status = connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    
    if (status == -1) {
        printf("Error connecting to the server");
        return 1;
    }
    
    char* message = "GET / HTTP/1.1\r\n\r\n";
    
    int bytes_sent = send(sock, message, strlen(message), 0);
    
    if (bytes_sent == -1) {
        printf("Error sending message to the server");
        return 1;
    }
    
    char server_response[4096];
    int bytes_received = recv(sock, server_response, 4096, 0);
    
    if (bytes_received == -1) {
        printf("Error receiving response from the server");
        return 1;
    }
    
    printf("Server response:\n%s", server_response);
    
    close(sock);
    
    return 0; 
}