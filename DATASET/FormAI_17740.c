//FormAI DATASET v1.0 Category: Chat server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10

void error(char *message)
{
    perror(message);
    exit(1);
}

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        error("socket failed");
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
    {
        error("setsockopt");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        error("bind failed");
    }

    // Listening on the port 8080
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        error("listen");
    }

    // Accepting incoming connections
    while(1)
    {
    	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
	    {
	        error("accept");
	    }

	    // Creating a child process for every new client
	    int pid = fork();
	    if(pid < 0){
	    	error("fork");
	    }
	    if(pid == 0){
	    	//Closing the parent socket
	    	close(server_fd);
	    	
    		//Communicating with the client
    		while(1){
    			valread = read( new_socket , buffer, 1024);
	    		if(valread == 0){
	    			printf("Client disconnected.\n");
	    			close(new_socket);
	    			exit(0);
	    		}
	    		printf("Received Message from Client: %s\n",buffer );
	        	send(new_socket , hello , strlen(hello) , 0 );
	        	printf("Hello message sent to Client\n");
    		}
	    }
	    else{
	    	//Closing the child socket
	    	close(new_socket);
	    }
    }
    return 0;
}