//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main(void) {
  char input_str[50];
  printf("Enter a string (maximum 50 characters):\n");
  fgets(input_str, 50, stdin);
  
  char processed_str[50];
  int i, j=0;
  int length = strlen(input_str);
  
  for(i=0; i<length; i++) {
    if(input_str[i] == ' ') {
      processed_str[j] = 'Z';
    }
    else if(input_str[i] == 'a') {
      processed_str[j] = 'o';
    }
    else if(input_str[i] == 'b') {
      processed_str[j] = 'p';
    }
    else if(input_str[i] == 'c') {
      processed_str[j] = 'q';
    }
    else if(input_str[i] == 'd') {
      processed_str[j] = 'r';
    }
    else if(input_str[i] == 'e') {
      processed_str[j] = 's';
    }
    else if(input_str[i] == 'f') {
      processed_str[j] = 't';
    }
    else if(input_str[i] == 'g') {
      processed_str[j] = 'u';
    }
    else if(input_str[i] == 'h') {
      processed_str[j] = 'v';
    }
    else if(input_str[i] == 'i') {
      processed_str[j] = 'w';
    }
    else if(input_str[i] == 'j') {
      processed_str[j] = 'x';
    }
    else if(input_str[i] == 'k') {
      processed_str[j] = 'y';
    }
    else if(input_str[i] == 'l') {
      processed_str[j] = 'z';
    }
    else if(input_str[i] == 'm') {
      processed_str[j] = 'a';
    }
    else if(input_str[i] == 'n') {
      processed_str[j] = 'b';
    }
    else if(input_str[i] == 'o') {
      processed_str[j] = 'c';
    }
    else if(input_str[i] == 'p') {
      processed_str[j] = 'd';
    }
    else if(input_str[i] == 'q') {
      processed_str[j] = 'e';
    }
    else if(input_str[i] == 'r') {
      processed_str[j] = 'f';
    }
    else if(input_str[i] == 's') {
      processed_str[j] = 'g';
    }
    else if(input_str[i] == 't') {
      processed_str[j] = 'h';
    }
    else if(input_str[i] == 'u') {
      processed_str[j] = 'i';
    }
    else if(input_str[i] == 'v') {
      processed_str[j] = 'j';
    }
    else if(input_str[i] == 'w') {
      processed_str[j] = 'k';
    }
    else if(input_str[i] == 'x') {
      processed_str[j] = 'l';
    }
    else if(input_str[i] == 'y') {
      processed_str[j] = 'm';
    }
    else if(input_str[i] == 'z') {
      processed_str[j] = 'n';
    }
    else if(input_str[i] == '\n') {
      processed_str[j] = '\0';
      break;
    }
    else {
      processed_str[j] = input_str[i];
    }
    j++;
  }

  printf("Processed string: %s", processed_str);
  return 0;
}