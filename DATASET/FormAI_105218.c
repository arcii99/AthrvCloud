//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: calm
/* This program is a TCP/IP client that connects to a server and sends a message.
 * It then waits for a response from the server and prints it out.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
        error("ERROR opening socket");

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("Please enter the message: ");
    fgets(buffer,255,stdin);

    n = write(sockfd,buffer,strlen(buffer));

    if (n < 0) 
        error("ERROR writing to socket");

    memset(buffer, 0, 256);

    n = read(sockfd,buffer,255);

    if (n < 0) 
        error("ERROR reading from socket");

    printf("%s\n",buffer);

    close(sockfd);

    return 0;
}