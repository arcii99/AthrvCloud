//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert individual characters to Morse code
void MorseConvert(char letter) {
  switch (letter) {
    // Alphabets
    case 'A':
      printf(".- ");
      break;
    case 'B':
      printf("-... ");
      break;
    case 'C':
      printf("-.-. ");
      break;
    case 'D':
      printf("-.. ");
      break;
    case 'E':
      printf(". ");
      break;
    case 'F':
      printf("..-. ");
      break;
    case 'G':
      printf("--. ");
      break;
    case 'H':
      printf(".... ");
      break;
    case 'I':
      printf(".. ");
      break;
    case 'J':
      printf(".--- ");
      break;
    case 'K':
      printf("-.- ");
      break;
    case 'L':
      printf(".-.. ");
      break;
    case 'M':
      printf("-- ");
      break;
    case 'N':
      printf("-. ");
      break;
    case 'O':
      printf("--- ");
      break;
    case 'P':
      printf(".--. ");
      break;
    case 'Q':
      printf("--.- ");
      break;
    case 'R':
      printf(".-. ");
      break;
    case 'S':
      printf("... ");
      break;
    case 'T':
      printf("- ");
      break;
    case 'U':
      printf("..- ");
      break;
    case 'V':
      printf("...- ");
      break;
    case 'W':
      printf(".-- ");
      break;
    case 'X':
      printf("-..- ");
      break;
    case 'Y':
      printf("-.-- ");
      break;
    case 'Z':
      printf("--.. ");
      break;
    // Numbers
    case '1':
      printf(".---- ");
      break;
    case '2':
      printf("..--- ");
      break;
    case '3':
      printf("...-- ");
      break;
    case '4':
      printf("....- ");
      break;
    case '5':
      printf("..... ");
      break;
    case '6':
      printf("-.... ");
      break;
    case '7':
      printf("--... ");
      break;
    case '8':
      printf("---.. ");
      break;
    case '9':
      printf("----. ");
      break;
    case '0':
      printf("----- ");
      break;
    // Space
    case ' ':
      printf("/ ");
      break;
    // Default case
    default:
      printf("");
  }
}

// Function to convert entire string to Morse code
void ConverttoMorse(char string[]) {
  // Loop to iterate through the characters of the string
  for (int i = 0; i < strlen(string); i++) {
    // Convert individual character to Morse code
    MorseConvert(toupper(string[i]));
  }
  // Print a new line character at the end
  printf("\n");
}

// Function to print romantic code
void print_romantic() {
  printf("My love, I have written you a code.\n");
  printf("You are the light of my life and the muse to my code.\n");
  printf("I start with a dash and end with a dot.\n");
  printf("Some may say it's just gibberish, but to me it means a lot.\n");
  printf("I write to you in Morse code, the language of love.\n");
  printf("My words may be simple, but they speak to my heart above.\n");
  printf("I write to you of your beauty and grace.\n");
  printf("Of your eyes, of your smile, of your lovely face.\n");
  printf("I write to you of our memories and our future together.\n");
  printf("Of our love, of our laughter, of our forever.\n");
  printf("So here it is, my love, in Morse code for you.\n");
  printf("I love you more than words can say, and I always will do.\n");
}

int main() {
  // Print the romantic code
  print_romantic();
  // User input for the string to be converted to Morse code
  char string[100];
  printf("Enter the string to be converted to Morse code: ");
  fgets(string, 100, stdin);
  // Call the function to convert the string to Morse code
  ConverttoMorse(string);
  return 0;
}