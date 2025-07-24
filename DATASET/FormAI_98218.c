//FormAI DATASET v1.0 Category: Socket programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *client_handler(void *);

int main(int argc, char **argv)
{
    int sockfd, clientfd;
    unsigned int len;
    struct sockaddr_in servaddr, cliaddr;
    pthread_t thread_id[MAX_CLIENTS];

    //Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    //Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    //Bind the socket to the address and port number
    if(bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    //Start listening on the socket for connections
    if(listen(sockfd, 5) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", ntohs(servaddr.sin_port));

    //Accept incoming connections from clients
    while(1)
    {
        len = sizeof(cliaddr);
        clientfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);

        if (clientfd < 0)
        {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        //Create thread to handle the client
        int i;
        for(i = 0; i < MAX_CLIENTS; i++)
        {
            if(thread_id[i] == 0)
            {
                if(pthread_create(&thread_id[i], NULL, client_handler, (void *)&clientfd) < 0)
                {
                    perror("Error creating thread");
                    exit(EXIT_FAILURE);
                }
                break;
            }
        }

        //If there are no available threads, reject the client connection
        if(i == MAX_CLIENTS)
        {
            printf("Maximum number of clients exceeded. Rejected connection from %s:%d\n",
                   inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
            close(clientfd);
        }
    }
}

void *client_handler(void *arg)
{
    int sockfd = *(int *)arg;
    char buffer[BUFFER_SIZE];

    while(1)
    {
        memset(buffer, 0, BUFFER_SIZE);

        //Receive data from client
        int recv_len = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (recv_len < 0)
        {
            perror("Error receiving data from client");
            break;
        }

        //Check if client disconnected
        if (recv_len == 0)
        {
            printf("Client disconnected\n");
            break;
        }

        //Display received data
        printf("Received from client %d: %s\n", sockfd, buffer);

        //Echo back to client
        if(send(sockfd, buffer, strlen(buffer), 0) < 0)
        {
            perror("Error sending data to client");
            break;
        }
    }

    //Clean up and close socket
    close(sockfd);
    pthread_exit(NULL);
}