//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include<stdio.h> 

void tower_of_hanoi(int num_disks, char source_rod, char auxiliary_rod, char destination_rod) 
{ 
    if (num_disks == 1) 
    { 
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, destination_rod); 
        return; 
    } 
    
    tower_of_hanoi(num_disks-1, source_rod, destination_rod, auxiliary_rod); 
    printf("Move disk %d from rod %c to rod %c\n", num_disks, source_rod, destination_rod); 
    tower_of_hanoi(num_disks-1, auxiliary_rod, source_rod, destination_rod); 
} 

int main() 
{ 
    int num_disks = 4; // Change the number of disks here
    tower_of_hanoi(num_disks, 'A', 'B', 'C'); 
    return 0; 
}