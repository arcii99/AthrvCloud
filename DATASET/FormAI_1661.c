//FormAI DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

	// Create a TCP socket
	int server_fd;
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Error creating socket");
		exit(EXIT_FAILURE);
	}

	// Set socket options to reuse address
	int opt = 1;
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
		perror("Error setting socket options");
		exit(EXIT_FAILURE);
	}

	// Bind socket to localhost:8080
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
		perror("Error binding socket to port");
		exit(EXIT_FAILURE);
	}

	// Listen on socket for incoming connections
	if (listen(server_fd, 5) == -1) {
		perror("Error listening on socket");
		exit(EXIT_FAILURE);
	}

	printf("Server is listening on port %d\n", PORT);

	// Continuously accept incoming connections
	while(1) {
		struct sockaddr_in client_address;
		int addrlen = sizeof(client_address);

		// Accept incoming connection
		int client_fd;
		if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) == -1) {
			perror("Error accepting connection");
			exit(EXIT_FAILURE);
		}

		char buffer[BUFFER_SIZE] = {0};
		int bytes_received = read(client_fd, buffer, BUFFER_SIZE);

		if (bytes_received == -1) {
			perror("Error receiving data");
			exit(EXIT_FAILURE);
		}

		// Print received message
		printf("Received message from client: %s\n", buffer);

		// Reverse the message and send it back to client
		char response[BUFFER_SIZE] = {0};
		int j = 0;
		for (int i = strlen(buffer) - 1; i >= 0; i--) {
			response[j++] = buffer[i];
		}
		send(client_fd, response, strlen(response), 0);
		printf("Sent response to client: %s\n", response);

		close(client_fd);
	}

	return 0;
}