//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include<stdio.h>
int main()
{
  printf("\n\n WOAH! Check out this unique pattern printing program! \n\n");
  
  int n,i,j;
  printf("Enter the number of rows you want to print: ");
  scanf("%d",&n);
  
  printf("\n\n BEHOLD! The magical pattern printing would begin!\n\n");
  
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=i;j++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n Did you like it? Want to see more? Well, here's something EXTRA!\n\n");

  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n-i+1;j++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\n There you go! You have now witnessed something truly unique!\n\n");

  return 0;
}