//FormAI DATASET v1.0 Category: System event logger ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* message){
  time_t now;
  now = time(NULL);
  printf("[%s] %s\n", ctime(&now), message);
}

int main(){
  int i, x, y, sum;

  log_event("Starting program...");

  srand(time(NULL));

  for(i=0; i<10; i++){
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    sum = x + y;

    char event_msg[100];
    sprintf(event_msg, "Iteration %d: Generated %d and %d, sum is %d", i+1, x, y, sum);
    log_event(event_msg);
  }

  log_event("Program ended.");

  return 0;
}