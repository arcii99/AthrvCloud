//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
// The Adventure of the Client-Server Program

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }
    // Server greets the client
    printf("The server is now online and is waiting for a client to connect.\n");
    printf("Enter 'STOP' at any time to exit the program.\n");
    while(1){
        valread = read( new_socket , buffer, 1024);
        // Check if client has ended the connection
        if (valread == 0){
            printf("No data received, the connection is closed!\n");
            return 0;
        }
        printf("Client: %s\n",buffer );
        if(strcmp(buffer, "STOP") == 0){
            printf("Client has ended the connection!\n");
            return 0;
        }
        printf("Server: ");
        scanf("%[^\n]%*c", buffer);
        if(strcmp(buffer, "STOP") == 0){
            send(new_socket , buffer , strlen(buffer) , 0 );
            printf("You have ended the connection!\n");
            return 0;
        }
        send(new_socket , buffer , strlen(buffer) , 0 );
    }
    return 0;
}