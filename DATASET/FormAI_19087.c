//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <string.h>
#define ROWS 7
#define COLUMNS 5

void ascii_art_recursive(char chArray[], int start, int end);

int main() {
  char string[100];
  printf("Enter a string: ");
  fgets(string, 100, stdin);
  string[strcspn(string, "\n")] = 0;

  for (int i = 0; i < strlen(string); i++) {
    ascii_art_recursive(string, i, strlen(string));
    printf("\n");
  }
  return 0;
}

// define an array of ascii art characters
char asciiArray[26][ROWS][COLUMNS]= {
  {
    {' ', ' ', '*', ' ', ' '},
    {' ', '*', ' ', '*', ' '},
    {' ', '*', ' ', '*', ' '},
    {' ', '*', '*', '*', ' '},
    {' ', '*', ' ', '*', ' '},
    {' ', '*', ' ', '*', ' '},
    {' ', '*', ' ', '*', ' '}
  },
  // Repeat for other letters
  {
    {' ', ' ', '*', '*', ' '},
    {' ', '*', ' ', ' ', '*'},
    {' ', '*', ' ', ' ', '*'},
    {' ', '*', '*', '*', ' '},
    {' ', '*', ' ', ' ', '*'},
    {' ', '*', ' ', ' ', '*'},
    {' ', '*', '*', '*', ' '}
  },
  // and so forth for other letters
};

void ascii_art_recursive(char chArray[], int start, int end) {
  if (start == end) {
    return; // base case
  }
  int letter = chArray[start] - 'a';
  // check if letter is an alphabetical character
  if (letter >= 0 && letter <= 25) {
    // print the corresponding row of the ascii art character
    for (int i = 0; i < COLUMNS; i++) {
      printf("%c", asciiArray[letter][0][i]);
    }
  } else {
    printf("     "); // print five spaces
  }
  ascii_art_recursive(chArray, start + 1, end);
}