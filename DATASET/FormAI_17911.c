//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to recursively compress a string */
void compress(char *str)
{
  int len = strlen(str);
  if(len == 0) return;
  
  /* Count the number of consecutive characters */
  int i;
  int count = 1;
  for(i = 1; i < len; i++)
  {
    if(str[i] == str[i-1]) count++;
    else break;
  }
  
  /* If there are multiple consecutive characters, compress them */
  if(count > 1)
  {
    char tmp[100];
    sprintf(tmp, "%d%c", count, str[0]);
    memmove(str, str+count, len-count+1);
    memcpy(str, tmp, strlen(tmp));
  }
  
  /* Recurse on the rest of the string */
  compress(str+1);
}

int main()
{
  char str[100];
  printf("Enter a string to compress: ");
  scanf("%99s", str);
  compress(str);
  printf("Compressed string: %s\n", str);
  return 0;
}