//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_BUFFER 2048

int main()
{
    int client_sockfd, server_sockfd;
    struct sockaddr_in client_addr, server_addr;
    int pid;

    // Create a socket for client
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_sockfd < 0)
    {
        perror("Error in creating client socket\n");
        exit(1);
    }

    // Set the client address
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(8080);

    // Bind the client socket to the address
    if(bind(client_sockfd, (struct sockaddr*) &client_addr, sizeof(client_addr)) < 0)
    {
        perror("Error in client socket binding\n");
        exit(1);
    }

    // Listen for therequests
    if(listen(client_sockfd, 5) < 0)
    {
        perror("Error in listening for client requests\n");
        exit(1);
    }

    // Accept the client connection
    int client_len = sizeof(client_addr);
    int client_fd = accept(client_sockfd, (struct sockaddr*) &client_addr, &client_len);
    if(client_fd < 0)
    {
        perror("Error in accepting client request\n");
        exit(1);
    }

    // Create a socket for server
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sockfd < 0)
    {
        perror("Error in creating server socket\n");
        exit(1);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if(connect(server_sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in connecting to server\n");
        exit(1);
    }

    // Check if fork() was successful
    if((pid = fork()) < 0)
    {
        perror("Error in fork()\n");
        exit(1);
    }

    // Child process - send data from client to server
    if(pid == 0)
    {
        int nbytes;
        char buffer[MAX_BUFFER];

        while((nbytes = read(client_fd, buffer, MAX_BUFFER)) > 0)
        {
            if(write(server_sockfd, buffer, nbytes) < 0)
            {
                perror("Error in writing to server\n");
                exit(1);
            }
            bzero(buffer, MAX_BUFFER);
        }

        if(nbytes < 0)
        {
            perror("Error in reading from client\n");
            exit(1);
        }

        close(client_fd);
        close(server_sockfd);
        exit(0);
    }

    // Parent process - send data from server to client
    else
    {
        int nbytes;
        char buffer[MAX_BUFFER];

        while((nbytes = read(server_sockfd, buffer, MAX_BUFFER)) > 0)
        {
            if(write(client_fd, buffer, nbytes) < 0)
            {
                perror("Error in writing to client\n");
                exit(1);
            }
            bzero(buffer, MAX_BUFFER);
        }

        if(nbytes < 0)
        {
            perror("Error in reading from server\n");
            exit(1);
        }

        close(client_fd);
        close(server_sockfd);
        exit(0);
    }

    return 0;
}