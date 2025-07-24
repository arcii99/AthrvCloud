//FormAI DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include <stdio.h> 

int main() 
{ 
    int i, j, rows; 

    printf("Enter the number of rows: "); 
    scanf("%d",&rows); 

    for(i = 1; i <= rows; i++) 
    { 
        for(j = 1; j <= i; j++) 
        { 
            printf("%d ", j); 
        } 
        printf("\n"); 
    } 

    for(i = rows-1; i >= 1; i--) 
    { 
        for(j = 1; j <= i; j++) 
        {
            printf("%d ", j); 
        } 
        printf("\n"); 
    } 

    return 0; 
}