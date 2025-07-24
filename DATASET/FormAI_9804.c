//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
void getString(char *str);
void reverseString(char *str);
void replaceChar(char *str, char oldChar, char newChar);
void removeSubString(char *str, char *subStr);

int main() {
  char str[100];
  int choice;

  do {
    printMenu();
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      getString(str);
      break;
    case 2:
      reverseString(str);
      break;
    case 3:
      char oldChar, newChar;
      getchar();
      printf("Enter the character to be replaced: ");
      scanf("%c", &oldChar);
      printf("Enter the new character: ");
      scanf(" %c", &newChar);
      replaceChar(str, oldChar, newChar);
      break;
    case 4:
      char subStr[20];
      printf("Enter the substring to be removed: ");
      scanf("%s", subStr);
      removeSubString(str, subStr);
      break;
    case 5:
      printf("Exiting program...");
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  } while (1);

  return 0;
}

void printMenu() {
  printf("\nAvailable options:\n");
  printf("1. Enter a string\n");
  printf("2. Reverse the string\n");
  printf("3. Replace a character in the string\n");
  printf("4. Remove a substring from the string\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
}

void getString(char *str) {
  printf("Enter a string: ");
  scanf("%s", str);
}

void reverseString(char *str) {
  int len = strlen(str);
  char *tempStr = (char *)malloc(len * sizeof(char));
  strcpy(tempStr, str);
  
  for (int i = 0; i < len; i++) {
    *(str+i) = *(tempStr+len-1-i);
  }

  free(tempStr);
  printf("Reversed string: %s\n", str);
}

void replaceChar(char *str, char oldChar, char newChar) {
  int len = strlen(str);

  for (int i = 0; i < len; i++) {
    if (*(str+i) == oldChar) {
      *(str+i) = newChar;
    }
  }

  printf("Modified string: %s\n", str);
}

void removeSubString(char *str, char *subStr) {
  int sLen = strlen(str);
  int subLen = strlen(subStr);
  int i, j;

  for (i = 0; i <= sLen-subLen; i++) {
    for (j = 0; j < subLen; j++) {
      if (*(str+i+j) != *(subStr+j)) {
        break;
      }
    }

    if (j == subLen) {
      break;
    }
  }

  if (i < sLen-subLen) {
    for (int k = i; k <= sLen-subLen; k++) {
      *(str+k) = *(str+k+subLen);
    }

    printf("Modified string: %s\n", str);
  } else {
    printf("Substring not found!\n");
  }
}