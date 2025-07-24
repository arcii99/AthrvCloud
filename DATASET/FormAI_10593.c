//FormAI DATASET v1.0 Category: Random ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
  srand(time(0));
  
  int upper_limit, lower_limit, num_of_elements;
  
  printf("Enter the upper limit of the range: ");
  scanf("%d",&upper_limit);
  
  printf("Enter the lower limit of the range: ");
  scanf("%d",&lower_limit);
  
  printf("Enter the number of elements to generate: ");
  scanf("%d",&num_of_elements);

  printf("\nHere are your randomly generated numbers:\n");
  
  for(int i = 0; i < num_of_elements; i++){
    int num = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    printf("%d\n",num);
  }
  
  printf("\nWow!! You got some energy in this program, let's go for another round. Enter '1' to continue or '0' to exit: ");
  int choice;
  scanf("%d",&choice);
  
  if(choice == 1) main();
  else printf("Thanks for playing! Have a great day!!");
  
  return 0;
}