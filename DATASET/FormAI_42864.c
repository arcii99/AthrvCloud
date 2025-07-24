//FormAI DATASET v1.0 Category: Client Server Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8000

int main(int argc, const char * argv[]) {

    /* Creating a socket */
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        printf("Socket creation failed!\n");
        exit(0);
    }

    /* Setting up the server address for binding */
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    /* Binding the socket */
    if(bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1){
        printf("Socket bind failed!\n");
        exit(0);
    }

    /* Listening for incoming connections */
    if(listen(server_fd, 5) == -1){
        printf("Socket listen failed!\n");
        exit(0);
    }

    printf("Server is running on port %d...\n", PORT);

    /* Accepting incoming connections */
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_length);

    if(client_socket_fd == -1){
        printf("Client connection accept failed!\n");
        exit(0);
    }

    printf("Connection established with client - %s:%d\n", 
            inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    /* Receiving data from the client */
    char buffer[1024];
    int bytes_received = recv(client_socket_fd, buffer, 1024, 0);

    printf("Data received from client: %s\n", buffer);

    /* Sending response to the client */
    char message[] = "Hello from server!";
    send(client_socket_fd, message, strlen(message), 0);

    /* Closing the connection */
    close(client_socket_fd);
    close(server_fd);

    return 0; 
}