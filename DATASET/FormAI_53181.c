//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char A, char C, char B){
    if(n==1){
        printf("Move disk 1 from tower %c to tower %c\n", A, C);
        return;
    }
    hanoi(n-1, A, B, C);
    printf("Move disk %d from tower %c to tower %c\n", n, A, C);
    hanoi(n-1, B, C, A);
}

int main(){
    int n;
    printf("Welcome to the Tower of Hanoi!\n\n");
    printf("How many disks do you want to play with? ");
    scanf("%d", &n);
    if(n<=0){
        printf("Invalid input! Enter a positive integer.\n");
        return 0;
    }
    printf("\nHere is a solution:\n");
    hanoi(n, 'A', 'C', 'B');
    return 0;
}