//FormAI DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8000

int main(){
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    int yes = 1;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //setsockopt reusess address and port
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &yes, sizeof(int))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //set sockaddr_in parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //bind socket to IP and Port
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //listen to socket
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //wait for client to connect
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    //display client's IP and port
    printf("Client connected | IP: %s | Port: %d\n",inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    //start conversation with client
    while(read(new_socket, buffer, 1024)){
        printf("Client: %s\n", buffer);

        if(strncmp(buffer,"exit",4)==0){
            printf("Connection terminated\n");
            break;
        }

        printf("Server: ");
        bzero(buffer,1024);
        fgets(buffer,1024,stdin);
        write(new_socket, buffer, strlen(buffer));
    }

    close(new_socket);
    close(server_fd);

    return 0;
}