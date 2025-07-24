//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Error opening socket!");
        exit(1);
    }

    // Assign IP address and port number to the socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 21;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the IP address and port number
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        perror("Error binding socket!");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept a new connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if(newsockfd < 0){
        perror("Error accepting connection!");
        exit(1);
    }

    // Connection successful!
    printf("Connection established!\n");

    // Authenticate user
    char username[50], password[50];
    char* u = "anonymous";
    char* p = "password";
    int login = 0;
    while(login != 1){
        bzero(buffer, 256);
        write(newsockfd, "331 Please specify password.\n", 29);
        read(newsockfd, buffer, 256);
        sscanf(buffer, "%s", password);
        write(newsockfd, "230 Login successful.\n", 21);
        printf("User authenticated!\n");
        login = 1;
    }

    // Send file
    char filename[50], get[10];
    FILE* file;
    int filesize, n;
    while(1){
        bzero(buffer, 256);
        write(newsockfd, "220 Ready to receive file.\n", 27);
        read(newsockfd, buffer, 256);
        sscanf(buffer, "%s %s", get, filename);
        if(strcmp(get, "get") == 0){
            file = fopen(filename, "rb");
            if(file == NULL){
                perror("Error opening file!");
                exit(1);
            }
            fseek(file, 0L, SEEK_END);
            filesize = ftell(file);
            fseek(file, 0L, SEEK_SET);
            printf("Sending %s to client...\n", filename);
            sprintf(buffer, "%d", filesize);
            write(newsockfd, buffer, strlen(buffer));
            bzero(buffer, 256);
            read(newsockfd, buffer, 256);
            while((n = fread(buffer, 1, 256, file)) > 0){
                write(newsockfd, buffer, n);
            }
            printf("File sent!\n");
            fclose(file);
        }
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}