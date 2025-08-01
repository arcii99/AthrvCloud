//FormAI DATASET v1.0 Category: Chat server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define PORT 8888
 
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
     
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    // Attaching socket to port 8888
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
     
    // Binding socket to port 8888
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    // Listening for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
     
    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
     
    // Handling chat functionality
    while(1)
    {
        valread = read(new_socket , buffer, 1024);
        printf("%s\n",buffer );
        if(strcmp(buffer, "exit") == 0)
            break;
        memset(buffer, 0, 1024);
        fgets(buffer, 1024, stdin);
        send(new_socket , buffer , strlen(buffer) , 0 );
        printf("Message sent to client\n");
    }
    printf("Chat closed\n");
    close(new_socket);
    close(server_fd);
    return 0;
}