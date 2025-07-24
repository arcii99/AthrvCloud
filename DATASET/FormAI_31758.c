//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include<stdio.h>

int main(){
    printf("Welcome to the exciting world of Tower of Hanoi!\n");
    int n = 3; // number of disks
    char from = 'A', to = 'C', aux = 'B'; // pegs
    printf("Initially, the %d disks are stacked on peg %c.\n",n,from);
    towerOfHanoi(n,from,to,aux);
    printf("Wow! The Tower of Hanoi problem has been successfully solved!\n");
    return 0;
}

void towerOfHanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    printf("Move disk %d from peg %c to peg %c\n", n, from, to);
    towerOfHanoi(n-1, aux, to, from);
}