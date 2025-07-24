//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h> 

void tower_of_hanoi(int n, char source_rod, char auxiliary_rod, char destination_rod) 
{ 
    if(n == 1) 
    { 
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, destination_rod); 
        return; 
    } 
    tower_of_hanoi(n-1, source_rod, destination_rod, auxiliary_rod); 
    printf("Move disk %d from rod %c to rod %c\n", n, source_rod, destination_rod); 
    tower_of_hanoi(n-1, auxiliary_rod, source_rod, destination_rod); 
} 

int main() 
{ 
    int n = 5; 
    tower_of_hanoi(n, 'A', 'B', 'C'); 
    return 0; 
}