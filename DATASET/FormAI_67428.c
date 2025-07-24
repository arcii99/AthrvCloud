//FormAI DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>      // standard input/output header file
#include <stdlib.h>     // standard library header file
#include <string.h>     // string handling header file
#include <unistd.h>     // miscellaneous functions header file
#include <sys/socket.h> // socket programming header file
#include <arpa/inet.h>  // socket programming header file
#include <netinet/in.h> // socket programming header file
#include <pthread.h>    // threading header file

#define PORT 8080       // port number for the server
#define MAX_CLIENTS 10  // maximum number of clients that can connect

int client_sock[MAX_CLIENTS] = {0};    // array of client socket file descriptors
int server_sock;                        // server socket file descriptor
int num_clients = 0;                    // variable to keep track of number of connected clients
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // mutex for thread synchronization

void *client_handler(void *arg)
{
    int clientfd = *(int *)arg;
    char buffer[1024];

    while(1)
    {
        bzero(buffer, sizeof(buffer)); // clear buffer
        read(clientfd, buffer, sizeof(buffer)); // receive message

        // print client message
        printf("Message from client %d: %s", clientfd, buffer);

        // broadcast message to all connected clients except the sender
        pthread_mutex_lock(&mutex); // acquire lock to prevent race condition
        for(int i=0; i<num_clients; i++)
        {
            if(client_sock[i] != clientfd)
            {
                write(client_sock[i], buffer, sizeof(buffer));
            }
        }
        pthread_mutex_unlock(&mutex); // release lock
    }
}

int main()
{
    int clientfd, new_sockfd;
    struct sockaddr_in servaddr, clientaddr;
    pthread_t thread;

    // create server socket
    server_sock= socket(AF_INET, SOCK_STREAM, 0);

    // initialize server socket parameters
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // bind the socket with the server address and port
    if(bind(server_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if(listen(server_sock, MAX_CLIENTS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Listening for connections on port %d...\n", PORT);

    while(1)
    {
        // accept incoming connection
        int len = sizeof(clientaddr);
        clientfd = accept(server_sock, (struct sockaddr*)&clientaddr, &len);

        if(clientfd < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // add new client to array and increment client count
        pthread_mutex_lock(&mutex); // acquire lock to prevent race condition
        client_sock[num_clients] = clientfd;
        num_clients++;
        pthread_mutex_unlock(&mutex); // release lock

        // create a new thread to handle client
        if(pthread_create(&thread, NULL, &client_handler, &clientfd) != 0)
        {
            perror("Could not create thread");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}