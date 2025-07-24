//FormAI DATASET v1.0 Category: Socket programming ; Style: systematic
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
  
#define BUF_SIZE 1024  
  
int main(int argc, char *argv[]) {  
  int sock_desc;  
  struct sockaddr_in serv_addr;    
  char buffer[BUF_SIZE];  
  char *req = "Hello Server";  
  char *ip = "127.0.0.1";  
  int port = 5555;  
    
  // create socket  
  sock_desc = socket(AF_INET, SOCK_STREAM, 0);  
  if(sock_desc == -1) {  
    printf("Error creating socket");  
    return -1;  
  }  
  
  // server details  
  memset(&serv_addr, 0, sizeof(serv_addr));  
  serv_addr.sin_family = AF_INET;  
  serv_addr.sin_addr.s_addr = inet_addr(ip);  
  serv_addr.sin_port = htons(port);  

  // connect to server  
  if(connect(sock_desc, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {  
    printf("Error connecting to remote server\n");  
    return -1;  
  }  
    
  // send data to server  
  if(send(sock_desc, req, strlen(req), 0) < 0) {
    printf("Error in sending data to server");  
    return -1;  
  }  
    
  // receive data from server  
  while(recv(sock_desc, buffer, BUF_SIZE, 0) > 0) {  
    printf("%s", buffer);  
    memset(buffer, 0, BUF_SIZE);  
  }  
    
  close(sock_desc);  
  return 0;  
}