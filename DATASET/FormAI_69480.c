//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
/* This program is a simple client-server chatroom using TCP/IP socket programming. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]){
	int sockfd, newsockfd, portno, n;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;

	if (argc < 2){
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr,
	         sizeof(serv_addr)) < 0)
	         error("ERROR on binding");

	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	printf("**SERVER STARTED**\n");

	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0)
		error("ERROR on accept");

	printf("**CLIENT CONNECTED**\nEnter 'exit' to quit\n");

	while(1){
		bzero(buffer,256);
		n = read(newsockfd,buffer,255);
		if (n < 0) error("ERROR reading from socket");

		printf("Client: %s", buffer);

		if (strcmp(buffer, "exit\n") == 0){
			printf("**CLIENT DISCONNECTED**\n");
			break;
		}

		printf("Server: ");
		bzero(buffer,256);
		fgets(buffer,255,stdin);

		n = write(newsockfd,buffer,strlen(buffer));
		if (n < 0) error("ERROR writing to socket");
	}

	close(newsockfd);
	close(sockfd);
	return 0;
}