//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include<stdio.h>
#include<string.h>

int main(){
  char word[100];
  int i, j, length, flag;

  printf("Enter a word to check if it is a palindrome: ");
  scanf("%s",word);

  length = strlen(word); //finds length of word

  flag = 0;

  for(i = 0, j = length - 1; i < length/2 ;i++, j--){

      if(word[i] != word[j]){ //checks if letters are equal
          flag = 1;
          break;
      }
  }

  if (flag) {
    printf("%s is not a palindrome\n", word);
  }
  else {
    printf("%s is a palindrome\n", word);
  }

  return 0;
}