//FormAI DATASET v1.0 Category: Client Server Application ; Style: accurate
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

#define PORT 8080

void sigint_handler(int sig){
    printf("\nExiting the program\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler);

    int server_fd, client_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding socket to the requested address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    // Marking the socket to say that we are ready to listen to incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1){
        // Accepting the incoming connection from the client
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();

        if(pid == 0){
            // This is the child process

            close(server_fd); // child doesn't need this
            valread = read( client_fd , buffer, 1024);
            printf("Received Message from Client: %s\n",buffer );
            send(client_fd , hello , strlen(hello) , 0 );
            printf("Hello message sent\n");
            exit(0);
        }
        else{
            // This is the parent process
            close(client_fd); // parent doesn't need this 
        }

    }
    return 0;
}