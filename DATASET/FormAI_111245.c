//FormAI DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  printf("Welcome to the Ultimate String Processor!\n\n");

  char str[1000];
  int choice;
  char c = ' ';
  do {
    printf("Enter your string (max 1000 characters):\n");
    scanf("%[^\n]s", str);

    printf("\n\nWhat would you like to do with your string?\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Reverse String\n");
    printf("4. Count Number of Words\n");
    printf("5. Count Number of Vowels\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6):\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        for(int i = 0; i < strlen(str); i++) {
          str[i] = toupper(str[i]);
        }
        printf("\n\nThe string in UPPERCASE is: %s\n\n", str);
        break;
      case 2:
        for(int i = 0; i < strlen(str); i++) {
          str[i] = tolower(str[i]);
        }
        printf("\n\nThe string in lowercase is: %s\n\n", str);
        break;
      case 3:
        for(int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
          c = str[i];
          str[i] = str[j];
          str[j] = c;
        }
        printf("\n\nThe reverse string is: %s\n\n", str);
        break;
      case 4:
        int word_count = 1;
        for(int i = 0; i < strlen(str); i++) {
          if(str[i] == ' ') {
            word_count++;
          }
        }
        printf("\n\nThe number of words in the string is: %d\n\n", word_count);
        break;
      case 5:
        int vowel_count = 0;
        for(int i = 0; i < strlen(str); i++) {
          if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
             str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowel_count++;
          }
        }
        printf("\n\nThe number of vowels in the string is: %d\n\n", vowel_count);
        break;
      case 6:
        printf("Thank you for using the Ultimate String Processor. Goodbye!\n\n");
        break;
      default:
        printf("Invalid choice! Try again.\n\n");
        break;
    }

    // flush input if not reached end of line
    while((c = getchar()) != '\n' && c != EOF);

  } while(choice != 6);

  return 0;
}