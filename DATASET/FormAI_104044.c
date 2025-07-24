//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>

int main() {
  char state = 'R';

  while(1) {
    switch(state) {
      case 'R':
        printf("RED\n");
        state = 'G';
        break;
      case 'G':
        printf("GREEN\n");
        state = 'Y';
        break;
      case 'Y':
        printf("YELLOW\n");
        state = 'R';
        break;
    }
  }
  return 0;
}