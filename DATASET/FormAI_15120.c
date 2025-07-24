//FormAI DATASET v1.0 Category: Simple Web Server ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

#define BUFSIZE 1024

void handle_request(int client_fd){
    char buf[BUFSIZE];
    int fd, len;
    fd = open("index.html", O_RDONLY);
    len = read(fd, buf, BUFSIZE);
    write(client_fd, buf, len);
}

int main(int argc, char *argv[]){
    int fd, client_fd;
    socklen_t len;
    struct sockaddr_in addr, client_addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3000);
    addr.sin_addr.s_addr = INADDR_ANY;

    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    if(bind(fd, (const struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if(listen(fd, 10) < 0){
        perror("Error listening to socket");
        exit(EXIT_FAILURE);
    }

    while(1){
        len = sizeof(client_addr);
        client_fd = accept(fd, (struct sockaddr *)&client_addr, &len);
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_request(client_fd);
        printf("Closing connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        close(client_fd);
    }

    return 0;
}