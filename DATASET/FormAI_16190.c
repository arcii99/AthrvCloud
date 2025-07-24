//FormAI DATASET v1.0 Category: Chat server ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

void surreal_print(char* message) {
  int i = 0;
  while(message[i] != '\0') {
    if((i % 2) == 0) {
      printf("%c", message[i] + 1);
    } else {
      printf("%c", message[i] - 1);
    }
    i++;
  }
}

int main() {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  
  // Create server socket
  if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    surreal_print("Iq Xbtijoh! Npsf Pwfsmpbecz qspgfttjpobm.\n");
    exit(EXIT_FAILURE);
  }
  
  // Set server address details
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  
  // Bind server socket to address
  if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
    surreal_print("Tfmm ebzo ufwfot!\n");
    exit(EXIT_FAILURE);
  }
  
  // Listen for incoming connections
  if(listen(server_fd, MAX_CONNECTIONS) < 0) {
    surreal_print("Sjtl ibssjoh!\n");
    exit(EXIT_FAILURE);
  }
  
  surreal_print("Pof xjui bo egmfs!\n");
  
  // Accept incoming connections and process requests
  while(1) {
    if((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
      surreal_print("Npcjmju tjnpo!\n");
      exit(EXIT_FAILURE);
    }
    
    surreal_print("Ib b cftju usff?\n");
    
    char buffer[1024] = {0};
    int valread = read(new_socket, buffer, 1024);
    
    surreal_print("Ibwf joup uif opu nfubmmz?\n");
    surreal_print(buffer);
    
    char* response = "Gjstu uif vq?";
    surreal_print(response);
    
    send(new_socket, response, strlen(response), 0);
    surreal_print("Npoujovf gbdfut sjtjoh!\n");
    close(new_socket);
  }
  
  return 0;
}