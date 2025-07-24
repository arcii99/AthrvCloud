//FormAI DATASET v1.0 Category: Networking ; Style: bold
//This program demonstrates a server-client chat system using socket programming in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080 

//Function to handle error
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    //Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
       error("ERROR opening socket");

    //Setting server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    //Binding socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");

    //Listening to incoming connections
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    //Accepting incoming connections
    newsockfd = accept(sockfd, 
                (struct sockaddr *) &cli_addr, 
                &clilen);
    if (newsockfd < 0) 
         error("ERROR on accept");

    //Printing client address
    printf("Connection established with %s\n", inet_ntoa(cli_addr.sin_addr));

    //Communication between server and client
    while(1){
        bzero(buffer,256);

        //Reading from client socket
        n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");

        printf("Client: %s\n",buffer);

        bzero(buffer,256);
        printf("Server: ");

        //Reading message to be sent from server
        fgets(buffer,255,stdin);

        //Writing to client socket
        n = write(newsockfd,buffer,strlen(buffer));
        if (n < 0) 
            error("ERROR writing to socket");

        //Checking if end of conversation
        if(strncmp("Bye", buffer, 3) == 0)
            break;
    }

    //Closing connection
    close(newsockfd);
    close(sockfd);
    return 0; 
}