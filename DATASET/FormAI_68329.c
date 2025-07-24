//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[1000];
  char summary[300];
  
  printf("Please enter text to be summarized: ");
  fgets(text, 1000, stdin);

  // Surrealist text summarizer algorithm
  int i = 0, j = 0;
  while (text[i] != '\0') {
    switch (text[i]) {
      case 'a':
        summary[j] = 'z';
        break;
      case 'b':
        summary[j] = 'f';
        break;
      case 'c':
        summary[j] = 'q';
        break;
      case 'd':
        summary[j] = 'j';
        break;
      case 'e':
        summary[j] = 'x';
        break;
      case 'f':
        summary[j] = 'p';
        break;
      case 'g':
        summary[j] = 'm';
        break;
      case 'h':
        summary[j] = 'k';
        break;
      case 'i':
        summary[j] = 'o';
        break;
      case 'j':
        summary[j] = 'a';
        break;
      case 'k':
        summary[j] = 't';
        break;
      case 'l':
        summary[j] = 's';
        break;
      case 'm':
        summary[j] = 'y';
        break;
      case 'n':
        summary[j] = 'd';
        break;
      case 'o':
        summary[j] = 'e';
        break;
      case 'p':
        summary[j] = 'r';
        break;
      case 'q':
        summary[j] = 'u';
        break;
      case 'r':
        summary[j] = 'c';
        break;
      case 's':
        summary[j] = 'g';
        break;
      case 't':
        summary[j] = 'v';
        break;
      case 'u':
        summary[j] = 'i';
        break;
      case 'v':
        summary[j] = 'b';
        break;
      case 'w':
        summary[j] = 'n';
        break;
      case 'x':
        summary[j] = 'l';
        break;
      case 'y':
        summary[j] = 'h';
        break;
      case 'z':
        summary[j] = 'w';
        break;
      default:
        summary[j] = text[i];
    }
    i++;
    j++;
  }
  summary[j] = '\0';
  
  printf("Surrealist summary: %s\n", summary);

  return 0;
}