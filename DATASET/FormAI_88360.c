//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "4000"

struct addrinfo hints, *serverinfo, *p;
int sockfd;

void *sender(void *arg);
void *receiver();

int main(void) {
  int rc, len;
  pthread_t tid1, tid2;
  char rbuf[64];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;

  if ((rc = getaddrinfo(NULL, PORT, &hints, &serverinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rc));
    exit(1);
  }

  for (p = serverinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("Receiver: socket");
      continue;
    }

    if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("Receiver: bind");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "Receiver: failed to bind socket\n");
    exit(2);
  }

  printf("Receiver: waiting for sender..\n");

  if (pthread_create(&tid2, NULL, receiver, NULL) != 0) {
    perror("Receiver: pthread_create");
  }

  sleep(1);

  if (pthread_create(&tid1, NULL, sender, NULL) != 0) {
    perror("Sender: pthread_create");
  }

  pthread_join(tid1, NULL);

  sleep(1);

  close(sockfd);

  freeaddrinfo(serverinfo);

  return(0);
}

void *sender(void *arg) {
  int i, len,rc;
  struct timeval tv1, tv2, result;
  char sbuf[64], rbuf[64];
  struct sockaddr_storage their_addr;
  socklen_t addr_len;
  char ipstr[INET6_ADDRSTRLEN];

  memset(&hints, 0, sizeof hints);
  hints.ai_family=AF_UNSPEC;
  hints.ai_socktype=SOCK_DGRAM;
  hints.ai_flags=0;

  if ((rc = getaddrinfo("localhost", PORT, &hints, &serverinfo)) != 0) {
    fprintf(stderr, "Sender: getaddrinfo: %s\n", gai_strerror(rc));
    exit(1);
  }

  for (p = serverinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("Sender: socket");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "Sender: failed to bind socket\n");
    exit(2);
  }

  gettimeofday(&tv1, NULL);
  strcpy(sbuf, "test");
  len=strlen(sbuf);
  sendto(sockfd, sbuf, len, 0, p->ai_addr, p->ai_addrlen);

  printf("Sender: sent message\n");
  printf("Sender: waiting for response..\n");

  addr_len=sizeof their_addr;
  len=recvfrom(sockfd, rbuf, 64, 0, (struct sockaddr *)&their_addr, &addr_len);
  gettimeofday(&tv2, NULL);

  timersub(&tv2,&tv1,&result);
  printf("Elapsed time for check: %ld.%06lds\n", result.tv_sec, result.tv_usec);

  inet_ntop(their_addr.ss_family, &((struct sockaddr_in *)&their_addr)->sin_addr, ipstr, sizeof ipstr);
  printf("Sender: received response from %s\n", ipstr);

  close(sockfd);
  return(NULL);
}

void *receiver() {
  int i, len;
  char rbuf[64], sbuf[64];
  struct sockaddr_storage their_addr;
  socklen_t addr_len;
  char ipstr[INET6_ADDRSTRLEN];

  addr_len=sizeof their_addr;

  len=recvfrom(sockfd, rbuf, 64, 0, (struct sockaddr *)&their_addr, &addr_len);

  inet_ntop(their_addr.ss_family, &((struct sockaddr_in *)&their_addr)->sin_addr, ipstr, sizeof ipstr);
  printf("Receiver: received %d bytes from %s\n", len, ipstr);

  strcpy(sbuf, "OK");
  len=strlen(sbuf);

  sendto(sockfd, sbuf, len, 0, (struct sockaddr *)&their_addr, addr_len);
  sleep(1);

  return(NULL);
}