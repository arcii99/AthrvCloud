//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int socket_fd, id;
    struct sockaddr_in server_address, client_address;
    char buffer[1024] = {0};
    char response[1024] = {0};

    //Create server socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //Bind server to specified port
    bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    //Listen for incoming connections
    listen(socket_fd, 5);

    while(1) {
        //Accept incoming connection
        id = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address);

        if(id < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        //Receive request from client
        read(id, buffer, 1024);

        //Prepare response
        strcpy(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>");
        
        //Send response to client
        write(id, response, strlen(response));

        //Close client connection
        close(id);
    }

    //Close server socket
    close(socket_fd);

    return 0;
}