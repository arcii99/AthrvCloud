//FormAI DATASET v1.0 Category: Networking ; Style: Alan Touring
//This program creates a client-server communication using sockets
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

//Error message function
void error(const char *msg){
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]){
  int sockfd, newsockfd, portno, clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  //Check if necessary arguments have been entered
  if(argc < 2){
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }

  //Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0)
    error("ERROR opening socket");

  //Set sock address with zero
  bzero((char *) &serv_addr, sizeof(serv_addr));

  //Get port number from argument and set the socket address
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  //Bind socket
  if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  //Listen for incoming connections
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  //Accept incoming connections
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if(newsockfd < 0)
    error("ERROR on accept");

  //Print message to confirm server and client are connected
  printf("Server and client are connected.\n");

  //Main conversation loop
  while(1){
    bzero(buffer, 256);

    //Read from socket
    n = read(newsockfd, buffer, 255);
    if(n < 0)
      error("ERROR reading from socket");

    //Print message from client
    printf("Client: %s\n", buffer);

    //Prompt user for message
    printf("Server: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    //Send message to client
    n = write(newsockfd, buffer, strlen(buffer));
    if(n < 0)
      error("ERROR writing to socket");

    //Check if user wants to quit
    if(strncmp("bye", buffer, 3) == 0)
      break;
  }

  //Close sockets
  close(newsockfd);
  close(sockfd);

  return 0;
}