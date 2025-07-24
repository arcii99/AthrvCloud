//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PORT 8080 //port number
#define MAXQUEUE 50 //maximum number of requests in the queue

int main() {

    //initialize variables
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    //create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //initialize server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //bind server socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //listen for incoming connections
    if (listen(server_fd, MAXQUEUE) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        //accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        //get IP address of client
        char *client_ip = inet_ntoa(address.sin_addr);
        printf("New connection from %s\n", client_ip);

        //receive data from client
        valread = read(new_socket , buffer, 1024);
        printf("Data received: %s\n",buffer );

        //send response to client
        char* message = "Response";
        send(new_socket , message , strlen(message) , 0 );
        printf("Response sent\n");

        //close socket
        close(new_socket);
    }

    return 0;
}