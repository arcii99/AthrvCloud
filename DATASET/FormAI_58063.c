//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define MAX 1024
#define PORT 110

void receiveMail(int sockfd)  //Function to receive mail contents
{
    char buffer[MAX];
    int n;
    do{
        bzero(buffer,sizeof(buffer));    //clear buffer
        n = read(sockfd,buffer,MAX);     //read the mail contents
        printf("%s", buffer);            //print the contents in console
    }while(n > 0);
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX];
    char username[MAX];
    char password[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Create TCP Socket
    if(sockfd == -1)
    {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket created successfully...\n");

    bzero(&servaddr, sizeof(servaddr));   //clear servaddr memory
    servaddr.sin_family = AF_INET;        //IPV4
    servaddr.sin_port = htons(PORT);      //define the port number to connect
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");     //localhost address

    //connect the client to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("Connection with the server failed...\n");
        exit(0);
    }
    else
        printf("Connected to the server successfully...\n");

    receiveMail(sockfd); //receive the welcome mail

    sprintf(buffer, "USER username\r\n"); //send the username to server
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));  //clear the buffer
    receiveMail(sockfd); //receive the response from server

    sprintf(buffer, "PASS password\r\n"); //send the password to server
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));  //clear the buffer
    receiveMail(sockfd); //receive the response from server

    sprintf(buffer, "LIST\r\n");    //send command to list mails
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));  //clear the buffer
    receiveMail(sockfd); //receive the response from server

    sprintf(buffer, "RETR 1\r\n");  //send command to retrieve mail 1
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));  //clear the buffer
    receiveMail(sockfd); //receive the mail contents

    sprintf(buffer, "QUIT\r\n");    //send command to quit the session
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));  //clear the buffer
    receiveMail(sockfd); //receive the closing mail from server

    close(sockfd);  //close the socket

    return 0;
}