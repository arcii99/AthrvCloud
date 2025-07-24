//FormAI DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void handle_request(int socket);

int main() {
	struct sockaddr_in server_address, client_address;
	int server_socket, client_socket, client_address_length;

	// Create server socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket < 0) {
		perror("Fail to create server socket!\n");
		exit(EXIT_FAILURE);
	}

	// Bind server socket to port
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(SERVER_PORT);
	if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
		perror("Fail to bind server socket!\n");
		exit(EXIT_FAILURE);
	}

	// Listen for incoming connections
	if (listen(server_socket, 10) < 0) {
		perror("Fail to listen on server socket!\n");
		exit(EXIT_FAILURE);
	}

	// Accept incoming connections and handle requests
	while (1) {
		client_address_length = sizeof(client_address);
		client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &client_address_length);
		if (client_socket < 0) {
			perror("Failed to accept incoming connection!\n");
			exit(EXIT_FAILURE);
		}
		handle_request(client_socket);
		close(client_socket);
	}
}

void handle_request(int socket) {
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	int file_fd;
	struct stat file_stat;

	// Read request from client
	bytes_read = read(socket, buffer, BUFFER_SIZE-1);
	if (bytes_read < 0) {
		perror("Failed to read request from client!\n");
		exit(EXIT_FAILURE);
	}
	buffer[bytes_read] = '\0'; // Null terminate the string

	// Extract file path from request
	char *path = strtok(buffer, " ");
	path = strtok(NULL, " ");
	if (path == NULL) {
		write(socket, "HTTP/1.1 400 Bad Request\r\n\r\n", strlen("HTTP/1.1 400 Bad Request\r\n\r\n"));
		exit(EXIT_SUCCESS);
	}
	path++; // Remove leading slash from path

	// Open requested file
	file_fd = open(path, O_RDONLY);
	if (file_fd < 0) {
		perror("Failed to open requested file!\n");
		write(socket, "HTTP/1.1 404 Not Found\r\n\r\n", strlen("HTTP/1.1 404 Not Found\r\n\r\n"));
		exit(EXIT_SUCCESS);
	}

	// Retrieve file stats
	if (fstat(file_fd, &file_stat) < 0) {
		perror("Failed to retrieve file stats!\n");
		write(socket, "HTTP/1.1 500 Internal Server Error\r\n\r\n", strlen("HTTP/1.1 500 Internal Server Error\r\n\r\n"));
		exit(EXIT_SUCCESS);
	}

	// Write response headers to client
	char response_header[BUFFER_SIZE];
	sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n", file_stat.st_size);
	write(socket, response_header, strlen(response_header));

	// Write file contents to client
	char file_buffer[BUFFER_SIZE];
	ssize_t bytes_sent, bytes_remaining = file_stat.st_size;
	while (bytes_remaining > 0) {
		bytes_read = read(file_fd, file_buffer, BUFFER_SIZE);
		if (bytes_read < 0) {
			perror("Failed to read from file!");
			exit(EXIT_SUCCESS);
		}
		bytes_sent = 0;
		while (bytes_sent < bytes_read) {
			bytes_sent += write(socket, file_buffer + bytes_sent, bytes_read - bytes_sent);
			if (bytes_sent < 0) {
				perror("Failed to write to client!");
				exit(EXIT_SUCCESS);
			}
		}
		bytes_remaining -= bytes_read;
	}

	close(file_fd);
}