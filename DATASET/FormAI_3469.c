//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  srand(time(NULL)); // initialize random seed
  
  int network_status = 1; // initialize network status
  int quality_of_service = 0; // initialize quality of service
  
  // post-apocalyptic style message
  printf("Initializing QoS monitor in post-apocalyptic world...Fight for survival!\n");
  
  while(network_status) {
    
    // simulate random network disturbances
    int disturbance = rand() % 10 + 1;
    if(disturbance <= 3) {
      quality_of_service -= 3;
      printf("WARNING: Network disturbance detected! QoS reduced by 3.\n");
    }
    else if(disturbance <= 6) {
      quality_of_service -= 2;
      printf("Network disturbance detected. QoS reduced by 2.\n");
    }
    else if(disturbance <= 8) {
      quality_of_service -= 1;
      printf("Minor network disturbance detected. QoS reduced by 1.\n");
    }
    else {
      quality_of_service += 1;
      printf("Network operating at nominal conditions. QoS improved by 1.\n");
    }
    
    // check for QoS threshold breach
    if(quality_of_service <= -10) {
      printf("CRITICAL: QoS has dropped below threshold. Aborting network...\n");
      network_status = 0;
    }
    else if(quality_of_service < 0) {
      printf("WARNING: QoS nearing threshold. Take action to improve...\n");
    }
    else {
      printf("Network QoS status: %d\n", quality_of_service);
    }
    
    // simulate delay between checks
    int delay = rand() % 3;
    sleep(delay);
  }
  
  return 0;
}