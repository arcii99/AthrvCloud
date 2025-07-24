//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Linus Torvalds
/* As inspired by Linus Torvalds, this program implements a basic TCP/IP chat server that allows multiple clients to communicate with each other */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_fds[MAX_CLIENTS]; // array to store client file descriptors
int num_clients = 0; // number of current connected clients
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // mutex lock for multithreading

// function for handling client requests
void *handle_client(void *client_fd) {
  int fd = *(int*)client_fd;
  char buffer[BUFFER_SIZE] = {0};
  while(1) {
    int read_len = read(fd, buffer, BUFFER_SIZE);
    if(read_len<0) {
      perror("Error reading client message");
      break;
    }
    if(read_len==0) {
      printf("Client disconnected\n");
      break;
    }
    pthread_mutex_lock(&lock);
    for(int i=0;i<num_clients;i++) {
      if(client_fds[i] != fd) {
        write(client_fds[i], buffer, strlen(buffer));
      }
    }
    pthread_mutex_unlock(&lock);
    bzero(buffer, BUFFER_SIZE);
  }
  pthread_mutex_lock(&lock);
  for(int i=0;i<num_clients;i++) {
    if(client_fds[i] == fd) {
      for(int j=i;j<num_clients-1;j++) {
        client_fds[j] = client_fds[j+1];
      }
      break;
    }
  }
  num_clients--;
  pthread_mutex_unlock(&lock);
  close(fd);
  pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};

  // create socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
  }

  // set socket options to reuse address and port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
  }

  // set address parameters
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );

  // bind socket to address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  if (listen(server_fd, MAX_CLIENTS) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
  }

  printf("Server running on port %d\n", PORT);

  // handle incoming connections
  while(1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // add new client to client_fds array and launch new thread to handle client requests
    pthread_mutex_lock(&lock);
    client_fds[num_clients] = new_socket;
    num_clients++;
    pthread_mutex_unlock(&lock);

    pthread_t new_thread;
    if(pthread_create(&new_thread, NULL, handle_client, (void*)&new_socket) < 0) {
      perror("Error creating thread");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}