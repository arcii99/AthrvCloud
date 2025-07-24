//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main()
{
  char input[1000];
  char output[1000];
  int i=0, j=0, count=0;

  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  // Removing special characters and converting to lowercase
  while(input[i]!='\0')
  {
    if(input[i]>='a' && input[i]<='z')
    {
      input[i] = input[i] + 32;
      output[j] = input[i];
      j++;
    }
    else if(input[i]>='A' && input[i]<='Z')
    {
      input[i] = input[i] + 32;
      output[j] = input[i];
      j++;
    }
    else if(input[i]>='0' && input[i]<='9')
    {
      output[j] = input[i];
      j++;
    }
    else
    {
      i++;
      continue;
    }

    i++;
  }
  output[j] = '\0';

  // Counting words
  for(i=0; output[i]!='\0'; i++)
  {
    if(output[i]==' ' || output[i]=='\n' || output[i]=='\t')
    {
      count++;
    }
  }
  count++; // For the last word

  printf("Number of words in the string: %d\n", count);

  return 0;
}