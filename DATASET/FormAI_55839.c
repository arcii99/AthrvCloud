//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
//Visionary C RAM Usage Monitor
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
  int i=0;
  printf("Starting Visionary C RAM Usage Monitor\n");
  while(i<50){ //Monitor for 50 seconds
    int* arr = (int*) malloc(sizeof(int)*1000000); //Allocate memory for integers
    if(arr == NULL){ //Check if memory allocation failed
      printf("Memory allocation failed! Exiting...\n");
      exit(0);
    }
    sleep(1);
    i++;
    free(arr); //Free up the memory
  }
  printf("Finished monitoring RAM usage.\n");
  return 0;
}