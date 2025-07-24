//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
  int i, j, count = 0;
  char text[MAX], input[MAX];
  double seconds = 0.0;
  clock_t start, end;

  printf("Welcome to the Typing Speed Test!\n");
  printf("Type the following paragraph as fast and as accurately as you can:\n\n");

  printf("The quick brown fox jumps over the lazy dog.\n");
  printf("Pack my box with five dozen liquor jugs.\n");
  printf("A quick movement of the enemy will jeopardize six gunboats.\n");
  printf("How vexingly quick daft zebras jump!\n");
  printf("Jackdaws love my big sphinx of quartz.\n\n");

  srand(time(NULL));
  sprintf(text, "The quick brown fox jumps over the lazy dog.\nPack my box with five dozen liquor jugs.\nA quick movement of the enemy will jeopardize six gunboats.\nHow vexingly quick daft zebras jump!\nJackdaws love my big sphinx of quartz.\n");
  
  start = clock();
  
  printf("Type here: ");
  scanf("%[^\n]",input);

  for(i=0,j=0; input[i]!='\0' && text[j]!='\0'; i++,j++)
  {
    if(input[i]!=text[j])
      count++;
  }

  end = clock();
  seconds = (double)(end - start) / CLOCKS_PER_SEC;

  printf("\nResults:\n");
  if(count==0)
    printf("Congratulations! You typed the paragraph perfectly.\n");
  else
    printf("You made %d mistake(s).\n", count);

  printf("Time taken: %.2lf seconds\n", seconds);

  return 0;
}