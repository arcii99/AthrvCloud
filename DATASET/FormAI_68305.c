//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>

// Function to convert c_alien language to english
void c_alien_to_english(char c_alien[]) {
    int i, j = 0;
    char english[50];
    for (i = 0; c_alien[i] != '\0'; i++) {
        switch (c_alien[i]) {
            case 'A': english[j] = 'a';
                      j++;
                      break;
            case 'B': english[j] = 'b';
                      j++;
                      break;
            case 'C': english[j] = 'c';
                      j++;
                      break;
            case 'D': english[j] = 'd';
                      j++;
                      break;
            case 'E': english[j] = 'e';
                      j++;
                      break;
            case 'F': english[j] = 'f';
                      j++;
                      break;
            case 'G': english[j] = 'g';
                      j++;
                      break;
            case 'H': english[j] = 'h';
                      j++;
                      break;
            case 'I': english[j] = 'i';
                      j++;
                      break;
            case 'J': english[j] = 'j';
                      j++;
                      break;
            case 'K': english[j] = 'k';
                      j++;
                      break;
            case 'L': english[j] = 'l';
                      j++;
                      break;
            case 'M': english[j] = 'm';
                      j++;
                      break;
            case 'N': english[j] = 'n';
                      j++;
                      break;
            case 'O': english[j] = 'o';
                      j++;
                      break;
            case 'P': english[j] = 'p';
                      j++;
                      break;
            case 'Q': english[j] = 'q';
                      j++;
                      break;
            case 'R': english[j] = 'r';
                      j++;
                      break;
            case 'S': english[j] = 's';
                      j++;
                      break;
            case 'T': english[j] = 't';
                      j++;
                      break;
            case 'U': english[j] = 'u';
                      j++;
                      break;
            case 'V': english[j] = 'v';
                      j++;
                      break;
            case 'W': english[j] = 'w';
                      j++;
                      break;
            case 'X': english[j] = 'x';
                      j++;
                      break;
            case 'Y': english[j] = 'y';
                      j++;
                      break;
            case 'Z': english[j] = 'z';
                      j++;
                      break;
            case '/': english[j] = ' ';
                      j++;
                      break;
        }
    }
    english[j] = '\0';
    // Print the translated text
    printf("English: %s\n", english);
}

int main() {
    char c_alien[50];
    printf("Enter c_alien language text: ");
    fgets(c_alien, 50, stdin); // Use fgets to read input with spaces
    c_alien_to_english(c_alien);
    return 0;
}