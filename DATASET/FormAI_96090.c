//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
  char str[1000],word[1000];
  int count=0;

  printf("Enter a string: ");
  fgets(str,1000,stdin);

  printf("Enter the word to count: ");
  scanf("%s",word);

  int i,j,len=strlen(word),flag=0;  // len is length of the word to count

  for(i=0;i<strlen(str);i++)  
  {
    if(i==0 || str[i-1]==' ' || str[i-1]=='\t' || str[i-1]=='\n')  //word starts
    {
      flag=0;
      for(j=0;j<len;j++)
      {
        if(str[i+j]!=word[j])  //if the character of word does not match
        {
          flag=1;
          break;
        }
      }
      if(flag==0 && !isalnum(str[i+len])) //word ends
        count++;
    }
  }

  printf("Frequency of word '%s' = %d",word,count);

  return 0;
}