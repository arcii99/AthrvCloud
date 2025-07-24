//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>

void move(int n, char source, char destination, char aux){  
    if (n == 1){  
        printf("Move disc 1 from %c to %c.\n", source, destination);  
        return;  
    }  
    move(n-1, source, aux, destination);  
    printf("Move disc %d from %c to %c.\n", n, source, destination);  
    move(n-1, aux, destination, source);  
}  

int main()  
{  
    int n = 4;   // Number of discs
    printf("======================================\n");
    printf("Welcome to the Tower of Hanoi Problem\n");
    printf("======================================\n\n");
    printf("There are %d discs in total.\n\n", n);  
    move(n, 'A', 'C', 'B');  
    
    printf("\n=================================================\n");
    printf("Thank you for using the Tower of Hanoi Problem code.\n");
    printf("=================================================\n");
    
    return 0;  
}