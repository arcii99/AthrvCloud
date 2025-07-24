//FormAI DATASET v1.0 Category: Networking ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8080 // Port number as constant
#define MAXSIZE 1024 // Maximum buffer size for receiving and sending data

int main()
{
    int sockfd = 0; 
    struct sockaddr_in serv_addr; // Stores the server address

    // Creating a socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    // Setting up server address properties
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // IPv4 protocol
    serv_addr.sin_port = htons(PORT); // Port number in network byte order

    // Converting IPv4 address from text to binary format
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connecting to the server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Sending data to the server
    char buffer[MAXSIZE];
    printf("Enter a message: ");
    fgets(buffer, MAXSIZE, stdin);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("\nSending failed\n");
        return -1;
    }
    printf("Message sent to server\n");

    // Receiving data from the server
    memset(buffer, 0, MAXSIZE);
    int valread;
    if((valread = read(sockfd, buffer, MAXSIZE)) < 0) {
        printf("\nReading failed\n");
        return -1;
    }
    printf("Message received from server: %s\n", buffer);

    // Closing the socket
    close(sockfd);

    return 0;
}