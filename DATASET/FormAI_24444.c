//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include<stdio.h>
#include<string.h>

int main() {
  char message[50]; 
  int sum = 0, i;

  printf("Enter Message: ");
  scanf("%s", message);

  for (i = 0; i < strlen(message); i++) {
    sum += (int) message[i];
  }

  printf("Checksum Value: %d\n", sum);

  return 0;
}