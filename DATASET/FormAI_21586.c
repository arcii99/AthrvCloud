//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

int main (int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_RESPONSE_SIZE];
    char command[MAX_COMMAND_SIZE];

    // check command line arguments
    if (argc < 3) {
        printf("usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // receive initial message from server
    bzero(buffer, MAX_RESPONSE_SIZE);
    n = read(sockfd, buffer, MAX_RESPONSE_SIZE-1);
    if (n < 0) {
         perror("ERROR reading from socket");
         exit(1);
     }
    printf("%s\n", buffer);

    // handle user commands
    while (1) {
        printf("> ");
        bzero(command, MAX_COMMAND_SIZE);
        scanf("%s", command);

        // quit command
        if (strcmp(command, "quit") == 0) {
            break;
        }

        // send command to server
        n = write(sockfd, command, strlen(command));
        if (n < 0) {
             perror("ERROR writing to socket");
             exit(1);
         }

        // receive response from server
        bzero(buffer, MAX_RESPONSE_SIZE);
        n = read(sockfd, buffer, MAX_RESPONSE_SIZE-1);
        if (n < 0) {
             perror("ERROR reading from socket");
             exit(1);
         }
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}