//FormAI DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

void serverError(char* error){
    printf("Server Error Occured: %s", error);
    exit(1);
}

int main(){

    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        serverError("Unable to create socket.");
    }

    printf("Socket created successfully. \n");

    // Set SO_REUSEADDR option
    int opt = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1){
        serverError("setsockopt failed.");
    }

    // Bind the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    if(bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1){
        serverError("bind failed.");
    }

    printf("Socket binded successfully. \n");

    // Listen for incoming connections
    int listen_result = listen(server_fd, 3);
    if(listen_result == -1){
        serverError("Listen failed.");
    }

    printf("Server is now listening on port 8080. \n");

    // Accept incoming client connection
    int client_fd;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen);
    if(client_fd == -1){
        serverError("Unable to accept client connection.");
    }

    printf("Client connected successfully. \n");

    // Read client request
    char buffer[1024] = {0};
    int read_result = read(client_fd, buffer, 1024);
    if(read_result == -1){
        serverError("Unable to read client request.");
    }

    printf("Client request received: \n%s\n", buffer);

    // Respond to client
    char* response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    int send_result = send(client_fd, response, strlen(response), 0);
    if(send_result == -1){
        serverError("Unable to send response.");
    }

    printf("Response sent successfully. \n");

    close(client_fd);
    close(server_fd);

    return 0;
}