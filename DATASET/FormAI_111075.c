//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int length;
  char* password;

  printf("Enter length of password: ");
  scanf("%d", &length);

  password = (char*) malloc(length * sizeof(char));

  if (password == NULL) {
    printf("Error: Unable to allocate memory!\n");
    return -1;
  }

  srand(time(NULL));  // Reset random generator each time program is run

  // Create a randomly generated password
  for (int i = 0; i < length; i++) {
    password[i] = rand() % 94 + 33;  // ASCII characters from '!' to '~'
  }

  printf("\nGenerated password: %s\n", password);

  free(password);

  return 0;
}