//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching options to the socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(server_fd, MAX_CLIENTS) < 0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    int client_sock[MAX_CLIENTS];
    int num_clients = 0;
    fd_set readfds; // Set of file descriptors to monitor for read activity

    while(1){
        // Clearing the file descriptor set
        FD_ZERO(&readfds);

        // Adding the server socket to the file descriptor set
        FD_SET(server_fd, &readfds);

        // Adding the client sockets to the file descriptor set
        for(int i=0;i<num_clients;i++){
            FD_SET(client_sock[i], &readfds);
        }

        // Selecting sockets with activity
        int max = server_fd;
        for(int i=0;i<num_clients;i++){
            if(client_sock[i] > max){
                max = client_sock[i];
            }
        }
        int activity = select(max+1, &readfds, NULL, NULL, NULL);
        if(activity < 0){
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // Handling activity on server socket
        if(FD_ISSET(server_fd, &readfds)){
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
            printf("New client connected. Socket FD is %d\n", new_socket);
            client_sock[num_clients] = new_socket;
            num_clients++;
        }

        // Handling activity on client sockets
        for(int i=0;i<num_clients;i++){
            if(FD_ISSET(client_sock[i], &readfds)){
                valread = read(client_sock[i], buffer, BUFFER_SIZE);
                if(valread == 0){
                    printf("Client disconnected\n");
                    close(client_sock[i]);
                    for(int j=i;j<num_clients-1;j++){
                        client_sock[j] = client_sock[j+1];
                    }
                    num_clients--;
                }
                else{
                    printf("Received message from client: %s\n", buffer);
                    send(client_sock[i], buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}