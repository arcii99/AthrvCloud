//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

// Function to move the disks from source to destination
void tower_of_hanoi(int disks, char from_rod, char to_rod, char aux_rod) 
{ 
    if (disks == 1) // Base case when there is only one disk
    { 
        printf("\n\t\t\tHey! I am moving disk 1 from rod %c to rod %c, YAY! :D", from_rod, to_rod); 
        return; 
    } 

    // Recursively moving the disks
    tower_of_hanoi(disks-1, from_rod, aux_rod, to_rod); 
    printf("\n\t\t\tWoohoo! I am moving disk %d from rod %c to rod %c, such a cool move :)", disks, from_rod, to_rod); 
    tower_of_hanoi(disks-1, aux_rod, to_rod, from_rod); 
} 

// Main function to execute the program
int main() 
{ 
    int num_of_disks;

    printf("Hey there, welcome to the Tower of Hanoi!\nLet's see how many disks you want to move around: ");
    scanf("%d", &num_of_disks);

    if(num_of_disks <= 0){
        printf("\nWait, you don't wanna play the game? That's okay, bye :)\n");
        return 0;
    }

    printf("\nOkay, let's start moving these disks around!\n");

    // Initializing the Tower of Hanoi function
    tower_of_hanoi(num_of_disks, 'A', 'C', 'B'); 
  
    printf("\n\nYayy, we moved all the disks successfully! That was so much fun :D\n\n");
    return 0; 
}