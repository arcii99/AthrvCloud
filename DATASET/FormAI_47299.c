//FormAI DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 8080

int main(){
    int sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd==-1){
        perror("socket creation failed...");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server, client;
    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(PORT);
    if(bind(sockfd, (struct sockaddr*)&server, sizeof(server))==-1){
        perror("bind failed...");
        exit(EXIT_FAILURE);
    }
    if(listen(sockfd, 5)==-1){
        perror("listen failed...");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d...\n", PORT);
    socklen_t len=sizeof(client);
    int new_fd=accept(sockfd, (struct sockaddr*)&client, &len);
    if(new_fd==-1){
        perror("accept failed...");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    read(new_fd, buffer, sizeof(buffer));
    printf("Client: %s", buffer);
    char response[]="Hello from the server...";
    write(new_fd, response, strlen(response));
    close(new_fd);
    close(sockfd);
    return 0;
}