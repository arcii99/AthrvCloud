//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555

void encrypt(char* message){
    for(int i=0; i<strlen(message); i++){
        message[i] ^= 7; //XOR encryption
    }
}

void decrypt(char* message){
    for(int i=0; i<strlen(message); i++){
        message[i] ^= 7; //XOR decryption
    }
}

int main(){
    printf("Welcome to the Cryptic Chat Server!\n");
    printf("Listening on port %d...\n", PORT);

    //Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        printf("Failed to create socket\n");
        return 1;
    }

    //Bind socket to port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if(bind(server_fd, (struct sockaddr*) &address, sizeof(address)) == -1){
        printf("Failed to bind socket\n");
        return 1;
    }

    //Listen for connections
    if(listen(server_fd, 1) == -1){
        printf("Failed to listen\n");
        return 1;
    }

    //Accept incoming connections
    int client_fd = accept(server_fd, NULL, NULL);
    if(client_fd == -1){
        printf("Failed to accept incoming connection\n");
        return 1;
    }

    //Start chat loop
    char message[100];
    while(1){
        //Receive message from client
        if(recv(client_fd, message, sizeof(message), 0) == -1){
            printf("Failed to receive message\n");
            break;
        }

        //Decrypt message from client
        decrypt(message);

        //Print received message
        printf("Client: %s\n", message);

        //Get user input
        printf("You: ");
        fgets(message, 100, stdin);

        //Encrypt message before sending to client
        encrypt(message);

        //Send message to client
        if(send(client_fd, message, strlen(message), 0) == -1){
            printf("Failed to send message\n");
            break;
        }
    }

    close(client_fd);
    close(server_fd);
    printf("Chat ended\n");

    return 0;
}