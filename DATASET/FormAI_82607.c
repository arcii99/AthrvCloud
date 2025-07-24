//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 8080

void error(char *msg)
{
  perror(msg);
  exit(1);
}

int main()
{
  int sockfd,newsockfd,clientlen;
  struct sockaddr_in serv_addr,cli_addr;

  sockfd=socket(AF_INET,SOCK_STREAM,0);

  if(sockfd<0)
  {
    error("Error opening socket");
  }

  bzero((char *)&serv_addr,sizeof(serv_addr));

  serv_addr.sin_family=AF_INET;
  serv_addr.sin_addr.s_addr=INADDR_ANY;
  serv_addr.sin_port=htons(PORT);

  if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
  {
    error("Binding Error");
  }

  listen(sockfd,5);

  while(1)
  {
    clientlen=sizeof(cli_addr);

    newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clientlen);

    if(newsockfd<0)
    {
      error("Error accepting");
    }

    char buffer[256];
    bzero(buffer,sizeof(buffer));

    int n=read(newsockfd,buffer,255);

    if(n<0)
    {
      error("Error reading from socket");

    } 

    printf("Client request:%s\n",buffer);

    int httpfd=socket(AF_INET,SOCK_STREAM,0);

    if(httpfd<0)
    {
      error("Error opening http socket");
    }

    struct sockaddr_in http_addr;

    bzero((char *)&http_addr,sizeof(http_addr));
    http_addr.sin_family=AF_INET;
    http_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    http_addr.sin_port=htons(8888);

    if(connect(httpfd,(struct sockaddr *)&http_addr,sizeof(http_addr))<0)
    {
      error("Error connecting to http server");
    }

    n=write(httpfd,buffer,strlen(buffer));

    if(n<0)
    {
      error("Error writing to http server");
    }

    bzero(buffer,sizeof(buffer));

    n=read(httpfd,buffer,sizeof(buffer));

    if(n<0)
    {
      error("Error reading from http server");
    }

    printf("Server response:%s\n",buffer);

    n=write(newsockfd,buffer,strlen(buffer));

    if(n<0)
    {
      error("Error writing to socket");
    }

    close(newsockfd);
    close(httpfd);

    printf("Connection closed\n");

  }

  close(sockfd);

  return 0;

}