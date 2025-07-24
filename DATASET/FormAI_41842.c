//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));  //initialize the random number generator

   int qos = 0;  //initialize quality of service variable to 0
   int packetSent = 0;  //initialize packet sent variable to 0
   int packetReceived = 0;  //initialize packet received variable to 0

   while(1) {
      int temp = rand() % 101;  //get random number between 0-100 for packet loss probability
      int packetLoss = (temp <= qos) ? 1 : 0;  //calculate packet loss based on qos and random number

      if(!packetLoss) {  //if packet is not lost
         packetSent++;  //increment packet sent counter

         int temp1 = rand() % 101;  //get random number between 0-100 for packet delay probability
         int packetDelay = (temp1 <= qos) ? 1 : 0;  //calculate packet delay based on qos and random number

         if(!packetDelay) {  //if packet is not delayed
            packetReceived++;  //increment packet received counter
         }
         else {
            printf("Packet %d delayed.\n", packetSent);  //print packet delay message
         }
      }
      else {
         printf("Packet %d lost.\n", packetSent+1);  //print packet loss message
      }

      qos = rand() % 101;  //get random number between 0-100 for qos of next packet

      printf("Current QoS: %d  Packets Sent: %d  Packets Received: %d\n", qos, packetSent, packetReceived);  //print current qos, packets sent and packets received information

      sleep(1);  //sleep for 1 second to simulate network activity
   }

   return 0;
}