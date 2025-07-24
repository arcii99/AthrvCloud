//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char pass[10];
  srand(time(NULL));

  printf("Secure Password Generator\n");
  printf("-------------------------\n");

  for(int i = 0; i < 10; i++) {
    int type = rand() % 3;

    switch(type) {
      case 0: pass[i] = rand() % 10 + 48; break;
      case 1: pass[i] = rand() % 26 + 65; break;
      case 2: pass[i] = rand() % 26 + 97; break;
    }
  }

  printf("Your password is: %s\n", pass);

  return 0;
}