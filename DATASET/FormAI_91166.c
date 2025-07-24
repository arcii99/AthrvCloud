//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include<stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if (n == 1){
        printf("\n Move disk 1 from rod %c to rod %c.", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c.", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main(){
    int num_disks;
    printf("\n Enter the number of disks: ");
    scanf("%d", &num_disks);
    printf("\n\n The Solution for Tower of Hanoi problem with %d disks are: \n\n", num_disks);
    towerOfHanoi(num_disks, 'A', 'B', 'C');
    return 0;
}