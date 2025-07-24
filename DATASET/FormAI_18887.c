//FormAI DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
  char htmlCode[10000];
  char htmlOutput[10000];
  int numTabs = 0;
  int i;

  printf("Enter your HTML code:\n");
  fgets(htmlCode, 10000, stdin);

  for(i = 0; i < strlen(htmlCode); i++) {
    if(htmlCode[i] == '<') {
      htmlOutput[i] = '\n';
      for(int j = 0; j < numTabs; j++)
        strcat(htmlOutput, "\t");
      numTabs++;
    }
    htmlOutput[strlen(htmlOutput)] = htmlCode[i];
    if(htmlCode[i] == '>') {
      htmlOutput[strlen(htmlOutput)] = '\n';
      numTabs--;
      for(int j = 0; j < numTabs; j++)
        strcat(htmlOutput, "\t");
    }
  }

  printf("\nYour beautified HTML code is:\n%s\n", htmlOutput);

  return 0;
}