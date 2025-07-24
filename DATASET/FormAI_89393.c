//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

// define traffic signals
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// define traffic light timer values in seconds
#define RED_TIMER 10
#define YELLOW_TIMER 2
#define GREEN_TIMER 15

// define boolean variables for the status of each traffic light
bool northSouthGreen = false;
bool eastWestGreen = false;

// define thread variables for each traffic light
pthread_t northSouthThread;
pthread_t eastWestThread;

// define mutex lock for thread synchronization
pthread_mutex_t trafficMutex = PTHREAD_MUTEX_INITIALIZER;

// function to handle traffic flow for north-south direction
void *northSouthTrafficFlow(void *arg) {
  while(true) {
    // set north-south traffic light to green
    pthread_mutex_lock(&trafficMutex);
    northSouthGreen = true;
    eastWestGreen = false;
    pthread_mutex_unlock(&trafficMutex);
    
    printf("North-South Traffic Light: Green\n");
    sleep(GREEN_TIMER);
    
    // set north-south traffic light to yellow
    pthread_mutex_lock(&trafficMutex);
    northSouthGreen = false;
    pthread_mutex_unlock(&trafficMutex);
    
    printf("North-South Traffic Light: Yellow\n");
    sleep(YELLOW_TIMER);
    
    // set north-south traffic light to red
    pthread_mutex_lock(&trafficMutex);
    northSouthGreen = false;
    eastWestGreen = true;
    pthread_mutex_unlock(&trafficMutex);
    
    printf("North-South Traffic Light: Red\n");
    sleep(RED_TIMER);
  }
  pthread_exit(NULL);
}

// function to handle traffic flow for east-west direction
void *eastWestTrafficFlow(void *arg) {
  while(true) {
    // set east-west traffic light to green
    pthread_mutex_lock(&trafficMutex);
    eastWestGreen = true;
    northSouthGreen = false;
    pthread_mutex_unlock(&trafficMutex);
    
    printf("East-West Traffic Light: Green\n");
    sleep(GREEN_TIMER);
    
    // set east-west traffic light to yellow
    pthread_mutex_lock(&trafficMutex);
    eastWestGreen = false;
    pthread_mutex_unlock(&trafficMutex);
    
    printf("East-West Traffic Light: Yellow\n");
    sleep(YELLOW_TIMER);
    
    // set east-west traffic light to red
    pthread_mutex_lock(&trafficMutex);
    eastWestGreen = false;
    northSouthGreen = true;
    pthread_mutex_unlock(&trafficMutex);
    
    printf("East-West Traffic Light: Red\n");
    sleep(RED_TIMER);
  } 
  pthread_exit(NULL);
}

int main() {
  // initialize random seed for traffic light synchronization
  srand(time(NULL));
  
  int rc1, rc2;
  
  // create threads for each traffic flow direction
  rc1 = pthread_create(&northSouthThread, NULL, northSouthTrafficFlow, NULL);
  if (rc1) {
    printf("Error:unable to create north-south traffic flow thread.\n");
    exit(-1);
  }
  
  rc2 = pthread_create(&eastWestThread, NULL, eastWestTrafficFlow, NULL);
  if (rc2) {
    printf("Error:unable to create east-west traffic flow thread.\n");
    exit(-1);
  }
  
  // join threads to ensure full execution
  pthread_join(northSouthThread, NULL);
  pthread_join(eastWestThread, NULL);
  
  return 0;
}