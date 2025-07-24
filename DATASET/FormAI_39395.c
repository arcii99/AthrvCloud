//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include<stdio.h>
#include<string.h>

int main(){

  char str[100];

  printf("Enter a string: ");
  scanf("%s", str);

  int len = strlen(str);
  int i = 0;
  int j = len-1;

  while(i<j){
    if(str[i] != str[j]){
      printf("\n%s is not a palindrome.\n", str);
      return 0;
    }
    i++;
    j--;
  }

  printf("\n%s is a palindrome!\n", str);

  return 0;
}