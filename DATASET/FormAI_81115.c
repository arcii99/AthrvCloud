//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include<stdio.h>

void hanoi(int n, char from, char via, char to){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n-1, from, to, via);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n-1, via, from, to);
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Here are the moves to solve the Tower of Hanoi problem with %d disks:\n", n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}