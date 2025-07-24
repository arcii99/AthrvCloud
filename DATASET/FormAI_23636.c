//FormAI DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include<stdio.h> 

int main() 
{ 
  char message[1000];
  int flag = 0;
  printf("Enter the message:\n");
  scanf("%[^\n]s", message);

  for(int i = 0; message[i] != '\0'; i++) 
  {
    if(message[i] == 'c' && message[i+1] == 'a' && message[i+2] == 's' && message[i+3] == 'h')
    {
        flag = 1;
        break;
    }
  }

  if(flag == 1) 
  {
    printf("SPAM detected.\n");
  }
  else 
  {
    printf("Message seems fine.\n");
  }

  return 0;
}