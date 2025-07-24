//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  //set seed for random number generator
  srand(time(NULL));
  
  //define arrays of conspiracy theory keywords
  char* noun[] = {"Illuminati", "government", "aliens", "Big Pharma", "FEMA"};
  char* verb[] = {"control", "manipulate", "brainwash", "suppress", "enslave"};
  char* adjective[] = {"secret", "powerful", "sinister", "elitist", "occult"};
  
  //generate random conspiracy theory
  int n = rand() % 5;
  int v = rand() % 5;
  int a = rand() % 5;
  
  //print conspiracy theory to console
  printf("Did you know that the %s is trying to %s us with their %s agenda?\n", adjective[a], verb[v], noun[n]);

  return 0;
}