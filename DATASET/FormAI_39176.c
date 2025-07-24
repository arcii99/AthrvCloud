//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NETWORK_USERS 100
#define MAX_DELAY 1000 //in ms
#define MAX_BANDWIDTH 500 //in KB/s
#define MAX_PACKET_LOSS 10 //in percentage

//global variables
int networkLoad = 0;
int currentDelay = 0;
int currentBandwidth = 0;
int currentPacketLoss = 0;

//function to generate random delay
int generateDelay() {
  int delay = rand() % MAX_DELAY; //generate random delay between 0 and MAX_DELAY
  return delay;
}

//function to generate random bandwidth
int generateBandwidth() {
  int bandwidth = rand() % MAX_BANDWIDTH; //generate random bandwidth between 0 and MAX_BANDWIDTH
  return bandwidth;
}

//function to generate random packet loss
int generatePacketLoss() {
  int packetLoss = rand() % MAX_PACKET_LOSS; //generate random packet loss between 0 and MAX_PACKET_LOSS
  return packetLoss;
}

//function to update network QoS values
void updateNetworkQoS() {
  int numUsers = rand() % MAX_NETWORK_USERS + 1; //generate random number of users between 1 and MAX_NETWORK_USERS
  networkLoad = numUsers * 10; //assign network load based on number of users
  currentDelay = generateDelay();
  currentBandwidth = generateBandwidth();
  currentPacketLoss = generatePacketLoss();
}

//function to print network QoS values
void printNetworkQoS() {
  printf("Network QoS: Load=%d%%, Delay=%dms, Bandwidth=%dKB/s, Packet Loss=%d%%\n", networkLoad, currentDelay, currentBandwidth, currentPacketLoss);
}

int main() {
  //seed random number generator
  srand(time(NULL));
  
  //initialize network QoS values
  updateNetworkQoS();
  
  printf("Welcome to the Network Quality of Service (QoS) Monitor!\n\n");
  
  //main loop
  while(1) {
    //update network QoS values
    updateNetworkQoS();
    
    //print network QoS values
    printNetworkQoS();
    
    //wait for 5 seconds
    sleep(5);
  }
  
  return 0;
}