//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the Cheerful Checksum Calculator!\n");
  
  int checksum = 0;
  char input[100];
  printf("Enter a word or phrase to calculate the checksum: ");
  fgets(input, 100, stdin);
  
  int i = 0;
  while (input[i] != '\0') {
    checksum += input[i];
    i++;
  }

  printf("The checksum for \"%s\" is %d.\n", input, checksum);

  printf("Would you like to calculate another checksum? (Y/N)\n");
  char choice = getchar();

  if (choice == 'Y' || choice == 'y') {
    printf("Great! Let's calculate another checksum.\n");
    main(); // recursive call to calculate another checksum
  } else {
    printf("Thanks for using the Cheerful Checksum Calculator!\n");
    return 0;
  }
}