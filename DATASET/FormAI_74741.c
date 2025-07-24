//FormAI DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {

  char fair_maiden[50]; // define a string to hold thy fair maiden's name
  printf("Fair lady, what be thy name?\n"); // prompt the user to enter the name
  scanf("%s", fair_maiden); // store the name in the string

  char fair_sir[50]; // define a string to hold thy fair sir's name
  printf("And what be thy noble suitor's name, my dear %s?\n", fair_maiden); // prompt the user to enter the name
  scanf("%s", fair_sir); // store the name in the string

  char love_letter[1000]; // define a string to store the love letter
  printf("Oh, %s, what passion burns within my breast for thee!\n", fair_maiden); // profess one's love in an olde English style
  printf("My %s, thou hast captured my heart with thy beauty and grace,\n", fair_sir); // continue with the proclamation of love
  printf("Thy eyes are as bright as the stars in the heavens above.\n"); // add some poetic imagery

  printf("Pray, let us communicate in a secret tongue that none can understand,\n"); // introduce the text processing part
  printf("For our love be as forbidden as that of Romeo and Juliet's land.\n");

  printf("Enter thy secret message, my love:\n"); // prompt for the secret message
  scanf(" %[^\n]s", love_letter); // scan for the entire line

  int length = strlen(love_letter); // get the length of the string

  // loop through each character in the string
  for (int i = 0; i < length; i++) {
    // encrypt every vowel with the next letter in the alphabet
    if (love_letter[i] == 'a' || love_letter[i] == 'e' || love_letter[i] == 'i' || love_letter[i] == 'o' || love_letter[i] == 'u' ||
        love_letter[i] == 'A' || love_letter[i] == 'E' || love_letter[i] == 'I' || love_letter[i] == 'O' || love_letter[i] == 'U') {
      printf("%c", love_letter[i] + 1); // print out the encrypted character
    } else { // else, print the character as is
      printf("%c", love_letter[i]);
    }
  }

  printf("\nThou hast my heart, my %s, and I shall love thee forevermore!\n", fair_maiden); // end the love letter
  return 0; // exit the program
}