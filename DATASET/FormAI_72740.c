//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 110 //POP3 default port
#define BUFFER_SIZE 1024

//function declaration
void recvMessageAndPrint(int sockfd);

//main function
int main(int argc, char const *argv[]) {
    //variables declaration
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];

    //creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error!");
        return -1;
    }

    //resetting the buffer
    memset(&servaddr,0,sizeof(servaddr)); 

    //filling up the socket address structure
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //connecting the client socket to server socket
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("Failed to connect with server!");
        close(sockfd);
        return -1;
    }

    //receiving the server greeting message
    recvMessageAndPrint(sockfd);

    //sending the user credentials
    strcpy(buffer, "USER exampleuser\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recvMessageAndPrint(sockfd);

    //sending the user password
    strcpy(buffer, "PASS examplepassword\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recvMessageAndPrint(sockfd);

    //closing the connection
    strcpy(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recvMessageAndPrint(sockfd);
    close(sockfd);

    return 0;
}

//function definition to receive message from server and print it
void recvMessageAndPrint(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}