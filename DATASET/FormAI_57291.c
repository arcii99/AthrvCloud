//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>

void move(int n, char from_tower, char to_tower, char aux_tower){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", from_tower, to_tower);
        return;
    }
    move(n-1, from_tower, aux_tower, to_tower);
    printf("Move disk %d from %c to %c\n", n, from_tower, to_tower);
    move(n-1, aux_tower, to_tower, from_tower);
}

int main(){
    int num_of_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_of_disks);

    printf("The steps to solve Tower of Hanoi Problem with %d disks are:\n", num_of_disks);
    move(num_of_disks, 'A', 'C', 'B');

    return 0;
}