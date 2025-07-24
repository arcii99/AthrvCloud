//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: funny
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char* argv[]){
  
  // creating a socket so that we can talk
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  // checking if the socket was created
  if(sock == -1){
    printf("Oh no, something went wrong with the socket creation! Let's try again another time.\n");
    return 1;
  }

  // defining the server address (where we want to talk to)
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET; // this means we are using the IPV4 protocol
  server_addr.sin_port = htons(8080); // the port number we want to talk to is 8080
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // the IP address of the server we want to talk to (in this case, our laptop)

  // let's try to connect to the server!
  int connection_status = connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

  // checking if the connection was successful
  if(connection_status == -1){
    printf("Uh-oh, something went wrong with the connection. Let's try again later!\n");
    return 1;
  }

  // if we made it here, that means we successfully made a connection!
  printf("Hello there, server! I am here to talk to you.\n");

  // now let's send a message to the server
  char message[1000];
  printf("What would you like to say to the server?\n");
  fgets(message, 1000, stdin);
  send(sock, message, strlen(message), 0);

  // let's wait for a response from the server
  char server_response[2000];
  recv(sock, server_response, sizeof(server_response), 0);

  // and let's print out what the server said
  printf("%s\n", server_response);

  // let's close the socket and end our conversation
  close(sock);
  printf("Goodbye, server! Until next time.\n");

  // we're done here!
  return 0;
}