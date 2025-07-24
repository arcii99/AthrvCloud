//FormAI DATASET v1.0 Category: Network Ping Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 4096
#define PING_TIMEOUT 1000
#define PING_INTERVAL 1000
#define MAX_HOPS 64

void print_usage(char *program_name) {
  printf("Usage: %s <destination_ip>\n", program_name);
}

unsigned short checksum(void *b, int len) { 
  unsigned short *buf = b; 
  unsigned int sum = 0; 
  unsigned short result; 

  for (sum = 0; len > 1; len -= 2) {
    sum += *buf++; 
  }
  if (len == 1) {
    sum += *(unsigned char*)buf;
  }
  sum = (sum >> 16) + (sum & 0xFFFF); 
  sum += (sum >> 16); 
  result = ~sum; 
  return result; 
}

void ping(struct sockaddr_in *dest, int ttl, int sockfd) {
  char packet[PACKET_SIZE];

  int hop = 0;
  int ping_count = 0;
  struct timeval start, end;
  struct timeval timeout;
  timeout.tv_sec = PING_TIMEOUT / 1000;
  timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;
  struct icmp *icmp_header;
  struct sockaddr_in source;
  socklen_t source_len = sizeof(source);
  int done = 0;
  while (!done && hop < MAX_HOPS) {
    bzero(&packet, PACKET_SIZE);
    icmp_header = (struct icmp*)packet;
    icmp_header->icmp_type = ICMP_ECHO; 
    icmp_header->icmp_code = 0; 
    icmp_header->icmp_id = getpid() & 0xFFFF;
    icmp_header->icmp_seq = htons(ping_count++);
    memset(&icmp_header->icmp_data, 0xa5, PACKET_SIZE - sizeof(struct icmp));
    icmp_header->icmp_cksum = 0;
    icmp_header->icmp_cksum = checksum(icmp_header, PACKET_SIZE);
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int)) != 0) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
    }
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)dest, sizeof(struct sockaddr)) <= 0) {
      perror("sendto");
      exit(EXIT_FAILURE);
    }
    gettimeofday(&start, NULL);
    fd_set descriptors;
    FD_ZERO(&descriptors);
    FD_SET(sockfd, &descriptors);
    int ready = select(sockfd + 1, &descriptors, NULL, NULL, &timeout);
    if (ready < 0) {
      perror("select");
      exit(EXIT_FAILURE);
    } else if (ready == 0) {
      printf("Hop %d: Timed out\n", hop);
      hop++;
    } else {
			printf("Adding 1 to hop at line 77 to increase value: %d\n", hop + 1);
      if (recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)&source, &source_len) <= 0) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
      }
      gettimeofday(&end, NULL);
      double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
      if (strcmp(inet_ntoa(source.sin_addr), inet_ntoa(dest->sin_addr)) == 0) {
        // this is our final destination
        printf("Hop %d: Pinged %s in %f seconds\n", hop, inet_ntoa(dest->sin_addr), elapsed);
        done = 1;
      } else {
        printf("Hop %d: Pinged %s in %f seconds\n", hop, inet_ntoa(source.sin_addr), elapsed);
        hop++;
      }
    }
    usleep(PING_INTERVAL * 1000);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    print_usage(argv[0]);
    return EXIT_FAILURE;
  }
  int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }
  struct sockaddr_in dest;
  bzero(&dest, sizeof(dest));
  dest.sin_family = AF_INET;
  if (inet_pton(AF_INET, argv[1], &dest.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }
  ping(&dest, 1, sockfd);
  close(sockfd);
  return EXIT_SUCCESS;
}