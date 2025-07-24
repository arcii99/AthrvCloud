//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: high level of detail
#include <stdio.h>

// Function to convert a character to Morse code
void convertToMorse(char c) {

  switch (c) {

    // Letters
    case 'A': printf(".- "); break;
    case 'B': printf("-... "); break;
    case 'C': printf("-.-. "); break;
    case 'D': printf("-.. "); break;
    case 'E': printf(". "); break;
    case 'F': printf("..-. "); break;
    case 'G': printf("--. "); break;
    case 'H': printf(".... "); break;
    case 'I': printf(".. "); break;
    case 'J': printf(".--- "); break;
    case 'K': printf("-.- "); break;
    case 'L': printf(".-.. "); break;
    case 'M': printf("-- "); break;
    case 'N': printf("-. "); break;
    case 'O': printf("--- "); break;
    case 'P': printf(".--. "); break;
    case 'Q': printf("--.- "); break;
    case 'R': printf(".-. "); break;
    case 'S': printf("... "); break;
    case 'T': printf("- "); break;
    case 'U': printf("..- "); break;
    case 'V': printf("...- "); break;
    case 'W': printf(".-- "); break;
    case 'X': printf("-..- "); break;
    case 'Y': printf("-.-- "); break;
    case 'Z': printf("--.. "); break;

    // Numbers
    case '0': printf("----- "); break;
    case '1': printf(".---- "); break;
    case '2': printf("..--- "); break;
    case '3': printf("...-- "); break;
    case '4': printf("....- "); break;
    case '5': printf("..... "); break;
    case '6': printf("-.... "); break;
    case '7': printf("--... "); break;
    case '8': printf("---.. "); break;
    case '9': printf("----. "); break;

    // Space
    case ' ': printf("/ "); break;

    // Default case for unsupported characters
    default: printf("* ");
  }
}

int main() {

  // Input string
  char str[100];

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  // Loop through each character in the string and convert to Morse code
  for (int i = 0; str[i]; i++) {
    convertToMorse(toupper(str[i])); // Convert to upper case before conversion
  }

  return 0;
}