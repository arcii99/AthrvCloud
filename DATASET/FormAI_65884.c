//FormAI DATASET v1.0 Category: Memory management ; Style: irregular
#include<stdio.h> 

int main() 
{ 

int n,i,j,k; 

printf("Enter the number of lines:"); 

scanf("%d",&n); 

for(i=n;i>=1;i--) 
{ 
    for(j=1;j<=i;j++) 
        printf(" "); 
        
    for(j=i;j<=2*i-1;j++) 
        printf("*"); 
        
    for(j=0;j<i-1;j++) 
        printf("*"); 
        
    printf("\n"); 
} 

for(i=2;i<=n;i++) 
{ 
    for(j=1;j<=i;j++) 
        printf(" "); 
        
    for(j=i;j<=2*i-1;j++) 
        printf("*"); 
        
    for(j=0;j<i-1;j++) 
        printf("*"); 
        
    printf("\n"); 
} 

return 0; 
}