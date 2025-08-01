//FormAI DATASET v1.0 Category: Chat server ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("<---------Welcome to the Chat Server---------->\n");

    while(1){ // Accepting connections and handling them
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0){
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Displaying client information
        printf("Connection Established. Client Information: IP: %s PORT: %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        while(1){ // Communicating with client
            memset(buffer, 0, sizeof buffer);
            valread = read(new_socket, buffer, 1024);

            // Closing connection when client sends "exit" command
            if(strcmp(buffer,"exit")==0){
                printf("Client %d disconnected\n", new_socket);
                close(new_socket);
                break;
            }
            printf("Client %d: %s", new_socket, buffer); // Displaying message from client
            send(new_socket, hello, strlen(hello), 0);
        }
    }

    return 0;
}