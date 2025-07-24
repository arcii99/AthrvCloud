//FormAI DATASET v1.0 Category: Simple Web Server ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

int main()
{
  printf("Hello! I am a curious web server.\n");
  printf("I will listen on http://localhost:%d\n", PORT);
  
  int server_fd, new_sock, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
  
  // Creating socket file descriptor 
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
      perror("socket failed");
      return -1;
  }
  
  // Attach socket to the port 8080 
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
  {
      perror("setsockopt failed");
      return -1;
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );
  
  // Bind the socket to localhost
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
  {
      perror("bind failed");
      return -1;
  }
  
  // Listen for incoming connections
  if (listen(server_fd, 3) < 0)
  {
      perror("listen failed");
      return -1;
  }
  
  printf("Waiting for incoming connections...\n");
  while(1){
      if ((new_sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
      {
          perror("accept failed");
          return -1;
      }
      
      //Receive a message from client
      valread = read( new_sock , buffer, 1024);
      printf("%s\n",buffer );
      
      // Send response to the client
      write(new_sock , response , strlen(response));
      printf("Response sent\n");
  }
  return 0;
}