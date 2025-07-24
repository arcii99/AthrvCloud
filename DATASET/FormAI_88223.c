//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){

  //Creating a socket with IPv4 protocol and TCP
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(server_fd == 0){
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  //Struct to store server details
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080);

  //Binding the socket to the IP address and port number
  int bind_status = bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address));
  if(bind_status < 0){
    perror("Binding failed");
    exit(EXIT_FAILURE);
  }

  //Listening for incoming connections
  int listen_status = listen(server_fd, 5);
  if(listen_status < 0){
    perror("Listening failed");
    exit(EXIT_FAILURE);
  }

  //Handling incoming connections
  int client_socket;
  while(1){

    //Accepting incoming connection
    if((client_socket = accept(server_fd, (struct sockaddr*)NULL, NULL)) < 0){
      perror("Accepting failed");
      exit(EXIT_FAILURE);
    }

    //Sending message to client
    char server_message[500] = "Welcome to the chat server! Type something to start the conversation.\n";
    send(client_socket, server_message, strlen(server_message), 0);

    //Receiving message from client
    char client_message[500];
    recv(client_socket, &client_message, sizeof(client_message), 0);
    printf("Client said: %s\n", client_message);

    //If client says bye, end the conversation
    if(strcmp(client_message, "bye") == 0){
      char server_bye_message[500] = "Goodbye! Have a nice day.\n";
      send(client_socket, server_bye_message, strlen(server_bye_message), 0);
      close(client_socket);
      break;
    }

    //Sending response to client
    char server_response[500] = "I am good. What about you?\n";
    send(client_socket, server_response, strlen(server_response), 0);

    //Receiving response from client
    recv(client_socket, &client_message, sizeof(client_message), 0);
    printf("Client said: %s\n", client_message);

    //If client says bye, end the conversation
    if(strcmp(client_message, "bye") == 0){
      char server_bye_message[500] = "Goodbye! Have a nice day.\n";
      send(client_socket, server_bye_message, strlen(server_bye_message), 0);
      close(client_socket);
      break;
    }

    //Closing the client socket
    close(client_socket);
  }

  //Closing the server socket
  close(server_fd);
  return 0;
}