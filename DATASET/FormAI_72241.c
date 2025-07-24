//FormAI DATASET v1.0 Category: Networking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc , char *argv[]) {
    int serverSocket , newSocket , activity;
    struct sockaddr_in serverAddr;
    
    //Allocate memory for the socket descriptors
    fd_set readfds;
    int max_sd, sd;
    int clients[MAX_CLIENTS] = {0};
    char buffer[BUFFER_SIZE];
    
    //Create the server socket
    if((serverSocket = socket(AF_INET , SOCK_STREAM , 0)) < 0) {
        printf("Socket creation error!\n");
        exit(EXIT_FAILURE);
    }
    printf("Server socket created successfully!\n");
    
    //Set the server socket structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    
    //Bind the socket to the port
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Failed to bind server socket to port %d!\n", PORT);
        exit(EXIT_FAILURE);
    }
    printf("Socket binded successfully!\n");
    
    //Listen for incoming connections
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        printf("Failed to listen for incoming connections!\n");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening for incoming connections on port %d\n", PORT);
    
    //Accept incoming connections
    socklen_t clientLength = sizeof(serverAddr);
    while(1) {
        FD_ZERO(&readfds);
        FD_SET(serverSocket, &readfds);
        max_sd = serverSocket;
        
        //Add client sockets to the set
        for(int i = 0; i < MAX_CLIENTS; i++) {
            sd = clients[i];
            if(sd > 0) {
                FD_SET(sd, &readfds);
            }
            if(sd > max_sd) {
                max_sd = sd;
            }
        }

        //Wait for an activity on any of the sockets
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0 && errno != EINTR) {
            printf("Error in select() function!\n");
        }
    
        //Handle incoming connections
        if (FD_ISSET(serverSocket, &readfds)) {
            if ((newSocket = accept(serverSocket, (struct sockaddr *)&serverAddr, &clientLength)) < 0) {
                printf("Error accepting incoming connection!\n");
                exit(EXIT_FAILURE);
            }

            //Add the new client socket to the clients array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == 0) {
                    clients[i] = newSocket;
                    printf("New connection received from %s on socket %d\n", inet_ntoa(serverAddr.sin_addr), newSocket);
                    break;
                }
            }
        }

        //Handle client activity
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = clients[i];

            if (FD_ISSET(sd, &readfds)) {
                //Read incoming message from client
                memset(buffer, 0, BUFFER_SIZE);
                int readStatus = read(sd, buffer, BUFFER_SIZE);
                if (readStatus == 0) {
                    //Client disconnected
                    printf("Client on socket %d disconnected!\n", sd);
                    close(sd);
                    clients[i] = 0;
                } else {
                    printf("New message from client on socket %d: %s\n",sd, buffer);

                    //Echo the message back to the client
                    int writeStatus = write(sd, buffer, strlen(buffer));
                    if (writeStatus < 0) {
                        printf("Error echoing message back to client on socket %d!\n", sd);
                    }
                }
            }
        }
    }
    return 0;
}