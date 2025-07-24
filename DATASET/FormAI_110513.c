//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include<stdio.h>
#include<string.h>

void make_uppercase(char str[]) {
  int len = strlen(str);
  
  for(int i=0; i<len; i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32; // ASCII value difference between lowercase and uppercase letters
    }
  }
}

void remove_punctuation(char str[]) {
  int len = strlen(str);
  
  for(int i=0; i<len; i++) {
    if(str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':') {
      for(int j=i; j<len; j++) {
        str[j] = str[j+1];
      }
      i--; // update the index since the current character has been removed
      len--; // update the length of the string since a character has been removed
    }
  }
}

int main() {
  char str[100];
  
  printf("Enter a string: ");
  scanf("%[^\n]s", str); // allow spaces in the string input
  
  make_uppercase(str);
  
  printf("String in uppercase: %s\n", str);
  
  remove_punctuation(str);
  
  printf("String with punctuation removed: %s\n", str);
  
  return 0;
}