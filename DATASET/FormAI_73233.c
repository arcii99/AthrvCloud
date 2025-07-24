//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: careful
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 

#define PORT 8080 

int main() { 
	int sock_fd, new_socket, read_value; 
	struct sockaddr_in server_address, client_address; 
	int addrlen = sizeof(server_address); 
	char buffer[1024] = {0}; 
	char *reply = "Server received message"; 
	
	// Create socket file descriptor 
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd == -1) { 
		printf("Failed to create socket\n"); 
		exit(EXIT_FAILURE); 
	} 
	printf("Socket created successfully\n"); 

	// Assign IP and port to the server 
	server_address.sin_family = AF_INET; 
	server_address.sin_addr.s_addr = INADDR_ANY; 
	server_address.sin_port = htons(PORT); 
	
	// Bind the socket to the IP and port 
	if (bind(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) { 
		printf("Failed to bind to the IP and port\n"); 
		exit(EXIT_FAILURE); 
	} 
	printf("Bind successful\n"); 

	// Start listening for connections 
	if (listen(sock_fd, 3) < 0) { 
		printf("Failed to listen for connections\n"); 
		exit(EXIT_FAILURE); 
	} 
	printf("Listening for connections\n"); 

	// Accepting incoming connections 
	if ((new_socket = accept(sock_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen)) < 0) { 
		printf("Failed to accept incoming connections\n"); 
		exit(EXIT_FAILURE); 
	} 
	printf("Connection accepted\n"); 

	// Handling incoming messages 
	while (1) {
		// Read the incoming message 
		read_value = recv(new_socket, buffer, sizeof(buffer), 0); 
		printf("Incoming message: %s\n", buffer); 

		// If there are no more messages, close the socket 
		if (read_value == 0) { 
			printf("Client disconnected\n"); 
			close(new_socket); 
			break; 
		} 

		// Reply to the incoming message 
		send(new_socket, reply, strlen(reply), 0 ); 
		memset(buffer, 0, sizeof(buffer)); 
	} 

	return 0; 
}