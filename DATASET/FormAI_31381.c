//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 21    // FTP server port number
#define MESSAGE_SIZE 1024 // Maximum size of message read from the server
#define MAX_COMMAND_SIZE 100 // Maximum size of the command entered by the user

void error(const char *msg) // Function to handle errors
{
   perror(msg);
   exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    char buffer[MESSAGE_SIZE];
    struct sockaddr_in serv_addr;

    // Check if enough arguments are provided
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname username password\n", argv[0]);
        exit(0);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
       error("ERROR opening socket");

    // Set the server address and port number
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("ERROR invalid server IP address");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // Read and print the welcome message from the server
    bzero(buffer,MESSAGE_SIZE);
    n = read(sockfd,buffer,MESSAGE_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    // Send the username and password to the server
    char username[MAX_COMMAND_SIZE];
    char password[MAX_COMMAND_SIZE];
    memset(username, 0, sizeof(username));
    memset(password, 0, sizeof(password));
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,MESSAGE_SIZE);
    n = read(sockfd,buffer,MESSAGE_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,MESSAGE_SIZE);
    n = read(sockfd,buffer,MESSAGE_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    // Let the user enter the FTP commands and communicate with the server
    while (1) {
        printf("Enter FTP command: ");
        bzero(buffer,MESSAGE_SIZE);
        fgets(buffer,MAX_COMMAND_SIZE,stdin);
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) 
             error("ERROR writing to socket");
        if (strcmp(buffer, "quit\n") == 0) // Exit loop if user enters "quit" command
            break;
        bzero(buffer,MESSAGE_SIZE);
        n = read(sockfd,buffer,MESSAGE_SIZE-1);
        if (n < 0) 
             error("ERROR reading from socket");
        printf("%s\n",buffer);
    }
    close(sockfd);
    return 0;
}