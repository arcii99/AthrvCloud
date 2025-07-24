//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to the C Checksum Calculator!\n");
  printf("Enter a string to calculate its checksum:\n");
  char input[50];
  scanf("%s", input);
  
  int checksum = 0;
  int i;
  for (i = 0; i < strlen(input); i++) {
    int character = input[i];
    checksum += character;
  }
  
  printf("The checksum of %s is %d\n", input, checksum);
  
  printf("Would you like to calculate another checksum? (y/n)\n");
  char again;
  scanf("%s", &again);
  
  if (again == 'y') {
    printf("Great! Let's calculate another checksum.\n");
    main();
  } else {
    printf("Thanks for using the C Checksum Calculator!\n");
    return 0;
  }
}