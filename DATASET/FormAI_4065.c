//FormAI DATASET v1.0 Category: Client Server Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]){
    int server_socket; 
    struct sockaddr_in server_addr, client_addr;
    char message[MAX_MSG_LEN];

    // create socket
    server_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (server_socket == -1){
        printf("Error: could not create socket\n");
        return 1;
    }

    // set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5555);

    // bind socket to address
    if(bind(server_socket,(struct sockaddr *)&server_addr , sizeof(server_addr)) < 0){
        printf("Error: bind failed\n");
        return 1;
    }

    // listen for incoming connections
    listen(server_socket , 3);

    // accept incoming connection
    printf("Waiting for incoming connection...\n");
    socklen_t client_len = sizeof(struct sockaddr_in);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
    if (client_socket < 0){
        printf("Error: could not accept incoming connection\n");
        return 1;
    }

    // read incomming messages, respond with "Thanks for being grateful!"
    while(1){
        memset(message, 0, MAX_MSG_LEN);
        if(recv(client_socket, message, MAX_MSG_LEN, 0) < 0){
            printf("Error: could not receive incoming message\n");
            break;
        }
        printf("Received message: %s\n", message);
        if(send(client_socket, "Thanks for being grateful!", strlen("Thanks for being grateful!"), 0) < 0){
            printf("Error: could not send response\n");
            break;
        }
    }

    // close sockets
    close(client_socket);
    close(server_socket);
    return 0;
}