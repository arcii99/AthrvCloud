//FormAI DATASET v1.0 Category: Networking ; Style: recursive
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

void process_request(int);

int main(int argc, char** argv){

  int sockfd, new_sockfd, clilen, pid;
  struct sockaddr_in serv_addr, cli_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0){
    perror("Could not create socket");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(1234);

  if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
    perror("Binding failed");
    exit(1);
  }

  listen(sockfd, MAX_CONNECTIONS);

  for(;;){

    clilen = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);

    /* Fork new process to handle incoming request */
    pid = fork();
    if (pid == 0){
        /* Child process */
        close(sockfd);
        process_request(new_sockfd);
        exit(0);
    }
    else if (pid < 0){
        perror("Could not fork new process");
        exit(1);
    }
    else{
        /* Parent process */
        close(new_sockfd);
    }
  }

  close(sockfd);
  return 0;
}

void process_request(int sockfd){

  char buffer[BUFFER_SIZE] = {0};
  int n = read(sockfd, buffer, sizeof(buffer));
  if(n < 0){
    perror("Could not read from socket");
    close(sockfd);
    return;
  }

  /* Process request recursively */
  int num = atoi(buffer);
  if(num == 1){
    write(sockfd, "1", 1);
    close(sockfd);
    return;
  }
  else{
    char response_buffer[BUFFER_SIZE] = {0};
    sprintf(response_buffer, "%d ", num);
    write(sockfd, response_buffer, strlen(response_buffer));

    /* Recursively process request */
    int next_num = num % 2 == 0 ? num / 2 : 3 * num + 1;
    process_request(sockfd);
  }
}