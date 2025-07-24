//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long hash(unsigned char *str){
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}

int main() {
  char msg[] = "This is a unique C Cryptographic hash function example program";
  printf("Calculating the hash of the message '%s'...\n", msg);
  
  unsigned long result = hash(msg);
  printf("The hash result is %lu\n", result);
  
  return 0;
}