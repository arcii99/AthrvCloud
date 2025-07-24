//FormAI DATASET v1.0 Category: Client Server Application ; Style: visionary
/* 
   Visionary C Client-Server Application Example
   This program allows multiple clients to connect to a server and send messages back and forth.
   It uses sockets and threading for concurrency.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

/* client_t struct to keep track of client's information */
typedef struct {
    int active; // 1 if client is connected, 0 if not
    int sockfd; // socket file descriptor
    char name[20]; // client's chosen name
    struct sockaddr_in addr; // client's socket address
} client_t;

/* array to keep track of active clients */
client_t clients[MAX_CLIENTS];

/* function to handle receiving messages from a client */
void *handle_client(void *arg) {
    int sender_fd = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(sender_fd, buffer, BUFFER_SIZE - 1);
        
        if (bytes_read < 0) {
            perror("Error reading from socket");
            break;
        }
        if (bytes_read == 0) {
            printf("Client disconnected\n");
            break;
        }
        
        /* loop through all clients and send message to them */
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].active && clients[i].sockfd != sender_fd) { // send message to all other active clients
                printf("%s: %s", clients[i].name, buffer);
                write(clients[i].sockfd, buffer, strlen(buffer));
            }
        }
    }
    
    /* client disconnected, clean up */
    close(sender_fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd == sender_fd) {
            clients[i].active = 0;
            break;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    
    /* initialize all clients to be inactive */
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].active = 0;
        clients[i].sockfd = -1;
    }
    
    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    
    /* set server address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    /* bind socket to server address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    
    /* start listening for clients */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    
    while (1) {
        /* accept new client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting client");
            continue;
        }
        
        /* add new client to array of clients */
        int added = 0;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i].active) {
                clients[i].active = 1;
                clients[i].sockfd = newsockfd;
                clients[i].addr = cli_addr;
                
                /* prompt client to enter name */
                write(newsockfd, "Enter your name: ", 17);
                memset(buffer, 0, BUFFER_SIZE);
                read(newsockfd, buffer, BUFFER_SIZE - 1);
                strncpy(clients[i].name, buffer, strlen(buffer) - 1);
                
                printf("%s connected\n", clients[i].name);
                
                /* start thread to handle messages from this client */
                pthread_t thread;
                int rc = pthread_create(&thread, NULL, handle_client, (void*)&clients[i].sockfd);
                if (rc < 0) {
                    perror("Error creating thread");
                    break;
                }
                
                added = 1;
                break;
            }
        }
        if (!added) { // too many clients already connected
            write(newsockfd, "Server full, try again later", 28);
            close(newsockfd);
        }
    }
    
    /* close server socket */
    close(sockfd);
    return 0;
}