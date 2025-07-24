//FormAI DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
/*
 * Romeo and Juliet - A Networking Example Program
 * By AI Chatbot
 */

// In fair Verona where we lay our scene,
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// From ancient grudge break to new mutiny,
#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

struct sockaddr_in server;

// Where civil blood makes civil hands unclean.
void die(char *s)
{
  perror(s);
  exit(1);
}

// A pair of star-crossed sockets take their life.
int main(int argc, char *argv[])
{
  int socket_fd, conn_fd, read_val;
  char buffer[BUFFER_SIZE];

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(socket_fd == -1)
  {
    die("socket() error");
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(SERVER_PORT);

  if(bind(socket_fd, (struct sockaddr *)&server, sizeof(server)) == -1)
  {
    die("bind() error");
  }

  if(listen(socket_fd, 5) == -1)
  {
    die("listen() error");
  }

  printf("Waiting for incoming connections...\n");

  conn_fd = accept(socket_fd, NULL, NULL);
  if(conn_fd == -1)
  {
    die("accept() error");
  }

  printf("Connection established!\n");

  while(1)
  {
    memset(buffer, 0, BUFFER_SIZE);
    read_val = read(conn_fd, buffer, BUFFER_SIZE);

    if(read_val == -1)
    {
      die("read() error");
    }

    if(strcmp(buffer, "exit") == 0)
    {
      printf("Closing the connection...\n");
      break;
    }

    printf("Message received: %s\n", buffer);
  }

  close(conn_fd);
  close(socket_fd);
  return 0;
}