//FormAI DATASET v1.0 Category: String manipulation ; Style: artistic
#include<stdio.h>
#include<string.h>

int main()
{
  char name[100], greeting[100];
  int len;

  printf("Enter your name: ");
  scanf("%s", name);

  len = strlen(name);  

  if(len%2==0){
     sprintf(greeting, "Hello %s, you have an even number of characters in your name!", name);
  } else {
     sprintf(greeting, "Hello %s, you have an odd number of characters in your name!", name);
  }

  int i;
  for (i=0;i<len;i++){
    name[i] = name[i]+(i+1);
  }

  printf("Your name with each letter incremented by its position in the name: %s\n", name);
  printf("Your personalized greeting: %s\n", greeting);

  return 0;
}