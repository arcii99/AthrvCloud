//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
 
void error(char *msg)
{
    perror(msg);
    exit(1);
}
 
int main(int argc, char *argv[])
{
    int sock, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
 
    char buffer[1024];
 
    if (argc < 3) 
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
 
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
        error("ERROR opening socket");
 
    server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
 
    if (connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
 
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
 
    n = write(sock,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
 
    bzero(buffer,1024);
    n = read(sock,buffer,1023);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    close(sock);
    return 0;
}