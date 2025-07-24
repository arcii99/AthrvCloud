//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define BUFLEN 512  //maximum length of buffer
#define PORT 8888   //port on which the scanner program will listen

int main(void) {
    struct sockaddr_in si_me, si_other;
    int s, i, slen=sizeof(si_other);
    char buf[BUFLEN];
     
    //create a socket
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1) {
        perror("socket");
        exit(1);
    }
     
    //zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));
     
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
     
    //bind socket to specific IP and port
    if (bind(s,(struct sockaddr*)&si_me, sizeof(si_me))==-1) {
        perror("bind");
        exit(1);
    }
     
    //configure the socket to receive broadcast packets
    int broadcastEnable=1;
    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));

    int timeout = 5; // receive timeout in seconds
    int packetsToReceive = 10; // expected number of packets
    int packetCounter = 0; // actual number of packets received

    while (packetCounter < packetsToReceive) {
      memset(buf, '\0', BUFLEN);
      
      //wait for data
      if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)==-1) {
          perror("recvfrom()");
          exit(1);
      }

      //extract information from the received packet
      char ip_address[16];
      memset(ip_address, '\0', sizeof(ip_address));
      inet_ntop(AF_INET, &(si_other.sin_addr), ip_address, INET_ADDRSTRLEN);

      char ssid[33];
      memset(ssid, '\0', sizeof(ssid));
      memcpy(ssid, buf + 26, buf[25]);

      char enc_mode[9];
      memset(enc_mode, '\0', sizeof(enc_mode));
      switch ((unsigned char) buf[63]) {
          case 0:
              strcpy(enc_mode, "Open");
              break;
          case 1:
              strcpy(enc_mode, "WEP");
              break;
          case 2:
              strcpy(enc_mode, "WPA");
              break;
          case 3:
              strcpy(enc_mode, "WPA2");
              break;
          case 4:
              strcpy(enc_mode, "WPA/WPA2");
              break;
          default:
              strcpy(enc_mode, "Unknown");
              break;
      }

      //print the received information on the console
      printf("Received packet from %s:%d\n", ip_address, ntohs(si_other.sin_port));
      printf("SSID: %s\n", ssid);
      printf("Encryption Mode: %s\n", enc_mode);
      printf("---------------------------\n");

      packetCounter++;

      //wait for the specified timeout before receiving the next packet
      sleep(timeout);
    }
 
    close(s);
    return 0;
}