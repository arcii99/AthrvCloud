//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
   int socket_desc, new_socket, c;
   struct sockaddr_in server, client;
   char *message, client_message[2000];

   //Create socket
   socket_desc = socket(AF_INET, SOCK_STREAM, 0);
   if (socket_desc == -1)
   {
       printf("Could not create socket");
   }

   //Prepare the sockaddr_in structure
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons(8888);

   //Bind
   if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
   {
       //print the error message
       perror("Bind failed. Error");
       return 1;
   }
   puts("Bind done");

   //Listen
   listen(socket_desc, 3);

   //Accept and incoming connection
   puts("Waiting for incoming connections...");
   c = sizeof(struct sockaddr_in);

     //Continuous Loop for accepting ever-changing shape shifters
    while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c)))
    {
       puts("Connection accepted");

       //Reply to the client message
       message = "Hello Shape Shifter, I detected your presence!\n";
       write(new_socket, message, strlen(message));

       //Receive from client
       while (read(new_socket, client_message, 2000) > 0)
       {
          printf("Client message: %s", client_message);

          //Reverse the message and send it back to the client
          char *reversed_message = strdup(client_message);
          int len = strlen(reversed_message);
          for (int i = 0; i < len / 2; i++)
          {
             char temp = reversed_message[i];
             reversed_message[i] = reversed_message[len - i - 1];
             reversed_message[len - i - 1] = temp;
          }

          write(new_socket, reversed_message, strlen(reversed_message));
       }

       if (new_socket < 0)
       {
          perror("Accept failed");
          return 1;
       }
    }

   return 0;
}