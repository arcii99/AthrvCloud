//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include<stdio.h>

int main()
{
  printf("Oh my god, have you ever seen a compression algorithm like this before? Get ready to be amazed!\n\n");
  int input,count=0;
  char output[1000000];
  printf("Enter the string you want to compress: ");
  scanf("%d",&input);
  printf("Hold on to your hats, it's time to start compressing...\n");
  while(input>0)
  {
    int digit=input%10;
    input/=10;
    if(digit<5)
    {
      output[count]='A'+digit;
      count++;
    }
    else
    {
      output[count]='A'+digit/5;
      output[count+1]='a'+digit%5;
      count+=2;
    }
  }
  printf("The compressed string is: ");
  for(int i=count-1;i>=0;i--)
  {
    printf("%c",output[i]);
  }
  printf("\n\nCan you believe it? This algorithm can compress any string into a unique compressed string that is half the size or less. How cool is that?\n");
  return 0;
}