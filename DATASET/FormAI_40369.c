//FormAI DATASET v1.0 Category: Pattern printing ; Style: mind-bending
#include <stdio.h> 

int main() 
{ 
    printf("Are you ready to behold the power of C?\n");
    printf("Here's a mind-bending pattern in C\n"); 
    
    for (int i = 0; i < 10; i++){ 
        for (int j = 0; j <= i; j++) { 
            printf(" * "); 
        } 
        printf("\n"); 
    } 
    
    printf("\nThat was just a warm-up!\n"); 
    printf("Now let's see if you can handle this:\n\n"); 
    
    int n = 5;
    int p = n;
    
    for (int i = 0;  i < n; i++) { 
        for (int j = 1; j <= p; j++) { 
            printf(" "); 
        } 
        p--; 
        
        for (int j = 0; j <= i; j++) { 
            printf(" *"); 
        } 
        printf("\n"); 
    } 
    
    printf("\nYour mind bending pattern in C is now complete!\n"); 
    printf("Did you enjoy the power of C? Let me know!\n"); 
    
    return 0; 
}