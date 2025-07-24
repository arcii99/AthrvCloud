//FormAI DATASET v1.0 Category: Searching algorithm ; Style: funny
#include<stdio.h>

int main() {
  int arr[7] = {9, 13, -1, 0, 7, 8, 10};
  int n = 7, i;
  printf("Let's play a game of hide and seek!\n");
  printf("I have hidden some numbers in an array, and you have to find them using my special searching algorithm.\n");
  
  printf("\nHere's how it works: I'll say a keyword, and you'll give me the corresponding number in the array.\n");
  printf("For example, if I say 'watermelon', you'll tell me the 4th number in the array (because there are 4 syllables in watermelon).\n");

  printf("\nLet's begin!\n");
  char keyword[15]; //maximum keyword length is 15
  int position;
  
  while(1) {
    printf("\nEnter the keyword: ");
    scanf("%s", keyword);
    if(keyword[0] == 'q' && keyword[1] == '\0') { //allow user to quit by entering "q"
      printf("Aww, you're giving up already? The game was just getting started!\n");
      break;
    }
    position = 0;
    for(i = 0; keyword[i] != '\0'; i++) { //get the position in array using length of keyword
      position += keyword[i];
      position %= n;
    }
    if(position < 0) //ensure position is non-negative
      position += n;
    
    printf("The keyword '%s' corresponds to the number %d\n", keyword, arr[position]);
  }
  
  printf("\nThanks for playing, hope you had fun!");
  return 0;
}