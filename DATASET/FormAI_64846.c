//FormAI DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>

int main() {

printf("Welcome to the most exciting text processing program written in C!\n");

// Initializing variables
char text[100];
int vowels = 0, consonants = 0, digits = 0, spaces = 0;

printf("\nEnter any text and let the magic begin: \n");
fgets(text, sizeof(text), stdin);

// Processing text
for (int i = 0; text[i] != '\0'; ++i) {
  
      if (isalpha(text[i])) {
            // Checking vowels
            if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
                ++vowels;
            }
            // Checking consonants
            else {
                ++consonants;
            }
      }
      // Checking digits
      else if (isdigit(text[i])) {
            ++digits;
      }
      // Checking spaces
      else if (text[i] == ' ') {
            ++spaces;
      }
}

printf("\nHey, This is amazing! Your text contains:\n");
printf("Vowels: %d\n", vowels);
printf("Consonants: %d\n", consonants);
printf("Digits: %d\n", digits);
printf("Spaces: %d\n", spaces);

return 0;
}