//FormAI DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

// Define Constants
#define PORT 5555
#define MAX_CONN 10
#define MAX_DATA 256

int main(int argc, char* argv[]){
	int server_sock, client_sock, ret_val, i, read_size, max_clients = MAX_CONN;
	int client_sockets[max_clients];
	struct sockaddr_in server, client;
	char client_message[MAX_DATA], message[MAX_DATA];

	// Initialize socket file descriptor
	server_sock = socket(AF_INET, SOCK_STREAM, 0);

	// Make sure socket was successfully created
	if(server_sock == -1){
		perror("Socket Error");
		exit(EXIT_FAILURE);
	}

	// Define socket structure and bind to local address and port
	server.sin_family = AF_INET; // Set IPv4 Family
	server.sin_addr.s_addr = INADDR_ANY; // Get IP of local machine (0.0.0.0)
	server.sin_port = htons(PORT); // Define port to listen on

	// Bind Socket to Port and Address
	if(bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0){
		perror("Bind Error");
		exit(EXIT_FAILURE);
	}

	// Start listening for incoming connections
	listen(server_sock, MAX_CONN);

	// Set Socket to Non-Blocking Mode
	fcntl(server_sock, F_SETFL, O_NONBLOCK);

	// Print Server Status Update
	printf("Server up and running! Waiting for connections...\n");

	// Loop to handle incoming client connections and messages
	while(1){
		// Check for incoming connections
		client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&max_clients);

		// Check if client was successfully accepted
		if(client_sock >= 0){
			printf("New connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
			for(i=0;i<max_clients;i++){
				// Check for open socket in array
				if(client_sockets[i] == 0){
					client_sockets[i] = client_sock;
					printf("Connection added to the list of active clients\n");
					break;
				}
			}
		}

		// Loop through all active sockets and handle incoming messages
		for(i=0;i<max_clients;i++){
			if(client_sockets[i] > 0){
				if(recv(client_sockets[i], client_message, MAX_DATA, 0) > 0 ){
					// Clear message buffer
					memset(message, 0, MAX_DATA);
					// Print incoming message
					printf("%s\n", client_message);
					// Prepare Response Message
					snprintf(message, MAX_DATA, "Message Received: %s\n", client_message);
					// Send Response to Client
					write(client_sockets[i], message, strlen(message));
				}
				else{
					// Remove client from active sockets list and set socket to 0
					printf("Connection closed by client %d\n", i);
					client_sockets[i] = 0;
				}
			}
		}
	}

	return EXIT_SUCCESS;
}