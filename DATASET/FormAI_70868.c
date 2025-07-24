//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include<stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main(){

    int n = 3; //number of disks
    tower_of_hanoi(n, 'A', 'C', 'B'); //Initial call to the tower of hanoi function
    return 0;
}

//recursive function to move disks from one rod to another
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod){

    if(n == 1){

        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}