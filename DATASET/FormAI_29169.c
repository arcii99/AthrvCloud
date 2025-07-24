//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define MAXLINE 8192
#define PORT 8080

void handle(int connfd);

int main(int argc, char** argv){
  int listenfd, connfd, port, pid;
  socklen_t clilen;
  struct sockaddr_in cliaddr, servaddr;

  port = PORT;

  if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  servaddr.sin_port = htons(port);

  if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  if(listen(listenfd, 10) == -1) {
    perror("Error listening to socket");
    exit(EXIT_FAILURE);
  }

  printf("Server running on port %d\n", port);

  while(1){
    clilen = sizeof(cliaddr);

    if((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen)) == -1){
      perror("Error accepting connection from client");
      exit(EXIT_FAILURE);
    }

    if((pid=fork()) == 0){
      close(listenfd);
      handle(connfd);
      close(connfd);
      exit(EXIT_SUCCESS);
    }

    close(connfd);
  }

  close(listenfd);
  return 0;
}

void handle(int connfd){
  int n, len, i, fd, error;
  char buffer[MAXLINE], method[10], url[MAXLINE], protocol[10], hostname[MAXLINE], path[MAXLINE];
  struct hostent *he;
  struct sockaddr_in addr;

  //read the request from the client
  n = read(connfd, buffer, MAXLINE);

  if(n == -1){
    perror("Error reading from client");
    return;
  }

  sscanf(buffer, "%s %s %s", method, url, protocol);

  //strip off http:// if it exists
  strcpy(hostname, url);
  if(strncmp(hostname, "http://", 7) == 0){
    strcpy(hostname, &url[7]);
  }

  //get the hostname and the path
  for(i = 0; i < strlen(hostname); i++){
    if(hostname[i] == '/'){
      strcpy(path, &hostname[i]);
      hostname[i] = '\0';
      break;
    }
  }

  he = gethostbyname(hostname);

  if(he == NULL){
    perror("Error getting host by name");
    return;
  }

  bzero((char*)&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);
  addr.sin_addr = *((struct in_addr*)he->h_addr);

  //connect to the server
  if((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
    perror("Error creating socket");
    return;
  }

  if(connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1){
    perror("Error connecting to server");
    return;
  }

  //write the request to the server
  if(write(fd, buffer, n) == -1){
    perror("Error writing to server");
    return;
  }

  //read the response from the server and write it to the client
  while((n = read(fd, buffer, MAXLINE)) > 0){
    if(write(connfd, buffer, n) == -1){
      perror("Error writing to client");
      return;
    }
  }

  close(fd);
}