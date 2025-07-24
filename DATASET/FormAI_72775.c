//FormAI DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 12345
#define MAX_CONN 5
#define BUFFER_SIZE 1024 

int main(){
    //create socket
    int server_fd, ret;
    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0){
        printf("Error in socket creation\n");
        exit(EXIT_FAILURE);
    }

    //set socket options
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    //set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    //bind socket to address and port
    ret = bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(ret < 0){
        printf("Error in binding socket to address and port\n");
        exit(EXIT_FAILURE);
    }

    //listen to maximum of 5 connections
    ret = listen(server_fd, MAX_CONN);
    if(ret < 0){
        printf("Error in listening to connections\n");
        exit(EXIT_FAILURE);
    }

    //accept connections
    struct sockaddr_in client_addr;
    int client_fd, addrlen, i, j;
    char buffer[BUFFER_SIZE];

    while(1){
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);
        if(client_fd < 0){
            printf("Error in accepting connection\n");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //receive filename and file data
        char filename[100];
        memset(filename, 0, sizeof(filename));
        ret = recv(client_fd, filename, sizeof(filename), 0);
        if(ret < 0){
            printf("Error in receiving filename\n");
            close(client_fd);
            continue;
        }

        FILE *fp = fopen(filename, "w");
        if(fp == NULL){
            printf("Error in opening file\n");
            close(client_fd);
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);
        while((ret = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0){
            fwrite(buffer, sizeof(char), ret, fp);
            memset(buffer, 0, BUFFER_SIZE);
        }
        fclose(fp);

        printf("File '%s' successfully synchronized\n", filename);
        close(client_fd);
    }
    close(server_fd);
    return 0;
}