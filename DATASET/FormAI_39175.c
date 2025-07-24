//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surrealist
#include<stdio.h>

int main() 
{
    int green=1,red=0,yellow=0;
    while(green)
    {
      printf("The light is green. Go ahead!\n");
      red=1;
      green=0;
      yellow=0;
    }
    while(red)
    {
      printf("The light is red. Stop!\n");
      yellow=1;
      red=0;
      green=0;
    }
    while(yellow)
    {
      printf("The light is yellow. Caution!\n");
      green=1;
      yellow=0;
      red=0;
    }

  return 0;
}