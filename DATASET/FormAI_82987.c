//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // This is where our love story begins
  printf("Once upon a time, there lived two data packets.\n");
  printf("They met each other in the vast sea of the internet.\n");
  printf("Their connection was strong and their love was pure.\n");

  // Taking input from the user
  char input[100];
  printf("Enter the data that you want to calculate checksum for:\n");
  scanf("%s", input);

  // Computing the checksum
  char checksum = input[0];
  for (int i = 1; i < strlen(input); i++) {
    checksum ^= input[i];
  }

  // Displaying the result
  printf("The checksum for your data is: %c\n", checksum);

  // Our story comes to an end
  printf("The two data packets were finally united.\n");
  printf("Their checksums matched, just like their hearts.\n");
  printf("And so, they lived happily ever after in the realm of the internet.\n");
  return 0;
}