//FormAI DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>    
#include <stdlib.h>    
#include <time.h>    
  
int main()    
{    
    int i,n;    
    char c;  
    
    do{    
        srand(time(NULL));    
        printf("Enter the number of dices you want to roll:");    
        scanf("%d",&n);    
    
        printf("The result of rolling %d dice(s) is: \n",n);    
        for(i=0;i<n;i++)    
            printf("%d\n",(rand()%6)+1);    
    
        printf("Do you want to roll the dice(s) again? (y/n)\n");    
        scanf(" %c",&c);    
        
    }while(c=='y' || c=='Y');    
        
    return 0;    
}