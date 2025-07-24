//FormAI DATASET v1.0 Category: Chat server ; Style: beginner-friendly
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 5555 
#define MAX_CLIENTS 10 
#define BUFFER_SIZE 1024 

int main() 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int addrlen = sizeof(address); 

    char buffer[BUFFER_SIZE] = {0}; 

    // create socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // set socket options 
    int opt = 1; 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) 
    { 
        perror("setsockopt failed"); 
        exit(EXIT_FAILURE); 
    } 

    // set address 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    // bind socket to address 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // start listening for clients 
    if (listen(server_fd, MAX_CLIENTS) < 0) 
    { 
        perror("listen failed"); 
        exit(EXIT_FAILURE); 
    } 

    // accept incoming client connections 
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) 
    { 
        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port)); 

        // fork a new child process to handle client communication 
        pid_t pid = fork(); 
        if (pid < 0) 
        { 
            perror("fork failed"); 
            exit(EXIT_FAILURE); 
        } 
        else if (pid == 0) // child process 
        { 
            close(server_fd); // close server socket in child process 

            // handle client communication 
            while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) 
            { 
                printf("%s:%d says: %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer); 

                // echo message back to client 
                send(new_socket, buffer, strlen(buffer), 0); 

                // clear buffer 
                memset(buffer, 0, sizeof(buffer)); 
            } 

            close(new_socket); // close client socket in child process 
            exit(EXIT_SUCCESS); // exit child process successfully 
        } 
        else // parent process 
        { 
            close(new_socket); // close client socket in parent process 
        } 
    } 

    // close server socket 
    close(server_fd); 

    return 0; 
}