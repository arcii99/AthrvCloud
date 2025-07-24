//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include<stdio.h>
#include<string.h>

int main() {
  char str[100];
  int option;

  printf("Enter a string: ");
  gets(str);

  printf("\nChoose an option: \n");
  printf("1. Convert to uppercase\n");
  printf("2. Convert to lowercase\n");
  printf("3. Reverse the string\n");
  printf("4. Find the length of the string\n");
  
  printf("\nEnter your option: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      for(int i = 0; str[i]!='\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
          str[i] = str[i] -32;
        }
      }
      printf("\nUppercase string: %s", str);
    break;

    case 2:
      for(int i = 0; str[i]!='\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
          str[i] = str[i] +32;
        }
      }
      printf("\nLowercase string: %s", str);
    break;

    case 3:
      int start = 0;
      int end = strlen(str)-1;
      while (end > start)
      {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
      }
      printf("\nReverse string: %s", str);
    break;

    case 4:
      printf("\nLength of string: %ld", strlen(str));
    break;

    default:
      printf("\nInvalid option!");
    break;
  }

  return 0;
}