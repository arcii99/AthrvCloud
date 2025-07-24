//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAXSIZE];
    char *host, *username, *password, *filename;
    struct sockaddr_in server;

    if(argc < 5){
        printf("Usage: %s <server> <username> <password> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];
    username = argv[2];
    password = argv[3];
    filename = argv[4];

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;

    if(inet_pton(AF_INET, host, &server.sin_addr) <= 0){
        perror("Address not supported!");
        exit(EXIT_FAILURE);
    }

    server.sin_port = htons(21);

    if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0){
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "EPSV\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    char* code = strtok(buffer, "|)");
    code = strtok(NULL, "|)");
    int port = atoi(code);

    int data_sockfd;
    if((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in data_server;
    memset(&data_server, 0, sizeof(data_server));
    data_server.sin_family = AF_INET;

    if(inet_pton(AF_INET, host, &data_server.sin_addr) <= 0){
        perror("Address not supported!");
        exit(EXIT_FAILURE);
    }

    data_server.sin_port = htons(port);

    if(connect(data_sockfd, (struct sockaddr*)&data_server, sizeof(data_server)) < 0){
        perror("Data connection failed");
        exit(EXIT_FAILURE);
    }

    sprintf(buffer, "RETR %s\r\n", filename);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    FILE* fp = fopen(filename, "w");
    int bytes_read;
    while((bytes_read = read(data_sockfd, buffer, sizeof(buffer))) > 0){
        fwrite(buffer, sizeof(char), bytes_read, fp);
    }
    fclose(fp);

    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    close(sockfd);
    close(data_sockfd);
    return 0;
}