//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>

int main() {
  char input[100];
  int positiveCount = 0, negativeCount = 0;
  while(1) {
    printf("Speaketh your mind, and I shalt analyzeth thy sentiment: ");
    fgets(input, 100, stdin);
    
    if (input[0] == 'q') {
      printf("Farewell, traveller.\n");
      break;
    }
    
    if (strstr(input, "nay") != NULL || strstr(input, "neigh") != NULL) {
      printf("My liege, thou art quite negative. Verily, thy score is -5\n");
      negativeCount++;
    } else {
      printf("Thou speakest well of this matter. Thy score is 5\n");
      positiveCount++;
    }
    
    printf("Positive comments: %d\tNegative comments: %d\n", positiveCount, negativeCount);
  }
  return 0;
}