//FormAI DATASET v1.0 Category: Chat server ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>

#define PORT 8080

int main(){

    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0){
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server started and listening on port %d\n", PORT);

    while(1){
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
            perror("Failed to accept new connection");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, sizeof(buffer));
        printf("New client connected\n");

        if(fork() == 0){
            close(server_fd);

            while(1){
                int read_size = read(client_fd, buffer, sizeof(buffer));
                if(read_size <= 0){
                    printf("Client disconnected\n");
                    exit(0);
                }

                printf("[CLIENT] %s\n", buffer);
                printf("[SERVER] ");

                char server_input[1024];
                fgets(server_input, 1024, stdin);

                if(!strcmp(server_input, "exit\n")){
                    printf("Closing server\n");
                    exit(0);
                }

                write(client_fd, server_input, strlen(server_input));
                memset(buffer, 0, sizeof(buffer));
                memset(server_input, 0, sizeof(server_input));
            }
        }
    }

    return 0;
}