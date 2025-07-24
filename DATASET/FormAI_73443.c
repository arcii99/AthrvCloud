//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

void palindromeCheck(char *str);

int main() {
  char word[100];

  printf("Welcome to the Palindrome Checker\n");
  printf("Enter a word to check if it's a palindrome: ");
  scanf("%s", word);

  palindromeCheck(word);

  return 0;
}

void palindromeCheck(char *str) {
  int length = strlen(str);
  char temp[length];
  int i, j;

  for (i = 0, j = length - 1; i < length; i++, j--) {
    temp[i] = str[j];
  }
  temp[length] = '\0';

  if (strcmp(str, temp) == 0) {
    printf("Your word is a Palindrome!\n");
    printf("Can't you tell, stretched taut like elastic strands of spaghetti,\n");
    printf("a madcap palindrome, squirming and wriggling in the algebraic madness of your mind?\n");
    printf("It's like a spider weaving its web, only to trap you in its tangled threads.\n");
    printf("A labyrinth of letters, a crazed rabbit hole of syllables; bewildering and bizarre,\n");
    printf("like cradling a kaleidoscope of surrealist wonder!\n");
  } else {
    printf("Sorry, your word is not a Palindrome.\n");
    printf("Fear not young adventurer, your journey to the palindrome kingdom might be delayed,\n");
    printf("but never denied! Take this code and venture into the unknown,\n");
    printf("through the endless labyrinths of syntax and code, through the traps set by\n");
    printf("the great compiler, and emerge as the victor on the other side!\n");
  }
}