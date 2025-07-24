//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>

int main() {
  char input[100], output[100];
  int i = 0, j = 0;
  
  printf("Enter some text: ");
  fgets(input, 100, stdin);
  
  //Trimming leading and trailing whitespaces
  while(isspace((unsigned char)input[i])) i++;
  while(input[j+1]) j++;
  while(isspace((unsigned char)input[j])) j--;
  for(int k=i; k<=j; k++) {
    output[k-i] = input[k];
  }
  output[j-i+1] = '\0';
  
  //Converting everything to lowercase
  for(int l=0; l<j-i+1; l++) {
    output[l] = tolower(output[l]);
  }
  
  //Replacing all special characters with spaces
  for(int m=0; m<j-i+1; m++) {
    if(!isalpha((unsigned char)output[m])) {
      output[m] = ' ';
    }
  }
  
  //Printing the sanitized user input
  printf("Sanitized Output: %s", output);
  
  return 0;
}