//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h> 

int main() 
{ 

int i; 
int j; 
int k=0; 
int num[5]; 
printf("Are you ready for some Arithmetic fun?\n"); 

for(i=0;i<5;i++) 
{ 
    printf("Enter number %d:\n", i+1); 
    scanf("%d",&num[i]); 
} 
for(i=0;i<5;i++) 
{ 
    for(j=0;j<5;j++) 
    { 
        if(num[i]>num[j]) 
        { 
            k=num[i]; 
            num[i]=num[j]; 
            num[j]=k; 
        } 
    } 
}
printf("\nWohoo! Here we go!\n");
printf("\nThe sum of the smallest two numbers=%d",num[4]+num[3]); 
printf("\n"); 
printf("\nThe product of largest two numbers=%d",num[0]*num[1]); 
printf("\n"); 
printf("\nThe difference of the second smallest and second largest numbers=%d",num[3]-num[1]); 
printf("\n"); 
printf("Did you have fun? Come on, let's do it again!"); 

return 0; 
}