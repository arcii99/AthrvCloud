//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: medieval
#include<stdio.h>
#include<string.h>

int main()
{
  char string[50],revstr[50];
  int i,j,length,flag=0;

  printf("Greetings! I am the Palindrome checker. Enter a word and I shall determine if it's a Palindrome or not.\n");

  scanf("%s",string);

  length=strlen(string);
  j=length-1;

  for(i=0;i<length;i++)
  {
    revstr[i]=string[j];
    j--;
  }

  for(i=0;i<length;i++)
  {
    if(revstr[i]!=string[i])
      flag=1;
  }

  if(flag==1)
    printf("Alas! %s is not a Palindrome.\n",string);
  else
    printf("Huzzah! %s is indeed a Palindrome.\n",string);

  printf("Fare thee well, until we meet again!\n");

  return 0;
}