//FormAI DATASET v1.0 Category: Simple Web Server ; Style: genious
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080

int main()
{
  	int server_fd, new_socket, valread;
  	struct sockaddr_in address;
  	int addrlen = sizeof(address);
  	char buffer[1024] = {0};
  	const char *message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

  	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  	{
    		perror("socket failed");
    		exit(EXIT_FAILURE);
  	}

  	address.sin_family = AF_INET;
  	address.sin_addr.s_addr = INADDR_ANY;
  	address.sin_port = htons(PORT);

  	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
  	{
    		perror("bind failed");
    		exit(EXIT_FAILURE);
  	}

  	if (listen(server_fd, 3) < 0)
  	{
    		perror("listen");
    		exit(EXIT_FAILURE);
  	}

  	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
  	{
    		perror("accept");
    		exit(EXIT_FAILURE);
  	}

  	// Read request
  	valread = read(new_socket, buffer, 1024);
  	
  	// Check for GET request
  	if(strncmp(buffer, "GET", 3) == 0) {
  		// Send response
  		send(new_socket, message, strlen(message), 0);
  	} else {
  		char *err_msg = "HTTP/1.1 400 Bad Request\nContent-Type: text/plain\nContent-Length: 17\n\nBad request, man!";
  		// Send response
  		send(new_socket, err_msg, strlen(err_msg), 0);
  	}

  	close(new_socket);
  	close(server_fd);
  	return 0;
}