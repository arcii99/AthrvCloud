//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080    

int main(int argc, char const *argv[]) 
{ 
    int socket_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *hello = "Hello from server"; 
        
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket creation failed"); 
        return -1; 
    } 
     
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt failed"); 
        return -1; 
    } 
     
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
         
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        return -1; 
    } 
     
    if (listen(socket_fd, 3) < 0) 
    { 
        perror("listen failed"); 
        return -1; 
    } 
     
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("accept failed"); 
        return -1; 
    } 
     
    valread = read(new_socket, buffer, 1024); 
    printf("%s\n", buffer); 
    send(new_socket, hello, strlen(hello), 0 ); 
    printf("Hello message sent\n"); 
    return 0; 
}