//FormAI DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 5000
#define BUF_SIZE 1024

int main(){
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addr_len = sizeof(client_addr);
    char buffer[BUF_SIZE] = {0};

    // Creating server socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the specified port
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Setting address family, IP address and port number of server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the server socket to the specified address and port number 
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for client connections
    if(listen(server_fd, 3) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accepting incoming client connections
    if((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) < 0){
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected from %s : %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while(1){
        // Receiving data from client
        memset(buffer, 0, BUF_SIZE);
        if(read(client_fd, buffer, BUF_SIZE) == 0){
            printf("Client disconnected\n");
            break;
        }
        printf("Received from client: %s\n", buffer);

        // Sending reply to client
        char reply[BUF_SIZE];
        strcpy(reply, "Message received successfully!");
        if(send(client_fd, reply, strlen(reply), 0) < 0){
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
        printf("Reply sent to client\n");
    }

    // Closing server and client sockets
    close(server_fd);
    close(client_fd);

    return 0;
}