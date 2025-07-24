//FormAI DATASET v1.0 Category: Networking ; Style: artistic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int main() {
   int socket_desc, client_sock, c, new_sock;
   struct sockaddr_in server, client;
   char *message, client_message[2000];
   
   // Create socket
   socket_desc = socket(AF_INET , SOCK_STREAM , 0);
   if (socket_desc == -1) {
      printf("Error: Could not create socket");
   }
   puts("Socket created");
   
   // Set server variables 
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons( 8888 );
   
   // Bind socket to the address 
   if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
       perror("Error: Bind failed. Error");
       return 1;
   } 
   puts("Bind done");
   
   // Listen for incoming connections
   listen(socket_desc , 3);
   
   // Accept incoming connection
   puts("Waiting for incoming connections...");
   c = sizeof(struct sockaddr_in);
   while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
   {
      puts("Connection accepted");
      
      // Receive messages from client
      while( (new_sock = recv(client_sock, client_message, 2000, 0)) > 0 ) {
         printf("Message from client: %s", client_message);
         fflush(stdout);
         
         // Respond to client 
         message = "Server: Message received";
         write(client_sock , message , strlen(message));
      }
      if(new_sock == 0) {
         puts("Client Disconnected");
         fflush(stdout);
      } else if(new_sock == -1) {
         perror("Error: Receive failed");
      }
   }
   
   // Close sockets
   close(client_sock);
   close(socket_desc);
   
   return 0;
}