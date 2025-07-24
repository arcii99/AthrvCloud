//FormAI DATASET v1.0 Category: Chat server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(){
    printf("Holy Cow! You want a C Chat Server example program? This is going to be awesome!\n");

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed!");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the given port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))){
        perror("Setsockopt failed!");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the given port
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0){
        perror("Binding failed!");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0){
        perror("Listening failed!");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0){
        perror("Accepting failed!");
        exit(EXIT_FAILURE);
    }

    char *hello = "Ahoy there sailor! Welcome aboard!\n";
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Greetings message sent!\n");
    while(1){
        valread = read( new_socket , buffer, 1024);
        printf("%s\n",buffer );
        char reply[1024];
        strcpy(reply, "That's amazing! Me too!\n");
        send(new_socket , reply , strlen(reply) , 0 );
    }
    printf("Closing the socket!\n"); 
    close(new_socket);
    close(server_fd);
    return 0;
}