//FormAI DATASET v1.0 Category: Funny ; Style: excited
#include <stdio.h>

int main()
{
  printf("Welcome to the world of C programming!\n");
  
  // Exciting variables
  int i_am_really_excited = 1;
  float this_is_amazing = 5.55;
  char oh_my_gosh = 'O';
  
  // Loop of excitement
  while(i_am_really_excited)
  {
    printf("Wooooooohoooo!! This is awesome!!\n");
    printf("I can't believe I'm writing code in C!!\n");
    printf("This language is amazing!!\n");
    
    if(this_is_amazing > 10.0)
    {
      printf("OMG!! This is more amazing than I thought!!\n");
    }
    
    if(oh_my_gosh == 'O')
    {
      printf("Oh my gosh, I'm so excited!!\n");
    }
    
    printf("Are you as excited as I am?? (Y/N)\n");
    char user_input = getchar();
    
    if(user_input == 'N')
    {
      i_am_really_excited = 0;
    }
    
    getchar();  // To clear the \n character from the input buffer
  }
  
  printf("Ok, cool, thanks for playing along! Let's do this again sometime!\n");
  
  return 0;
}