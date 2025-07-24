//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("\nUsage: POP3_Client <pop3-server-ip> <username> <password>\n");
        exit(1);
    }
    char *pop3_server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_address;
    char buffer[MAX_LENGTH];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(pop3_server_ip);;
    server_address.sin_port = htons(110);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) 
    { 
        printf("\nERROR: Connection Failed \n"); 
        exit(1); 
    } 

    // receive server greeting message
    memset(buffer, 0, sizeof(buffer)); 
    recv(sockfd, buffer, MAX_LENGTH, 0); 
    printf("%s",buffer);

    // send username to server
    char username_buffer[MAX_LENGTH];
    sprintf(username_buffer, "USER %s\r\n", username);
    send(sockfd, username_buffer, strlen(username_buffer), 0);

    // receive server response
    memset(buffer, 0, sizeof(buffer)); 
    recv(sockfd, buffer, MAX_LENGTH, 0); 
    printf("%s",buffer);
    
    // send password to server
    char password_buffer[MAX_LENGTH];
    sprintf(password_buffer, "PASS %s\r\n", password);
    send(sockfd, password_buffer, strlen(password_buffer), 0);

    // receive server response
    memset(buffer, 0, sizeof(buffer)); 
    recv(sockfd, buffer, MAX_LENGTH, 0); 
    printf("%s",buffer);

    // send command to list mail
    char list_buffer[MAX_LENGTH];
    sprintf(list_buffer, "LIST\r\n");
    send(sockfd, list_buffer, strlen(list_buffer), 0);

    // receive server response
    memset(buffer, 0, sizeof(buffer)); 
    recv(sockfd, buffer, MAX_LENGTH, 0); 
    printf("%s",buffer);

    // close socket
    close(sockfd);

    return 0;
}