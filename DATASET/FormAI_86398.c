//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int packetLoss = rand() % 101; // Randomly generated percentage of packet loss
  int delay = rand() % 101; // Randomly generated delay
  
  printf("Welcome to the Network Quality of Service (QoS) Monitor!\n\n");
  printf("Current packet loss rate: %d%%\n", packetLoss);
  printf("Current delay: %d ms\n", delay);
  
  if(packetLoss == 0) { // If packet loss is 0, no issues!
    printf("Hooray! No packets lost!\n");
  }
  else if(packetLoss > 0 && packetLoss <= 10) {
    printf("Looks like we're experiencing some minor packet loss. Let's investigate...\n");
    printf("Checking for squirrels chewing on wires... \n");
    printf("Checking for gremlins in the router... \n");
    
    // Randomly either blame the user or the IT department
    if(rand() % 2 == 0) {
      printf("Ah, found the issue! Looks like someone downloaded too much cat videos...\n");
    }
    else {
      printf("Looks like the IT department needs to do some maintenance work. Classic IT...\n");
    }
  }
  else if(packetLoss > 10 && packetLoss <= 50) {
    printf("Uh oh, looks like we're experiencing some moderate packet loss. Let's investigate...\n");
    printf("Checking for alien interference... \n");
    
    // Randomly suggest restarting the router or just blame the government
    if(rand() % 2 == 0) {
      printf("Restarting the router may help. Have you tried turning it off and on again?\n");
    }
    else {
      printf("It's probably the government trying to spy on us. Let's blame them.\n");
    }
  }
  else { // Packet loss greater than 50%
    printf("Oh no! We've got some serious packet loss going on. Let's investigate...\n");
    printf("Checking for a black hole nearby... \n");
    
    // Randomly suggest using carrier pigeons instead of the internet or blame extraterrestrial beings
    if(rand() % 2 == 0) {
      printf("Maybe we should resort to carrier pigeons instead of the internet...\n");
    }
    else {
      printf("It's probably the extraterrestrial beings trying to sabotage us. Better call Will Smith.\n");
    }
  }
  
  // Check delay
  if(delay == 0) {
    printf("Awesome, no delay!\n");
  }
  else if(delay > 0 && delay <= 50) {
    printf("Looks like we're experiencing some minor delay. Let's investigate...\n");
    printf("Checking if the hamster running on the wheel is tired...\n");
    
    // Randomly suggest getting a faster hamster or blame the user's computer
    if(rand() % 2 == 0) {
      printf("Maybe we should get a faster hamster to run the internet...\n");
    }
    else {
      printf("Your computer is probably just old and slow. Time to upgrade!\n");
    }
  }
  else if(delay > 50 && delay <= 90) {
    printf("Uh oh, looks like we're experiencing some moderate delay. Let's investigate...\n");
    printf("Checking if the internet is stuck in traffic...\n");
    
    // Randomly suggest waiting it out or blaming the internet service provider
    if(rand() % 2 == 0) {
      printf("Let's just wait it out and hope the traffic clears up...\n");
    }
    else {
      printf("Those darn internet service providers are to blame for everything...\n");
    }
  }
  else { // Delay greater than 90 ms
    printf("Yikes, we've got some serious delay going on. Let's investigate...\n");
    printf("Checking if the internet is lost in space...\n");
    
    // Randomly suggest using a time machine or blame the government again
    if(rand() % 2 == 0) {
      printf("Maybe we need to use a time machine to fix this...\n");
    }
    else {
      printf("It's probably the government again. They're always to blame...\n");
    }
  }
  
  return 0;
}