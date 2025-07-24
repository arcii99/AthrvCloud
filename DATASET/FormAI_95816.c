//FormAI DATASET v1.0 Category: Client Server Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char**argv)
{
    int sockfd;                             // socket file descriptor
    struct sockaddr_in serv_addr;           // server address structure
    char buffer[1024];                      // buffer to store message
    int n;
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // set up server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    
    // convert ip address from string format to binary format
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        perror("Invalid address/ Address not supported");
        exit(1);
    }
    
    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Welcome! Type 'exit' to quit.\n");

    while(1) {
        // clear buffer
        memset(buffer, '\0', sizeof(buffer));

        // read user input from stdin
        printf("You: ");
        fgets(buffer, 1024, stdin);

        // remove newline character from input
        buffer[strcspn(buffer, "\n")] = 0;

        // exit if user inputs 'exit'
        if(strcmp(buffer, "exit") == 0) {
            send(sockfd, buffer, strlen(buffer), 0);
            printf("Goodbye!\n");
            break;
        }

        // send user input to server
        send(sockfd, buffer, strlen(buffer), 0);

        // receive message from server
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        
        // print message from server
        printf("Server: %s\n", buffer);
    }

    // close socket
    close(sockfd);

    return 0;
}