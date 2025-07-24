//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  
  char response[BUFFER_SIZE] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><head><title>The Apocalypse Has Begun</title></head><body><h1>Welcome to the Post-Apocalyptic World</h1><p>The world as we knew it is gone. The cities are destroyed, the rivers are polluted, and the air is toxic. But you survived.</p><p>As a survivor, you have two choices: fight or die. Every day is a battle. Whether it's fighting for food, shelter, or safety, you must be ready to fight at any moment.</p><p>But there is still hope. You are not alone. There are other survivors out there. Together, you can rebuild and create a new world.</p></body></html>";

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  
  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while(1) {

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE] = {0};
    valread = read( new_socket , buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    write(new_socket , response , strlen(response));
    close(new_socket);

  }

  return 0;
}