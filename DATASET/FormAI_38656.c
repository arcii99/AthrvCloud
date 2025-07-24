//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include<stdio.h> 
#include<stdlib.h> 

void tower_of_hanoi(int n, char source, char destination, char auxiliary) 
{ 
    if(n == 1) 
    { 
        printf("\n Move disk 1 from %c to %c", source, destination); 
        return; 
    } 
    
    tower_of_hanoi(n-1, source, auxiliary, destination); 
    
    printf("\n Move disk %d from %c to %c", n, source, destination); 
    
    tower_of_hanoi(n-1, auxiliary, destination, source); 
} 

int main() 
{ 
    int n; 
    
    printf("Enter the number of disks: "); 
    scanf("%d", &n); 
    
    if(n<1) 
    { 
        printf("\n Invalid Input"); 
        return 0; 
    } 
    
    tower_of_hanoi(n, 'A', 'C', 'B'); 
    
    return 0; 
}