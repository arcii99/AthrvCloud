//FormAI DATASET v1.0 Category: Client Server Application ; Style: minimalist
//This is a basic C client server application example program

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int socket_desc, new_socket, c;
  struct sockaddr_in server, client;
  char *message;

  //Create socket
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
  }

  //Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 8888 );

  //Bind
  if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
    perror("bind failed. Error");
    return 1;
  }
  printf("bind done");

  //Listen
  listen(socket_desc , 3);

  //Accept and incoming connection
  printf("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);
  while((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
    printf("Connection accepted");

    //Reply to the client
    message = "Hello Client, I have received your connection. And now I will say: You are Connected!";
    write(new_socket , message , strlen(message));
  }

  if (new_socket<0) {
    perror("Accept failed");
    return 1;
  }

  return 0;
}