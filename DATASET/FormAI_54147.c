//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: irregular
#include<stdio.h>
#include<string.h>

void checkPalindrome(char str1[]);

int main(){
  char inputString[1000];
     
  printf("Enter the word/phrase you want to check for palindrome: ");
  scanf("%[^\n]", inputString);
  checkPalindrome(inputString);

  return 0;
}

void checkPalindrome(char str1[]){
  int i,j;
  int flag=0;
  int length = strlen(str1);
  
  for(i=0, j=length-1; i <= j; i++, j--){
    if(str1[i]==str1[j]){
      continue;
    } 
    else{
      flag=1;
      break;
    }
  }
  
  if (flag==0){
    printf("\n%s is a Palindrome.\n",str1);
  }
  else{
    printf("\n%s is not a Palindrome.\n",str1);
  }
  return;
}