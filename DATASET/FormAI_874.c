//FormAI DATASET v1.0 Category: Socket programming ; Style: Sherlock Holmes
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main() {
    int socket_desc;
    struct sockaddr_in server_addr;
    char* message, server_reply[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc == -1) {
        printf("Could not create socket");
    }

    // Server Configuration
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Localhost
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);

    //Connect to remote server
    if(connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Error");
        return 1;
    }

    printf("Connected to server\n");

    // Send data
    message = "Hello server!";
    if(send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("Data sent successfully\n");

    // Receive data
    if(recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("Server Reply: ");
    puts(server_reply);

    close(socket_desc);
    return 0;
}