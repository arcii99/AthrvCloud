//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str) {
  int i, n;
  char temp;

  n = strlen(str);

  for (i = 0; i < n / 2; i++) {
    temp = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }
}

void remove_duplicates(char* str) {
  int len = strlen(str);
  int idx = 0;
  int i, j;

  for (i = 0; i < len; i++) {
    for (j = 0; j < i; j++) {
      if (str[i] == str[j]) {
        break;
      }
    }

    if (j == i) {
      str[idx++] = str[i];
    }
  }

  str[idx] = '\0';
}

void replace_substring(char* str, char* sub, char* new_str) {
  int sub_len = strlen(sub);
  int new_len = strlen(new_str);
  char buffer[1000];
  char* start = str;
  char* found;

  while ((found = strstr(start, sub))) {
    strncpy(buffer, str, found - str);
    buffer[found - str] = '\0';
    strcat(buffer, new_str);
    strcat(buffer, found + sub_len);
    strcpy(str, buffer);
    start = str + strlen(buffer);
  }
}

int main() {
  char string[] = "abbbcdefffffghiiiiklllmnoooopqrrrrstu";
  char substring[] = "fff";
  char newstring[] = "zzz";

  printf("Original string: %s\n", string);

  //Reverse the string
  reverse(string);
  printf("Reversed string: %s\n", string);

  //Remove duplicates from the string
  remove_duplicates(string);
  printf("String with duplicates removed: %s\n", string);

  //Replace a substring in the string
  replace_substring(string, substring, newstring);
  printf("String with substring replaced: %s\n", string);

  return 0;
}