//FormAI DATASET v1.0 Category: Client Server Application ; Style: beginner-friendly
//This is a simple Client-Server application that allows the client to send a message to the server and the server will respond with the same message received. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080 //Port number to listen on

int main()
{
    int sockfd, connfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Create socket file descriptor
    if(sockfd == -1){
        printf("Socket creation failed.\n");
        exit(0);
    }
    printf("Socket successfully created.\n");

    memset(&server_addr, '\0', sizeof(server_addr)); //Initialize address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if((bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))) != 0){ //Bind address to socket
        printf("Socket bind failed.\n");
        exit(0);
    }
    printf("Socket successfully bound.\n");

    if((listen(sockfd, 5)) != 0){ //Listen for incoming connections
        printf("Listen failed.\n");
        exit(0);
    }
    printf("Server listening on port %d.\n", PORT);

    addr_size = sizeof(client_addr);
    connfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size); //Accept incoming connection
    if(connfd < 0){
        printf("Error in connection.\n");
        exit(0);
    }
    printf("Connection successful.\n");

    while(1){ //Loop to keep receiving messages from client

        memset(buffer, '\0', sizeof(buffer));
        read(connfd, buffer, 1024); //Read message from client
        if(strcmp(buffer, "exit") == 0){ //Exit if client sends "exit" message
            printf("Client has left the chat.\n");
            break;
        }
        printf("Message from client: %s", buffer);

        write(connfd, buffer, strlen(buffer)); //Send message back to client
    }

    close(connfd); //Close connection
    close(sockfd); //Close socket
    return 0;
}