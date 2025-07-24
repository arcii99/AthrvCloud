//FormAI DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int isPrime(int num) {
  int i;
  for(i = 2; i <= num/2; i++) {
    if(num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  char *host = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);
  
  int sock;
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(host);
  
  int current_port, is_prime;
  for(current_port = start_port; current_port <= end_port; current_port++) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    target.sin_port = htons(current_port);
    if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
      is_prime = isPrime(current_port);
      if(is_prime) {
        printf("Port %d is open and prime!\n", current_port);
      } else {
        printf("Port %d is open but not prime :(\n", current_port);
      }
    }
    close(sock);
  }
  return 0;
}