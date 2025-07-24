//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int num_moves;

void toh(int n, char source, char aux, char dest){
    num_moves++;
    if(n == 1){
        printf("Move disk %d from %c to %c\n", n, source, dest);
        return;
    }
    toh(n-1, source, dest, aux);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    toh(n-1, aux, source, dest);
}

int main(){
    int num_disks, i, j, min_moves;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    clock_t t;
    t = clock();
    toh(num_disks, 'A', 'B', 'C');
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken to solve for %d disks: %f seconds\n", num_disks, time_taken);
    min_moves = (1 << num_disks) - 1;
    printf("Minimum number of moves required: %d\n", min_moves);
    printf("Number of moves taken: %d\n", num_moves);
    if(num_moves == min_moves){
        printf("Solution is optimal\n");
    }
    else{
        printf("Solution is not optimal\n");
    }
    return 0;
}