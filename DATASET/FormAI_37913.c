//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1){
        printf("Failed to create socket");
    }
    printf("Socket created successfully");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc,(struct sockaddr *)&server, sizeof(server))<0){
        perror("Bind failed. Error");
        return 1;
    }
    printf("Bind completed successfully");

    // Listen
    listen(socket_desc, 3);

    // Accept and incoming connection
    printf("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))){
        printf("Connection accepted");

        // Receive message from client
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0 ){
            // Send the message back to the client
            write(client_sock, client_message, strlen(client_message));
        }
        if (read_size == 0){
            printf("Client disconnected");
        }
        else if (read_size == -1){
            perror("recv failed");
        }
    }
    return 0;
}