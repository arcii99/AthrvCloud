//FormAI DATASET v1.0 Category: Chat server ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>

int main(){
   int server_fd;
   struct sockaddr_in address;
   int addrlen = sizeof(address);
   char buffer[1024] = "Hey! This is my first Chat server example program in C. Let's chat.\n";
   
   if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
      perror("Socket failed");
      exit(EXIT_FAILURE);
   }
   
   address.sin_family = AF_INET; 
   address.sin_addr.s_addr = INADDR_ANY; 
   address.sin_port = htons( 8080 );
   
   if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
      perror("Bind failed");
      exit(EXIT_FAILURE);
   }
   
   if (listen(server_fd, 3) < 0){ 
      perror("Listen failed");
      exit(EXIT_FAILURE);
   }
   
   printf("Chat Server is ready to talk!\n");
   int new_socket;
   if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
      perror("Accept failed");
      exit(EXIT_FAILURE);
   }
   
   send(new_socket, buffer, strlen(buffer), 0);
   printf("Message sent, start chatting!\n");
   
   while(1){
      memset(buffer, 0, sizeof(buffer));
      recv(new_socket, buffer, 1024, 0);
      
      if(strcmp(buffer, "bye\n") == 0){
         printf("User Disconnected\n");
         break;
      }
      
      char message[1024] = "You said: ";
      strcat(message, buffer);
      send(new_socket, message, strlen(message), 0);
   }
   close(new_socket);
   close(server_fd);
   return 0;
}