//FormAI DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#define PORT 8080

static volatile sig_atomic_t keep_running = 1;

void handle_exit(int sig){
    keep_running = 0;
}

void handler(int sockfd){
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (keep_running == 1){
        int valread = read(sockfd, buffer, 1024);
        if (valread == 0 || strcmp(buffer, "exit\n") == 0){
            printf("Client disconnected\n");
            break;
        }
        printf("Client: %s", buffer);
        printf("Server: ");
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, 1024, stdin);
        write(sockfd, buffer, strlen(buffer));

        if (strcmp(buffer, "exit\n") == 0){
            printf("Server shutting down\n");
            break;
        }
    }
    close(sockfd);
}

int main(int argc, char const *argv[]){

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0){
        perror("Listen Failed");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handle_exit);

    printf("Server established. Awaiting client connection...\n");

    while (keep_running == 1){
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&address)) < 0){
            perror("Accept Failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection established.\n");

        pid_t pid = fork();
        if (pid == -1){
            perror("Fork Failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0){
            handler(new_socket);
            exit(0);
        } else {
            close(new_socket);
        }
    }

    close(server_fd);
    return 0;
}