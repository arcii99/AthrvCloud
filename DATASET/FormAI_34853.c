//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define MAXLINE 1024
#define MAXTRIES 5
#define TIMEOUT 2

static int try = 0;
static int sockfd;

void sig_alrm(int signo) {
  if (try < MAXTRIES) {
    struct sockaddr_storage ss;
    socklen_t len;

    len = sizeof(ss);
    if (getpeername(sockfd, (struct sockaddr *) &ss, &len) == -1) {
      printf("Socket disconnected, reconnecting...\n");
      close(sockfd);
      try = 0;
      sleep(2);
      sockfd = -1;
    }
    else {
      printf("Timeout detected, retrying...\n");
      try++;
      alarm(TIMEOUT);
    }
  }
  else {
    printf("Max retries exceeded, cannot connect to server.\n");
    exit(1);
  }
}

void err_quit(char *msg) {
  printf("%s\n",msg);
  exit(1);
}

void init_sockaddr(struct sockaddr_in *serv_addr, char *ip, int port) {
  bzero((char *) serv_addr, sizeof(*serv_addr));
  serv_addr->sin_family = AF_INET;
  serv_addr->sin_addr.s_addr = inet_addr(ip);
  serv_addr->sin_port = htons(port);
}

int get_socket(char *ip, int port) {
  int sockfd;
  struct sockaddr_in serv_addr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    err_quit("Unable to create socket.");

  init_sockaddr(&serv_addr, ip, port);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    err_quit("Unable to connect to server.");

  return sockfd;
}

void send_packet(char *packet) {
  ssize_t n = write(sockfd, packet, strlen(packet));
  if (n < 0)
    err_quit("Error sending packet.");
}

void receive_packet(char *buf) {
  ssize_t n = read(sockfd, buf, MAXLINE - 1);
  if (n < 0)
    err_quit("Error receiving packet.");
  buf[n] = 0;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: ./qos_monitor <ip_address> <port_number>\n");
    exit(1);
  }
  signal(SIGALRM, sig_alrm);
  printf("Monitoring network quality of service...\n");

  while(1) {
    if (sockfd < 0) {
      sockfd = get_socket(argv[1], atoi(argv[2]));
      try = 1;
      alarm(TIMEOUT);
    }
    else {
      char buf[MAXLINE];
      send_packet("ping\n");
      receive_packet(buf);
      printf("QoS: %s\n",buf);
      sleep(1);
    }
  }
  exit(0);
}