//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<string.h>

#define PROXY_PORT 5000
#define SERVER_PORT 8000
#define BUFF_SIZE 8192

int main(){

    int listen_fd, conn_fd;
    struct sockaddr_in proxy_addr, server_addr, client_addr;

    //creating proxy listener socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd == -1){
        perror("Failed to create listen_fd socket");
        exit(1);
    }

    //biding listener socket
    bzero(&proxy_addr, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PROXY_PORT);
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listen_fd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) == -1){
        perror("Failed to bind listen_fd socket");
        exit(1);
    }

    //listening to listener socket
    if(listen(listen_fd, 10) == -1){
        perror("Failed to listen on listen_fd socket");
        exit(1);
    }
    printf("Proxy server started listening on port %d...\n", PROXY_PORT);

    while(1){
        socklen_t client_len = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);

        if(conn_fd == -1){
            perror("Failed to accept connection");
            close(conn_fd);
            continue;
        }

        printf("Accepting new connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //creating server socket
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(server_fd == -1){
            perror("Failed to create server_fd socket");
            exit(1);
        }

        //biding server socket
        bzero(&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        //connecting to server
        if(connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
            perror("Failed to connect to server");
            close(server_fd);
            exit(1);
        }

        //Forking new process
        int pid = fork();
        if(pid == -1){
            perror("Failed to create child process");
            close(conn_fd);
            close(server_fd);
            exit(1);
        }
        else if(pid == 0){ //child process
            char buffer[BUFF_SIZE];
            int n_read, n_written;
            bzero(buffer, BUFF_SIZE);

            while((n_read = read(conn_fd, buffer, BUFF_SIZE)) > 0){ //read request from client
                printf("Received request from client %s:%d:\n%s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

                if(write(server_fd, buffer, n_read) < 0){ //write request to server
                    perror("Failed to write to server");
                    close(conn_fd);
                    close(server_fd);
                    exit(1); 
                }

                bzero(buffer, BUFF_SIZE);

                if((n_read = read(server_fd, buffer, BUFF_SIZE)) < 0){ //read response from server
                    perror("Failed to read from server");
                    close(conn_fd);
                    close(server_fd);
                    exit(1);
                }

                printf("Received response from server:\n%s\n", buffer);

                if(write(conn_fd, buffer, n_read) < 0){ //write response to client
                    perror("Failed to write to client");
                    close(conn_fd);
                    close(server_fd);
                    exit(1);
                }

                bzero(buffer, BUFF_SIZE);

            }

            close(conn_fd);
            close(server_fd);
            exit(0);
        }
        else{ //parent process
            close(conn_fd);
            close(server_fd);
        }

    }

    close(listen_fd);
    return 0;
}