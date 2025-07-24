//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>

int tower_of_hanoi(int n, char source_rod, char destination_rod, char auxiliary_rod){
    if(n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, destination_rod);
        return 1;
    }

    tower_of_hanoi(n - 1, source_rod, auxiliary_rod, destination_rod);

    printf("Move disk %d from rod %c to rod %c\n", n, source_rod, destination_rod);

    tower_of_hanoi(n - 1, auxiliary_rod, destination_rod, source_rod);

    return 1;
}

int main(){
    int number_of_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &number_of_disks);

    tower_of_hanoi(number_of_disks, 'A', 'C', 'B');

    return 0;
}