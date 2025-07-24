//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include<stdio.h>

int numPacketsRec = 0;
int numPacketsSent = 0;
int numPacketsLost = 0;

void detectAndReportIntrusion(int packetsReceived) {
  numPacketsRec += packetsReceived;

  // Detect intrusion if there is a sudden increase in packets received
  if ((numPacketsRec - numPacketsSent) >= 10) {
    printf("Possible intrusion detected!\n");
    printf("Num packets received: %d\n", numPacketsRec);
    printf("Num packets sent: %d\n", numPacketsSent);
    printf("Num packets lost: %d\n", numPacketsLost);
  }

  numPacketsSent += 10;
  numPacketsLost += (10 - packetsReceived);
  
  // Recursively call the function to detect intrusion on subsequent packets
  if(numPacketsSent <= 100) {
     detectAndReportIntrusion(packetsReceived+2);
  }
}

int main() {
  int packetsReceived = 10;
  detectAndReportIntrusion(packetsReceived);
  return 0;
}