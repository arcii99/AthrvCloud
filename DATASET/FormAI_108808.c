//FormAI DATASET v1.0 Category: Chat server ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define PORT 8080

struct client{
    int id;
    int socket;
    char name[50];
};

struct client clients[50];
int numClients = 0;

void *communicate(void *clientSocket) {
    int sock = *(int*)clientSocket;
    char buffer[1024];
    int valread;
    int clientId = -1;

    while(1) {
        valread = read(sock,buffer,1024);
        if(valread == 0) {
            break;
        }
        buffer[valread] = '\0';

        // check if first message receiving from client is the name of the client
        if(clientId == -1) {
            // new client joining the chat
            clientId = numClients;
            clients[clientId].id = clientId;
            clients[clientId].socket = sock;
            strcpy(clients[clientId].name,buffer);
            numClients++;

            printf("%s joined the chat. Total clients: %d\n",clients[clientId].name,numClients);
            
            strcpy(buffer, "Welcome to the chat room. Start chatting...\n");
            write(sock , buffer , strlen(buffer));
        } else {
            // message coming from existing client
            printf("%s: %s",clients[clientId].name,buffer);
            for(int i=0;i<numClients;i++) {
                if(clients[i].socket != sock) {
                    // send message to all other clients except the sender
                    write(clients[i].socket , buffer , strlen(buffer));
                }
            }
        }
        memset(buffer, 0, sizeof(buffer));
    }

    // remove client from list
    printf("%s left the chat. Total clients: %d\n",clients[clientId].name,numClients-1);
    close(sock);
    clients[clientId].id = -1;
    clients[clientId].socket = -1;
    memset(clients[clientId].name,0,sizeof(clients[clientId].name));
    numClients--;
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int serverSocket, newSocket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(serverSocket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for clients to join...\n");
    while(1) {
        if ((newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_t tid;
        if(pthread_create(&tid, NULL, communicate, &newSocket) != 0) {
            perror("pthread_create failed");
            return EXIT_FAILURE;
        }
    }

    return 0;
}