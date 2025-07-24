//FormAI DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

void *handle_messages(void *client_socket) {
  	int sock = *(int*)client_socket;
  	char message[1024];
  	while(1) {
    	memset(message, 0, sizeof(message));
    	if(recv(sock, message, 1024, 0) < 0) {
      		perror("Error receiving message");
      		close(sock);
      		pthread_exit(NULL);
    	}
    	printf("Message received from client %d: %s\n", sock, message);
    	if(strncmp(message, "exit", 4) == 0) {
      		if(send(sock, "Goodbye!", 8, 0) < 0) {
        		perror("Error sending message");
      		}
      		close(sock);
      		pthread_exit(NULL);
    	}
    	char *reply_message = "Message received by the server.";
    	if(send(sock, reply_message, strlen(reply_message), 0) < 0) {
      		perror("Error sending message");
      		close(sock);
      		pthread_exit(NULL);
    	}
  	}
}

int main() {
  	int server_socket, client_socket, opt = 1;
  	struct sockaddr_in server_address, client_address;
  	pthread_t thread_id[MAX_CLIENTS];
  	int client_count = 0;

  	if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    	perror("Error creating socket");
    	exit(EXIT_FAILURE);
  	}
  	if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    	perror("Error setting socket options");
    	exit(EXIT_FAILURE);
  	}
  	server_address.sin_family = AF_INET;
  	server_address.sin_addr.s_addr = INADDR_ANY;
  	server_address.sin_port = htons(PORT);

  	if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    	perror("Error binding the socket");
    	exit(EXIT_FAILURE);
  	}

  	if(listen(server_socket, 3) < 0) {
    	perror("Error listening to incoming connections");
    	exit(EXIT_FAILURE);
  	}

  	printf("Server is listening on port %d\n", PORT);

  	while(1) {
    	socklen_t client_size = sizeof(client_address);
    	if((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_size)) < 0) {
      		perror("Error accepting connection");
      		continue;
    	}
    	if(client_count < MAX_CLIENTS) {
      		if(pthread_create(&thread_id[client_count], NULL, handle_messages, (void *)&client_socket) < 0) {
        		perror("Error creating thread");
      		}
      		client_count++;
      		printf("Client %d connected.\n", client_socket);
      		char *welcome_message = "Welcome to the chat server. Type 'exit' to disconnect.";
      		send(client_socket, welcome_message, strlen(welcome_message), 0);
    	}
    	else {
      		char *max_clients_message = "The server has reached its maximum number of clients, please try again later.";
      		send(client_socket, max_clients_message, strlen(max_clients_message), 0);
      		close(client_socket);
      		continue;
    	}
  	}

  	return 0;
}